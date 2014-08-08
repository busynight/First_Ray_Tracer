#include "Plane.h"

const double Plane::kEpsilon = 0.001;

Plane::Plane(void) : GeometricObject(), a(0.0), n(0.0, 1.0, 0.0) {}

Plane::Plane(const Point3D& point, const Normal& normal) : GeometricObject(), a(point), n(normal) {}

Plane::Plane(const Plane& plane): GeometricObject(plane), a(plane.a), n(plane.n) {}

Plane* Plane::clone(void) const{

	return new Plane(*this);

}

Plane& Plane::operator= (const Plane& rhs){

	if(this == &rhs)
		return *this;

	GeometricObject::operator= (rhs);

	a = rhs.a;
	n = rhs.n;

	return *this;

}

Plane::~Plane(void){}

bool Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{

	float t = (a - ray.o) * n / (ray.d * n);

	if (t > kEpsilon){

		tmin = t;
		sr.normal = n;
		sr.local_hit_point = ray.o + t * ray.d; 
		//^^point of where the ray hit where the equation is p = o + t*d

		return true;
	}

	return false;
}

bool Plane::shadow_hit(const Ray& ray, float& tmin) const{

	if( !shadows)
		return false;

	float t = (a - ray.o) * n / (ray.d * n);

	if (t > kEpsilon){

		tmin = t;
		return true;
	}

	return false;
}