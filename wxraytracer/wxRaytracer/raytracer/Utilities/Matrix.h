#ifndef __MATRIX__
#define __MATRIX__

// this file contains the declaration of the class Matrix
// Matrix is a 4 x 4 square matrix that is used to represent affine transformations
// we don't need a general m x n matrix

//----------------------------------------- class Matrix

class Matrix
{
public:

	//default constructor
	Matrix(void);

	//copy constructor
	Matrix(const Matrix& mat); 

	//destructor
	~Matrix(void);

	//assignment operator
	Matrix& operator = (const Matrix& rightSided);

	//multiplication of two matrices
	Matrix operator* (const Matrix& mat) const;

	//division by a scalar
	Matrix operator/ (const double d);

	//set matrix to an identity matrix
	void set_identity(void);

	//elements within matrix
	double m[4][4];
};

#endif