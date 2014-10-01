#include <openMind/core.h>
#include <openMind/math/Matrix.h>


namespace openMind
{

namespace math
{
	
template<class T>
Matrix<T>::Matrix()
{
	m_matrix = NULL;
	m_rows = 0;
	m_cols = 0;
}

template<class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	resize(rows, cols);
} 

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	resize(m.m_rows, m.m_cols);
	memcpy(m_matrix, m.m_matrix, sizeof(T)*m.m_rows*m.m_cols);
} 

template<class T>
Matrix<T>::~Matrix()
{
	if (NULL != m_matrix)
	{
		delete [] m_matrix;
		m_matrix = NULL;
	}
	m_rows = 0;
	m_cols = 0;
}

template<class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& m)
{
	if (this != &m)
	{
		if (m.getRowCount() != m_rows || m.getColCount() != m_cols)
		{
			resize(m.getRowCount(), m.getColCount());
		}
		memcpy(m_matrix, m.m_matrix, sizeof(T)*m.m_rows*m.m_cols);
	}
	return *this;
}

template<class T>
void Matrix<T>::resize(unsigned int rows, unsigned int cols)
{
	if (NULL != m_matrix)
	{
		delete m_matrix;
		m_matrix = NULL;
	}
	
	m_matrix = new T[rows*cols];
	memset(m_matrix, 0, sizeof(T)*rows*cols);
	
	m_rows = rows;
	m_cols = cols;
}

template<class T>
unsigned int Matrix<T>::getRowCount()
{
	return m_rows;
}

template<class T>
unsigned int Matrix<T>::getColCount()
{
	return m_cols;
}

template<class T>
T& Matrix<T>::get(unsigned int row, unsigned int col)
{
	if (row >= m_rows || col >= m_cols)
	{
		
	}
	return m_matrix[m_cols*row + col];
}
	
template<class T>	
T Matrix<T>::get(unsigned int row, unsigned int col) const
{
	if (row >= m_rows || col >= m_cols)
	{
		
	}
	return m_matrix[m_cols*row + col];
}
		

template<class T>
void Matrix<T>::set(unsigned int row, unsigned int col, T value)
{
	if (row >= m_rows || col >= m_cols)
	{
		
	}
	m_matrix[m_cols*row + col] = value;
}

}	// namespace math
}	// namespace openMind

