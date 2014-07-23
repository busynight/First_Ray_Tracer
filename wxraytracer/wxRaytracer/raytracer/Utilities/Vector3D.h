#ifndef __VECTOR3D__
#define __VECTOR3D__

#include "Matrix.h"

class Normal;
class Point3D;

class Vector3D{

public:

	//default constructor
	Vector3D(void);

	//other constructors
	Vector3D(double a);
	Vector3D(double nX, double nY, double nZ);
	Vector3D(const Vector3D& v);
	Vector3D(const Normal& n);
	Vector3D(const Point3D& p);

	//destructor
	~Vector3D(void);

	//assignment operator for vectors, normals, and points
	Vector3D& operator= (const Vector3D& rhs);

	Vector3D& operator= (const Normal& rhs);

	Vector3D& operator= (Point3D& rhs);

	//unary minus
	Vector3D operator- (void) const;

	//length
	double length (void); 

	// square of the length
	double len_squared(void);

	//multiply vector with a scalar
	Vector3D operator* (const double a) const;

	//divide vector with a scalar
	Vector3D operator/ (const double a) const;

	//add two vectors together
	Vector3D operator+ (const Vector3D& v) const;

	//compound addition
	Vector3D& operator+= (const Vector3D& v);

	//subtracting a vector
	Vector3D operator- (const Vector3D& v) const;

	// dot product
	double operator* (const Vector3D& b) const ;

	//cross product
	Vector3D operator^ (const Vector3D& v) const; 
	
	//converting a vector to a unity vector
	void normalize(void);

	//return a unit vector, and normalize the vector
	Vector3D& hat(void);

public:

	double x, y, z;
};

//inlined member functions

//changes direction of the vector

inline Vector3D  Vector3D::operator- (void) const{

	return Vector3D(-x,-y,-z);
}

inline double Vector3D::len_squared(void){

	return (x * x + y * y + z * z);
}

inline Vector3D Vector3D::operator*(const double a) const{


	return Vector3D( x * a, y * a, z * a);
}

inline Vector3D Vector3D::operator/ (const double a) const{

	return Vector3D(x / a, y / a, z / a);
}

inline Vector3D Vector3D::operator+ (const Vector3D& v) const {
	return (Vector3D(x + v.x, y + v.y, z + v.z));
}


inline Vector3D Vector3D::operator- (const Vector3D& v) const {
	return (Vector3D(x - v.x, y - v.y, z - v.z));
}

inline double Vector3D::operator* (const Vector3D& v) const {
	return (x * v.x + y * v.y + z * v.z);
} 

inline Vector3D Vector3D::operator^ (const Vector3D& v) const {
	return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}

inline Vector3D& Vector3D::operator+= (const Vector3D& v) {
	x += v.x; y += v.y; z += v.z;
	return (*this);
}

// inlined non-member function

// multiplication by a double on the left

Vector3D operator* (const double a, const Vector3D& v);

inline Vector3D operator* (const double a, const Vector3D& v) {
	return (Vector3D(a * v.x, a * v.y, a * v.z));	
}

// multiplication by a matrix on the left

Vector3D operator* (const Matrix& mat, const Vector3D& v);


#endif 