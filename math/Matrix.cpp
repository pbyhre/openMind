#include <openMind/math/Matrix.h>
#include <openMind/exception/InvalidCellException.h>
#include <openMind/exception/IncompatableMatrixException.h>
#include <algorithm>
#include <math.h>

namespace openMind
{

namespace math
{

Matrix::Matrix()
{
	m_matrix = NULL;
	m_rows = 0;
	m_cols = 0;
}

Matrix::Matrix(unsigned int rows, unsigned int cols)
{
	m_matrix = NULL;
	m_rows = 0;
	m_cols = 0;
	
	resize(rows, cols);
}

Matrix::Matrix(const Matrix& m)
{
	m_matrix = NULL;
	m_rows = 0;
	m_cols = 0;
	
	resize(m.m_rows, m.m_cols);
	memcpy(m_matrix, m.m_matrix, sizeof(double)*m.m_rows*m.m_cols);
}

Matrix::~Matrix()
{
	if (NULL != m_matrix)
	{
		delete [] m_matrix;
		m_matrix = NULL;
	}
	m_rows = 0;
	m_cols = 0;
}

bool Matrix::isVector() const
{
	if (m_rows > 0 && m_cols > 0)
	{
		return (m_rows == 1 || m_cols == 1);	// either rows or cols must be 1
	}
	return false;
}

double Matrix::dotProduct(const Matrix& value) const
{
	// both matricies must be vectors
	std::vector<double> v1 = toVector();
	std::vector<double> v2 = value.toVector();
	
	if (v1.size() != v2.size())
	{
		throw openMind::exception::IncompatableMatrixException();
	}
	
	double result = 0.0;
	for (int i=0; i<v1.size(); i++)
	{
		result += v1.at(i) * v2.at(i);
	}
	
	return result;
}

std::vector<double> Matrix::toVector() const
{
	if (isVector() == false)
	{
		throw openMind::exception::IncompatableMatrixException();
	}
	
	std:: vector<double> vec;
	if (m_rows == 1)
	{
		for (int i=0; i<m_cols; i++)
		{
			vec.push_back(get(0, i));
		}
	}
	else
	{
		for (int i=0; i<m_cols; i++)
		{
			vec.push_back(get(i, 0));
		}
	}
	return vec;
}

unsigned int Matrix::vectorLength() const
{
	if (isVector() == false)
	{
		throw openMind::exception::IncompatableMatrixException();
	}
	
	double sum = 0.0;
	if (m_rows == 1)
	{
		for (unsigned int i=0; i<m_cols; i++)
		{
			sum += pow(get(0, i), 2);
		}
	}
	else
	{
		for (unsigned int i=0; i<m_cols; i++)
		{
			sum += pow(get(i, 0), 2);
		}
	}
	return sqrt(sum);
}

bool Matrix::operator == (const Matrix& m) const 
{
	if (this != &m)
	{
		if (m.getRowCount() != m_rows || m.getColCount() != m_cols)
		{
			return false;
		}
		
		for (unsigned int i=0; i<m_rows; i++)
		{
			for (unsigned int j=0; j<m_cols; j++)
			{
				if (get(i, j) != m.get(i, j))
				{
					return false;
				}
			}
		}
	}
	return true;
}

Matrix& Matrix::operator = (const Matrix& m)
{
	if (this != &m)
	{
		if (m.getRowCount() != m_rows || m.getColCount() != m_cols)
		{
			resize(m.getRowCount(), m.getColCount());
		}
		memcpy(m_matrix, m.m_matrix, sizeof(double)*m.m_rows*m.m_cols);
	}
	return *this;
}

Matrix& Matrix::operator += (double value)
{
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			set(i, j, get(i, j) + value);
		}
	}
	return *this;
}

Matrix& Matrix::operator += (const Matrix& value)
{
	if (m_rows != value.getRowCount() || m_cols != value.getColCount())
	{
		throw openMind::exception::IncompatableMatrixException();
	}
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			set(i, j, get(i, j) + value.get(i, j));
		}
	}
	return *this;
}

Matrix& Matrix::operator -= (double value)
{
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			set(i, j, get(i, j) - value);
		}
	}
	return *this;
}

Matrix& Matrix::operator -= (const Matrix& value)
{
	if (m_rows != value.getRowCount() || m_cols != value.getColCount())
	{
		throw openMind::exception::IncompatableMatrixException();
	}
	
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			set(i, j, get(i, j) - value.get(i, j));
		}
	}
	return *this;
}

Matrix& Matrix::operator *= (double value)
{
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			set(i, j, get(i, j) * value);
		}
	}
	return *this;
}

