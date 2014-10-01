#ifndef MATRIX_H
#define MATRIX_H

#pragma once

namespace openMind
{

namespace math
{

template<class T>
class Matrix
{
	public:
		Matrix();
		Matrix(unsigned int rows, unsigned int cols);
		Matrix(const Matrix& m);
		
		~Matrix();
		
		Matrix& operator = (const Matrix& m);
		
		void resize(unsigned int rows, unsigned int cols);
		
		unsigned int getRowCount();
		unsigned int getColCount();
		
		T& get(unsigned int row, unsigned int col);
		T get(unsigned int row, unsigned int col) const;
		
		void set(unsigned int row, unsigned int col, T value);

	private:
		T*				m_matrix;
		unsigned int	m_rows;
		unsigned int	m_cols;
};

}

}

#endif // MATRIX_H
