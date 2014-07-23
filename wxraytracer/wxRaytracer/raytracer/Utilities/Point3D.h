#ifndef __POINT3D__
#define __POINT3D__

// This file contains the declaration of the class Point3D

#include "Matrix.h"
#include "Vector3D.h"

class Point3D {
	public:
		// default constructor
		Point3D();		

		//other constructors
		Point3D(const double a);								
		Point3D(const double a, const double b, const double c);	
		Point3D(const Point3D& p);									

		// destructor
		~Point3D();

		// assignment operator
		Point3D& operator= (const Point3D& p);

		// unary minus
		Point3D operator- (void) const;

		// vector joining two points
		Vector3D operator- (const Point3D& p) const;


		// addition of a vector
		Point3D operator+ (const Vector3D& v) const;

		// subtraction of a vector
		Point3D operator- (const Vector3D& v) const;

		// multiplication by a double on the right
		Point3D operator* (const double a) const;

		// square of distance bertween two points
		double d_squared(const Point3D& p) const;

		// distance bewteen two points
		double distance(const Point3D& p) const;



public:	
		double x, y, z;
};



// inlined member functions


inline Point3D Point3D::operator- (void) const {
	return (Point3D(-x, -y, -z));
}

// the vector that joins two points

inline Vector3D Point3D::operator- (const Point3D& p) const {
	return (Vector3D(x - p.x,y - p.y,z - p.z));
}

// addition of a vector to a point that returns a new point

inline Point3D Point3D::operator+ (const Vector3D& v) const {
	return (Point3D(x + v.x, y + v.y, z + v.z));
}

// subtraction of a vector from a point that returns a new point

inline Point3D Point3D::operator- (const Vector3D& v) const {
	return (Point3D(x - v.x, y - v.y, z - v.z));
}

// mutliplication by a double on the right

inline Point3D Point3D::operator* (const double a) const {
	return (Point3D(x * a,y * a,z * a));
}

// the square of the distance between the two points as a member function

inline double Point3D::d_squared(const Point3D& p) const {
	return (	(x - p.x) * (x - p.x) 
			+ 	(y - p.y) * (y - p.y)
			+	(z - p.z) * (z - p.z) );
}

// inlined non-member function

// multiplication by a double on the left

Point3D operator* (double a, const Point3D& p);

inline Point3D operator* (double a, const Point3D& p) {
	return (Point3D(a * p.x, a * p.y, a * p.z));
}

// multiplication by a matrix on the left

Point3D operator* (const Matrix& mat, const Point3D& p);

#endif
