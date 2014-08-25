#include "Triangle.h"


Triangle::Triangle(void) : GeometricObject(), 
	v0(0.0,0.0,0.0), v1(0.0,0.0,1.0), v2(1.0,0.0,0.0), 
	normal(0.0,1.0,0.0){}

Triangle::Triangle(const Point3D& p0, const Point3D& p1, const Point3D& p2) : GeometricObject(), v0(p0), v1(p1), v2(p2) {

	normal = (v1 - v0) ^ (v2 - v0);	// computer normal
	normal.normalize(); 
}

Triangle::Triangle(const Triangle& t) : GeometricObject(t), v0(t.v0), v1(t.v1), v2(t.v2), normal(t.normal){}

GeometricObject* Triangle::clone(void) const {

	return new Triangle(*this);
}

Triangle& Triangle::operator=(const Triangle& rhs){

	if(this == &rhs)
		return *this;

	GeometricObject::operator=(rhs);
	
	v0 = rhs.v0;
	v1 = rhs.v1;
	v2 = rhs.v2;
	normal = rhs.normal;

	return *this;

}

bool Triangle::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{

	// Page 366 with math involved
	double a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
	double e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.x - ray.o.y;
	double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.x - ray.o.z;

	double m = f * k - g * j,
		   n = h * k - g * l,
		   p = f * l - h * j,
		   q = g * i - e * k, 
		   s = e * j - f * i;

	double inv_determ = 1.0 / ( a* m + b * q + c * s);

	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_determ;

	if( beta <0.0)
		return false;

	double r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_determ;

	if (gamma < 0.0)
		return false;

	if ( gamma + beta > 1.0)
		return false;

	double e3 = a * p - b * r + d * s;
	double t = e3 * inv_determ;

	if (t < kEpsilon)
		return false;

	tmin = t;
	sr.normal = normal;
	sr.local_hit_point = ray.o + t * ray.d;

	return true;

	return false;
}

bool Triangle::shadow_hit(const Ray& ray, double& tmin) const{

	if(!shadows)
		return false;

		// Page 366 with math involved
	double a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
	double e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.x - ray.o.y;
	double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.x - ray.o.z;

	double m = f * k - g * j,
		   n = h * k - g * l,
		   p = f * l - h * j,
		   q = g * i - e * k, 
		   s = e * j - f * i;

	double inv_determ = 1.0 / ( a* m + b * q + c * s);

	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_determ;

	if( beta <0.0)
		return false;

	double r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_determ;

	if (gamma < 0.0)
		return false;

	if ( gamma + beta > 1.0)
		return false;

	double e3 = a * p - b * r + d * s;
	double t = e3 * inv_determ;

	if (t < kEpsilon)
		return false;

	tmin = t;

	return true;
}


Triangle::~Triangle(void){}