Matrix& Matrix::operator *= (const Matrix& value)
{
	// row count must equal column count of the multiplied matrix and column count
	// must equal the row count of the multiplied matrix
	if (m_rows != value.getColCount() || m_cols != value.getRowCount())
	{
		throw openMind::exception::IncompatableMatrixException();
	}
	
	unsigned int size = value.getColCount();	// new matrix will be square
	Matrix new_matrix(size, size);
	
	for (unsigned int i=0; i<size; i++)
	{
		for (unsigned int j=0; j<size; j++)
		{
			double cell_value = 0;
			for (unsigned int x=0; x<m_cols; x++)
			{
				cell_value += get(i, x) * value.get(x, j);
			}
			
			new_matrix.set(i, j, cell_value);
		}
	}
	*this = new_matrix;
	return *this;
}

Matrix& Matrix::operator /= (double value)
{
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			set(i, j, get(i, j) / value);
		}
	}
	return *this;
} 

Matrix Matrix::operator + (const Matrix& value)
{
	Matrix result = *this;      // Make a copy of myself.  Same as MyClass result(*this);
	result += value;            // Use += to add other to the copy.
	return result;              // All done!
}

Matrix Matrix::operator * (double value)
{
	Matrix result = *this;      // Make a copy of myself.  Same as MyClass result(*this);
	result *= value;            // Use += to add other to the copy.
	return result;              // All done!
}

Matrix Matrix::operator * (const Matrix& value)
{
	Matrix result = *this;      // Make a copy of myself.  Same as MyClass result(*this);
	result *= value;            // Use += to add other to the copy.
	return result;              // All done!
}

Matrix Matrix::operator / (double value)
{
	Matrix result = *this;      // Make a copy of myself.  Same as MyClass result(*this);
	result /= value;            // Use += to add other to the copy.
	return result;              // All done!
}

void Matrix::resize(unsigned int rows, unsigned int cols)
{
	if (NULL != m_matrix)
	{
		delete m_matrix;
		m_matrix = NULL;
	}
	
	m_matrix = new double[rows*cols];
	memset(m_matrix, 0, sizeof(double)*rows*cols);
	
	m_rows = rows;
	m_cols = cols;
}

Matrix Matrix::transpose() const
{
	Matrix new_matrix(m_cols, m_rows);		// switch the rows and columns
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			new_matrix.set(j, i, get(i, j));
		}
	}
	return new_matrix;
}

Matrix Matrix::getColumn(unsigned int col) const
{
	if (col >= m_cols)
	{
		throw openMind::exception::InvalidCellException(0, col);
	}
	Matrix m(m_rows, 1);
	for (unsigned int i=0; i<m_rows; i++)
	{
		m.set(i, 0, get(i, col));
	}
	return m;
}

Matrix Matrix::getRow(unsigned int row) const
{
	if (row >= m_rows)
	{
		throw openMind::exception::InvalidCellException(row, 0);
	}
	Matrix m(1, m_cols);
	for (unsigned int i=0; i<m_cols; i++)
	{
		m.set(0, i, get(row, i));
	}
	return m;
}

unsigned int Matrix::getRowCount() const 
{
	return m_rows;
}

unsigned int Matrix::getColCount() const 
{
	return m_cols;
}

double& Matrix::get(unsigned int row, unsigned int col)
{
	if (row >= m_rows || col >= m_cols)
	{
		throw openMind::exception::InvalidCellException(row, col);
	}
	return m_matrix[m_cols*row + col];
}

double Matrix::get(unsigned int row, unsigned int col) const
{
	if (row >= m_rows || col >= m_cols)
	{
		throw openMind::exception::InvalidCellException(row, col);
	}
	return m_matrix[m_cols*row + col];
}

void Matrix::set(unsigned int row, unsigned int col, double value)
{
	if (row >= m_rows || col >= m_cols)
	{
		throw openMind::exception::InvalidCellException(row, col);
	}
	m_matrix[m_cols*row + col] = value;
}

void Matrix::clear()
{
	memset(m_matrix, 0, sizeof(double)*m_rows*m_cols);
}

bool Matrix::isZero()
{
	for (unsigned int i=0; i<m_rows; i++)
	{
		for (unsigned int j=0; j<m_cols; j++)
		{
			if (get(i, j) != 0)
			{
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix::createIdentityMatrix(unsigned int size)
{
	Matrix new_matrix(size, size);
	for (unsigned int i=0; i<size; i++)
	{
		new_matrix.set(i, i, 1);
	}
	return new_matrix;
}

Matrix Matrix::createColumnVector(unsigned int size)
{
	return Matrix(size, 1);
}

Matrix Matrix::createRowVector(unsigned int size)
{
	return Matrix(1, size);
}

		
		
	
	
}
}
