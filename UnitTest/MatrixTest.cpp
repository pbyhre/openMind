#include <gtest/gtest.h>
#include <openMind/math/Matrix.h>

const unsigned int ROWS = 3;
const unsigned int COLS = 2;

using namespace openMind::math;

class MatrixTest : public ::testing::Test 
{
	protected:
		virtual void SetUp() 
		{
			m_long_matrix = new Matrix<long>(ROWS, COLS);
			for (int i=0; i<ROWS; i++)
			{
				for (int j=0; j<COLS; j++)
				{
					m_long_matrix->set(i, j, i+j);
				}
			}
			
		}

		virtual void TearDown() 
		{
			if (NULL != m_long_matrix)
			{
				delete m_long_matrix;
				m_long_matrix = NULL;
			}
		}

	openMind::math::Matrix<long>*	m_long_matrix;
	//openMind::math::Matrix<double>	m_double_matrix(ROWS,COLS);
};

TEST(MatrixTest, MultiplyLong) 
{
	Matrix<long> m1(3, 2);
	Matrix<long> m2(2, 3);
	Matrix<long> result(3, 3);
	
	m1.set(0, 0, 1);
	m1.set(1, 0, 2);
	m1.set(2, 0, 3);
	m1.set(0, 1, 4);
	m1.set(1, 1, 5);
	m1.set(2, 1, 6);
	
	m2.set(0, 0, 7);
	m2.set(0, 1, 8);
	m2.set(0, 2, 9);
	m2.set(1, 0, 10);
	m2.set(1, 1, 11);
	m2.set(1, 2, 12);
	
	result.set(0, 0, 47);
	result.set(0, 1, 52);
	result.set(0, 2, 57);
	result.set(1, 0, 64);
	result.set(1, 1, 71);
	result.set(1, 2, 78);
	result.set(2, 0, 81);
	result.set(2, 1, 90);
	result.set(2, 2, 99);
	
	m1 *= m2;
	
	EXPECT_EQ(result, m1);
	
}

TEST(MatrixTest, IdentityMatrix) 
{
	Matrix<long> m1 = Matrix<long>::createIdentityMatrix(3);
	
	Matrix<long> result(3, 3);
	
	result.set(0, 0, 47);
	result.set(0, 1, 52);
	result.set(0, 2, 57);
	result.set(1, 0, 64);
	result.set(1, 1, 71);
	result.set(1, 2, 78);
	result.set(2, 0, 81);
	result.set(2, 1, 90);
	result.set(2, 2, 99);
	
	m1 *= result;
	
	EXPECT_EQ(result, m1);
	
}

TEST(MatrixTest, TransposeMatrix) 
{
	Matrix<long> m1(3, 2);
	Matrix<long> m2(2, 3);
	
	m1.set(0, 0, 1);
	m1.set(1, 0, 3);
	m1.set(2, 0, 5);
	m1.set(0, 1, 2);
	m1.set(1, 1, 4);
	m1.set(2, 1, 6);
	
	m2.set(0, 0, 1);
	m2.set(0, 1, 3);
	m2.set(0, 2, 5);
	m2.set(1, 0, 2);
	m2.set(1, 1, 4);
	m2.set(1, 2, 6);
	
	Matrix<long> result = m1.transpose();
	EXPECT_EQ(result, m2);
	
	result = result.transpose();
	EXPECT_EQ(result, m1);
}

TEST(MatrixTest, EmptyConstructorLong) 
{
	openMind::math::Matrix<long> m;
	
	EXPECT_EQ(0, m.getRowCount()) << "Rows should be 0 for empty matrix";
	EXPECT_EQ(0, m.getColCount()) << "Cols should be 0 for empty matrix";
	try
	{
		m.set(0, 0, 10);
		ASSERT_FALSE(true) << "InvalidCellException should have been thrown";
	}
	catch (openMind::exception::InvalidCellException& ex)
	{
		EXPECT_EQ(0, ex.getRow()) << "Row should be 0";
		EXPECT_EQ(0, ex.getCol()) << "Col should be 0";
	}
}

TEST(MatrixTest, 3x2Long) 
{
	openMind::math::Matrix<long> m(3,2);
	
	EXPECT_EQ(3, m.getRowCount()) << "Rows should be 3 for empty matrix";
	EXPECT_EQ(2, m.getColCount()) << "Cols should be 2 for empty matrix";
	try
	{
		for (unsigned int i=0; i<3; i++)
		{
			for (unsigned int j=0; j<2; j++)
			{
				m.set(i, j, (i+j)*7);
			}
		}
		for (unsigned int i=0; i<3; i++)
		{
			for (unsigned int j=0; j<2; j++)
			{
				EXPECT_EQ((i+j)*7, m.get(i, j)) << "Value was wrong for cell in row: " << i << " col: " << j;
			}
		}
		
		// now go outside the bounds
		m.set(4, 4, 10);
		ASSERT_FALSE(true) << "InvalidCellException should have been thrown";
	}
	catch (openMind::exception::InvalidCellException& ex)
	{
		EXPECT_EQ(4, ex.getRow()) << "Row should be 4";
		EXPECT_EQ(4, ex.getCol()) << "Col should be 4";
	}
}

// double
TEST(MatrixTest, EmptyConstructorDouble) 
{
	openMind::math::Matrix<double> m;
	
	EXPECT_EQ(0, m.getRowCount()) << "Rows should be 0 for empty matrix";
	EXPECT_EQ(0, m.getColCount()) << "Cols should be 0 for empty matrix";
	try
	{
		m.set(0, 0, 10);
		ASSERT_FALSE(true) << "InvalidCellException should have been thrown";
	}
	catch (openMind::exception::InvalidCellException& ex)
	{
		EXPECT_EQ(0, ex.getRow()) << "Row should be 0";
		EXPECT_EQ(0, ex.getCol()) << "Col should be 0";
	}
}

TEST(MatrixTest, 3x2Double) 
{
	double multiplier = 2.123456;
	openMind::math::Matrix<double> m(3,2);
	
	EXPECT_EQ(3, m.getRowCount()) << "Rows should be 3 for empty matrix";
	EXPECT_EQ(2, m.getColCount()) << "Cols should be 2 for empty matrix";
	try
	{
		for (unsigned int i=0; i<3; i++)
		{
			for (unsigned int j=0; j<2; j++)
			{
				m.set(i, j, (i+j)*multiplier);
			}
		}
		for (unsigned int i=0; i<3; i++)
		{
			for (unsigned int j=0; j<2; j++)
			{
				EXPECT_EQ((i+j)*multiplier, m.get(i, j)) << "Value was wrong for cell in row: " << i << " col: " << j;
			}
		}
		
		// now go outside the bounds
		m.set(4, 4, 10);
		ASSERT_FALSE(true) << "InvalidCellException should have been thrown";
	}
	catch (openMind::exception::InvalidCellException& ex)
	{
		EXPECT_EQ(4, ex.getRow()) << "Row should be 4";
		EXPECT_EQ(4, ex.getCol()) << "Col should be 4";
	}
}