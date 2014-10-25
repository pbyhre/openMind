#ifndef BIPOLAR_MATRIX_H
#define BIPOLAR_MATRIX_H

#include <openMind/math/Matrix.h>


namespace openMind
{

namespace math
{

class BinaryMatrix;

	
class BipolarMatrix : public Matrix
{
	public:
		BipolarMatrix();
		
		BipolarMatrix(unsigned int rows, unsigned int cols);
		
		BipolarMatrix(const BipolarMatrix& m);
		
		virtual void set(unsigned int row, unsigned int col, double value);

		BinaryMatrix toBinaryMatrix() const;
};



}

}

#endif // BIPOLAR_MATRIX_H