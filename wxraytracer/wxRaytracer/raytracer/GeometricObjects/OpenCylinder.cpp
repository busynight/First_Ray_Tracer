#include "OpenCylinder.h"
#include "Math.h"

OpenCylinder::OpenCylinder(void) : GeometricObject(), y0(-1.0), y1(1.0), radius(1.0){}

OpenCylinder::OpenCylinder(const OpenCylinder& oc) : GeometricObject(oc), y0(oc.y0), y1(oc.y1), radius(oc.radius) {}

OpenCylinder::OpenCylinder(const float p0, const float p1, const float r) : GeometricObject(), y0(p0), y1(p1), radius(r) {}

GeometricObject* OpenCylinder::clone(void) const{

	return new OpenCylinder(*this);
}

OpenCylinder& OpenCylinder::operator=(const OpenCylinder& rhs){

	if(this == &rhs)
		return *this;

	GeometricObject::operator=(rhs);

	y0 = rhs.y0;
	y1 = rhs.y1;
	radius = rhs.radius;

	return *this;


}

bool OpenCylinder::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{



	double a = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
	double b = 2.0 * (ray.o.x * ray.d.x + ray.o.x * ray.d.z);
	double c = (ray.o.x * ray.o.x) + (ray.o.z * ray.o.z) - (radius * radius);
	double disc = b * b - 4.0 * a * c;

	if (disc < 0.0)
		return false;

	else{

		double e = sqrt(disc);
		double denom = 2.0 * a;
		double t = (-b - e) / denom; // smaller root

		double px = ray.o.x + t * ray.d.x;
		double py = ray.o.y + t * ray.d.y;
		double pz = ray.o.z + t * ray.d.z;

		if(py > y1 || py < y0)
			return false;


		if (t > kEpsilon){

			tmin = t;

			sr.normal =  Normal(px / radius, 0.0, pz / radius);
			sr.local_hit_point = ray.o + t * ray.d;

			return true;
		}

		t = (-b + e) / denom; // larger root

		px = ray.o.x + t * ray.d.x;
		py = ray.o.y + t * ray.d.y;
		pz = ray.o.z + t * ray.d.z;

		if(py > y1 || py < y0)
			return false;

		if (t > kEpsilon){
			tmin = t;

			sr.normal =  Normal(px / radius, 0.0, pz / radius);
			sr.local_hit_point = ray.o + t * ray.d;

			return true;

		}

	}

	return false;
}

bool OpenCylinder::shadow_hit(const Ray& ray, double& tmin) const{

	if(!shadows)
		return false;


	double a = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
	double b = 2.0 * (ray.o.x * ray.d.x + ray.o.x * ray.d.z);
	double c = (ray.o.x * ray.o.x) + (ray.o.z * ray.o.z) - (radius * radius);
	double disc = b * b - 4.0 * a * c;

	if (disc < 0.0)
		return false;

	else{

		double e = sqrt(disc);
		double denom = 2.0 * a;
		double t = (-b - e) / denom; // smaller root

		double px = ray.o.x + t * ray.d.x;
		double py = ray.o.y + t * ray.d.y;
		double pz = ray.o.z + t * ray.d.z;

		if(py > y1 || py < y0)
			return false;


		if (t > kEpsilon){

			tmin = t;
			return true;
		}

		t = (-b + e) / denom; // larger root

		px = ray.o.x + t * ray.d.x;
		py = ray.o.y + t * ray.d.y;
		pz = ray.o.z + t * ray.d.z;

		if(py > y1 || py < y0)
			return false;

		if (t > kEpsilon){
			tmin = t;
			return true;

		}

	}

	return false;
}

OpenCylinder::~OpenCylinder(void)
{
}
