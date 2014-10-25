#ifndef BINARY_MATRIX_H
#define BINARY_MATRIX_H

#include <openMind/math/Matrix.h>


namespace openMind
{

namespace math
{

class BipolarMatrix;

class BinaryMatrix : public Matrix
{
	public:
		BinaryMatrix();
		
		BinaryMatrix(unsigned int rows, unsigned int cols);
		
		BinaryMatrix(const BinaryMatrix& m);
		
		virtual void set(unsigned int row, unsigned int col, double value);

		BipolarMatrix toBipolarMatrix() const;
		
		static BinaryMatrix createColumnVector(const std::vector<bool>& values);
		
		static BinaryMatrix createRowVector(const std::vector<bool>& values);
};



}

}

#endif // BINARY_MATRIX_H