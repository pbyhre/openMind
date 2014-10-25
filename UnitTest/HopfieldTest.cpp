#include <gtest/gtest.h>
#include <openMind/math/BipolarMatrix.h>
#include <openMind/math/BinaryMatrix.h>


using namespace openMind::math;


TEST(HopfieldTest, CreateContribution) 
{
	BinaryMatrix input(4, 1);
	BipolarMatrix expect_bipolar (4, 1);
	BipolarMatrix expect_transpose (1, 4);
	Matrix expect_mult(4, 4);
	
	
	input.set(0, 0, 0);
	input.set(1, 0, 1);
	input.set(2, 0, 0);
	input.set(3, 0, 1);
	
	expect_bipolar.set(0, 0, -1);
	expect_bipolar.set(1, 0, 1);
	expect_bipolar.set(2, 0, -1);
	expect_bipolar.set(3, 0, 1);
	
	expect_transpose.set(0, 0, -1);
	expect_transpose.set(0, 1, 1);
	expect_transpose.set(0, 2, -1);
	expect_transpose.set(0, 3, 1);
	
	BipolarMatrix bp = input.toBipolarMatrix();
	
	EXPECT_EQ(bp, expect_bipolar);
	
	Matrix bp_transpose = bp.transpose();
	
	EXPECT_EQ(bp_transpose, expect_transpose);
	
	expect_mult.set(0, 0, 1);
	expect_mult.set(0, 1, -1);
	expect_mult.set(0, 2, 1);
	expect_mult.set(0, 3, -1);
	expect_mult.set(1, 0, -1);
	expect_mult.set(1, 1, 1);
	expect_mult.set(1, 2, -1);
	expect_mult.set(1, 3, 1);
	expect_mult.set(2, 0, 1);
	expect_mult.set(2, 1, -1);
	expect_mult.set(2, 2, 1);
	expect_mult.set(2, 3, -1);
	expect_mult.set(3, 0, -1);
	expect_mult.set(3, 1, 1);
	expect_mult.set(3, 2, -1);
	expect_mult.set(3, 3, 1);
	
	Matrix mult = bp * bp_transpose;
	
	EXPECT_EQ(mult, expect_mult);
	
}
