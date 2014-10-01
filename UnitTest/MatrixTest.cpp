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

TEST_F(MatrixTest, IsEmptyInitially) 
{
	for (int i=0; i<ROWS; i++)
	{
		for (int j=0; j<COLS; j++)
		{
			EXPECT_EQ(i+j, m_long_matrix->get(i, j));
		}
	}
}
