#include "HopfieldNetwork.h"
#include <openMind/math/BinaryMatrix.h>
#include <openMind/math/BipolarMatrix.h>
#include <openMind/exception/InvalidParameterException.h>


using namespace openMind::math;


namespace openMind
{

namespace neuralnet
{

HopfieldNetwork::HopfieldNetwork()
{
	m_size = 0;
}

HopfieldNetwork::HopfieldNetwork(unsigned int size)
{
	setSize(size);
}

HopfieldNetwork::~HopfieldNetwork()
{
}

unsigned int HopfieldNetwork::getSize() const
{
	return m_size;
}
		
void HopfieldNetwork::setSize(unsigned int size)
{
	m_weights.resize(size, size);
	m_size = size;
}
		
std::vector<bool> HopfieldNetwork::present(const std::vector<bool>& values)
{
	if (m_size == 0 || values.size() != m_size)
	{
		// throw exception because size must match
		std::vector<std::string> args;
		args.push_back(std::to_string(values.size()));
		args.push_back(std::to_string(m_size));
		
		throw openMind::exception::InvalidParameterException("HopfieldNetwork::present", "values", "exception.invalid.parameter.presented.values.size.must.equal.network.size", args);
	}
	
	BinaryMatrix input_matrix = BinaryMatrix::createRowVector(values);
	
	std::vector<bool> output(m_size);
	
	// Process each value in the pattern
	for (int col=0; col<values.size(); col++) 
	{
		Matrix column_matrix = m_weights.getColumn(col);

		// The output for this input element is the dot product of the
		// input matrix and one column from the weight matrix.
		double dot_product = input_matrix.dotProduct(column_matrix);

		// Convert the dot product to either true or false.
		if (dot_product > 0) 
		{
			output[col] = true;
		} 
		else 
		{
			output[col] = false;
		}
	}
	return output;
}	

void HopfieldNetwork::train(const std::vector<bool>& pattern)
{
	if (m_size == 0 || pattern.size() != m_size)
	{
		// throw exception because size must match
		std::vector<std::string> args;
		args.push_back(std::to_string(pattern.size()));
		args.push_back(std::to_string(m_size));
		
		throw openMind::exception::InvalidParameterException("HopfieldNetwork::train", "pattern", "exception.invalid.parameter.pattern.size.must.equal.network.size", args);
	}

	BinaryMatrix input_matrix = BinaryMatrix::createRowVector(pattern);
	BipolarMatrix bipolar_input = input_matrix.toBipolarMatrix();
	Matrix transposed_bipolar_input = bipolar_input.transpose();
	Matrix m = input_matrix * transposed_bipolar_input;
	for (unsigned int i=0; i<m_size; i++)
	{
		m.set(i, i, 0);
	}
	m_weights += m;
}

	
}	// neuralnet

}	// openMind

