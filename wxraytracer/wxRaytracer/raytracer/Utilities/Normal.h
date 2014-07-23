#ifndef __NORMAL__
#define __NORMAL__

#include "Matrix.h"
#include "Vector3D.h"
#include "Point3D.h"



class Normal
{
public:
	
	//default constructor
	Normal(void);

	//copy constructor
	Normal(const Normal& n);


	//destructor
	~Normal(void);

	//overload constructors
	Normal(double a);
	Normal(double a, double b, double c);
	Normal(const Vector3D& v);

	//assignment operators
	Normal& operator= (const Normal& rhs);
	Normal& operator= (const Vector3D& rhs);
	Normal& operator= (const Point3D& rhs);

	Normal operator- (void) const;

	Normal operator+ (const Normal& n) const;

	Normal& operator+= (const Normal& n);

	double operator* (const Vector3D& v) const;

	Normal operator* (const double a) const;

	void normalize (void);

public:

	double x, y, z;
};

inline Normal Normal::operator- (void) const{

	return Normal(-x,-y,-z);
}

inline Normal Normal::operator+ (const Normal& n) const {

	return Normal(x + n.x, y + n.y, z + n.z);
}

inline Normal& Normal::operator+= (const Normal& n){

	x += n.x;
	y += n.y;
	z += n.z;
	return *this;
}

inline double Normal::operator* (const Vector3D& v) const{

	return (x * v.x + y * v.y + z * v.z);
}

inline Normal Normal::operator* (const double a) const {

	return (Normal(x * a, y * a, z * a));
}

// inlined non-member functions

Normal operator* (const double a, const Normal& n);

inline Normal operator*(const double f, const Normal& n) {
	return (Normal(f * n.x, f * n.y,f * n.z));
}

// addition of a vector on the left to return a vector 

Vector3D operator+ (const Vector3D& v, const Normal& n);

inline Vector3D operator+ (const Vector3D& v, const Normal& n) {	
	return (Vector3D(v.x + n.x, v.y + n.y, v.z + n.z));
}	  
// subtraction of a normal from a vector to return a vector

Vector3D operator- (const Vector3D&, const Normal& n);

inline Vector3D operator- (const Vector3D& v, const Normal& n) {
	return (Vector3D(v.x - n.x, v.y - n.y, v.z - n.z));
}

// dot product of a vector on the left and a normal on the right

double operator* (const Vector3D& v, const Normal& n);

inline double operator* (const Vector3D& v, const Normal& n) {
	return (v.x * n.x + v.y * n.y + v.z * n.z);     
}

// non-inlined non-member function
// multiplication by a matrix on the left

Normal operator* (const Matrix& mat, const Normal& n);


#endif