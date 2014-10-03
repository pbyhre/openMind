#ifndef MATRIX_H
#define MATRIX_H

#pragma once

#include <openMind/exception/InvalidCellException.h>

namespace openMind
{

namespace math
{

template<class T>
class Matrix
{
	public:
		Matrix()
		{
			m_matrix = NULL;
			m_rows = 0;
			m_cols = 0;
		}
		
		Matrix(unsigned int rows, unsigned int cols)
		{
			m_matrix = NULL;
			m_rows = 0;
			m_cols = 0;
			
			resize(rows, cols);
		}
		
		Matrix(const Matrix& m)
		{
			m_matrix = NULL;
			m_rows = 0;
			m_cols = 0;
			
			resize(m.m_rows, m.m_cols);
			memcpy(m_matrix, m.m_matrix, sizeof(T)*m.m_rows*m.m_cols);
		}
		
		~Matrix()
		{
			if (NULL != m_matrix)
			{
				delete [] m_matrix;
				m_matrix = NULL;
			}
			m_rows = 0;
			m_cols = 0;
		}
		
		Matrix& operator = (const Matrix& m)
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
		
		void resize(unsigned int rows, unsigned int cols)
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
		
		unsigned int getRowCount()
		{
			return m_rows;
		}
		
		unsigned int getColCount()
		{
			return m_cols;
		}
		
		T& get(unsigned int row, unsigned int col)
		{
			if (row >= m_rows || col >= m_cols)
			{
				throw openMind::exception::InvalidCellException(row, col);
			}
			return m_matrix[m_cols*row + col];
		}
		
		T get(unsigned int row, unsigned int col) const
		{
			if (row >= m_rows || col >= m_cols)
			{
				throw openMind::exception::InvalidCellException(row, col);
			}
			return m_matrix[m_cols*row + col];
		}
		
		void set(unsigned int row, unsigned int col, T value)
		{
			if (row >= m_rows || col >= m_cols)
			{
				throw openMind::exception::InvalidCellException(row, col);
			}
			m_matrix[m_cols*row + col] = value;
		}

	private:
		T*				m_matrix;
		unsigned int	m_rows;
		unsigned int	m_cols;
};

}

}

#endif // MATRIX_H
