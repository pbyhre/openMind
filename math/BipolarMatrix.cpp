#include <openMind/math/BipolarMatrix.h>
#include <openMind/math/BinaryMatrix.h>
#include <openMind/exception/InvalidValueException.h>


const std::string INVALID_BIPOLAR_MATRIX_CELL_VALUE_EXCEPTION = "exception.invalid.bipolar.matrix.cell.value";


namespace openMind
{

namespace math
{
	
BipolarMatrix::BipolarMatrix()
:Matrix()
{
}

BipolarMatrix::BipolarMatrix(unsigned int rows, unsigned int cols)
:Matrix(rows, cols)
{
}

BipolarMatrix::BipolarMatrix(const BipolarMatrix& m)
:Matrix(m)
{
}

void BipolarMatrix::set(unsigned int row, unsigned int col, double value)
{
	if (value != -1 && value != 1)
	{
		openMind::exception::InvalidValueException<long> ex(value);
		ex.setCode(INVALID_BIPOLAR_MATRIX_CELL_VALUE_EXCEPTION);
		throw ex;
	}
	Matrix::set(row, col, value);
}

BinaryMatrix BipolarMatrix::toBinaryMatrix() const
{
	unsigned int rows = getRowCount();
	unsigned int cols = getColCount();
	BinaryMatrix bipolar(rows, cols);
	
	for (unsigned int i=0; i<rows; i++)
	{
		for (unsigned int j=0; j<cols; j++)
		{
			double value = get(i, j);
			if (value == -1)
			{
				value = 0;
			}
			bipolar.set(i, j, value);
		}
	}
	return bipolar;
}

}

}