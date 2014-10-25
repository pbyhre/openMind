#include <openMind/math/BinaryMatrix.h>
#include <openMind/math/BipolarMatrix.h>
#include <openMind/exception/InvalidValueException.h>

const std::string INVALID_BINARY_MATRIX_CELL_VALUE_EXCEPTION = "exception.invalid.binary.matrix.cell.value";

namespace openMind
{

namespace math
{
	
BinaryMatrix::BinaryMatrix()
:Matrix()
{
}

BinaryMatrix::BinaryMatrix(unsigned int rows, unsigned int cols)
:Matrix(rows, cols)
{
}

BinaryMatrix::BinaryMatrix(const BinaryMatrix& m)
:Matrix(m)
{
}


		
void BinaryMatrix::set(unsigned int row, unsigned int col, double value)
{
	if (value != 0 && value != 1)
	{
		openMind::exception::InvalidValueException<long> ex(value);
		ex.setCode(INVALID_BINARY_MATRIX_CELL_VALUE_EXCEPTION);
		throw ex;
	}
	Matrix::set(row, col, value);
}

BipolarMatrix BinaryMatrix::toBipolarMatrix() const
{
	unsigned int rows = getRowCount();
	unsigned int cols = getColCount();
	BipolarMatrix bipolar(rows, cols);
	
	for (unsigned int i=0; i<rows; i++)
	{
		for (unsigned int j=0; j<cols; j++)
		{
			double value = get(i, j);
			if (value == 0)
			{
				value = -1;
			}
			bipolar.set(i, j, value);
		}
	}
	return bipolar;
}

BinaryMatrix BinaryMatrix::createColumnVector(const std::vector<bool>& values)
{
	BinaryMatrix mat(values.size(), 1);
	
	for (unsigned int i=0; i<values.size(); i++)
	{
		mat.set(i, 0, values[i] ? 1 : 0);
	}
	return mat;
}

BinaryMatrix BinaryMatrix::createRowVector(const std::vector<bool>& values)
{
	BinaryMatrix mat(1, values.size());
	
	for (unsigned int i=0; i<values.size(); i++)
	{
		mat.set(0, i, values[i] ? 1 : 0);
	}
	return mat;
}

}

}