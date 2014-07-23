#include "Matrix.h"


//default matrix is the identity matrix
Matrix::Matrix(void){

	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++)

			//if the row and column is the same, 
			//set it equal to 1
			//else make it 0
			(i == j)? 1: 0;

}


Matrix::Matrix(const Matrix& mat){

	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++)
			m[i][j] = mat.m[i][j];


}

Matrix& Matrix::operator= (const Matrix& rhs){

	if(this == &rhs)

		return *this;


	for (unsigned int i = 0; i < 4; i++)		
		for (unsigned int j = 0; j < 4; j++)
			m[i][j] = rhs.m[i][j];

	return *this;
}

Matrix Matrix::operator* (const Matrix& mat) const{

	Matrix result;

	//for each column
	for (int c = 0; c < 4; ++c){
		// for each row
		for(int r = 0; r < 4; ++r){

			double sum = 0.0;
			
			//for each column of current matrix 
			//and for each row in other matrix
			for(int j = 0; j < 4; j++){

				sum += m[r][j] * mat.m[j][c];
			}
			result.m[r][c] = sum;
		}
	}
	
	return result;
	
}

Matrix Matrix::operator/(const double d){

	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++)
			m[i][j] /= d;

	return *this;
}


void Matrix::set_identity(void){

	for (unsigned int i = 0; i < 4; i++)
		for (unsigned int j = 0; j < 4; j++)

			//if the row and column is the same, 
			//set it equal to 1
			//else make it 0
			(i == j)? 1: 0;

}

Matrix::~Matrix(void){}
