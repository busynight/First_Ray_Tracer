#include "BBox.h"
#include "Constants.h"

BBox::BBox(void) : x0(0.0), y0(0.0), z0(0.0), x1(1.0), y1(1.0), z1(1.0){}

BBox::BBox(const BBox& b) : x0(b.x0), y0(b.y0), z0(b.z0), x1(b.x1), y1(b.y1), z1(b.z1) {}

BBox::BBox(const Point3D& p0, const Point3D& p1) : 
	x0(p0.x), y0(p0.y), z0(p0.z),
	x1(p1.x), y1(p1.y), z1(p1.z){}

BBox& BBox::operator=(const BBox& rhs){

	if(this == &rhs)
		return *this;

	x0 = rhs.x0;
	y0 = rhs.y0;
	z0 = rhs.z0;
	x1 = rhs.x1;
	y1 = rhs.y1;
	z1 = rhs.z1;

	return *this;
}

bool BBox::hit(const Ray& ray) const{

	double ox = ray.o.x; double oy = ray.o.y; double oz = ray.o.z;
	double dx = ray.d.x; double dy = ray.d.y; double dz = ray.d.z;

	double tx_min, ty_min, tz_min;
	double tx_max, ty_max, tz_max;

	double a = 1.0 / dx;

	if ( a >= 0 ) {

		tx_min = (x0 - ox) * a;
		tx_max = (x1 - ox) * a;
	}
	else{
		tx_min = (x1 - ox) * a;
		tx_max = (x0 - ox) * a;
	}
	
	double b = 1.0 / dy;

	if ( b >= 0 ) {

		ty_min = (y0 - oy) * b;
		ty_max = (y1 - oy) * b;
	}
	else{
		ty_min = (y1 - oy) * b;
		ty_max = (y0 - oy) * b;
	}

	double c = 1.0 / dz;

	if ( c >= 0 ) {

		tz_min = (z0 - oz) * c;
		tz_max = (z1 - oz) * c;
	}
	else{
		tz_min = (z1 - oz) * c;
		tz_max = (z0 - oz) * c;
	}


	double t0, t1;

	// find largest entering t value

	if( tx_min > ty_min)
		t0 = tx_min;
	else
		t0 = ty_min;
	if(tz_min > t0)
		t0 = tz_min;

	// find the smallest exiting t value

	if( tx_max < ty_max)
		t1 = tx_max;
	else
		t1 = ty_max;

	if(tz_max < t1)
		t1 = tz_max;

	return (t0 < t1 && t1 > kEpsilon);
}


bool BBox::inside(const Point3D& p) const{

	return (  (p.x > x0 && p.x < x1) &&
			  (p.y > y0 && p.y < y1) &&
			  (p.z > z0 && p.z < z1) ) ;

}


BBox::~BBox(void)
{
}
