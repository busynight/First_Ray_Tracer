#include "Disk.h"

Disk::Disk(void) : GeometricObject(), center(0.0), radius(1.0), normal(0.0,1.0,0.0),sampler_ptr(NULL), area(2*PI),inv_area(1/area) {}

Disk::Disk(const Point3D& c, const float r, const Normal n) : GeometricObject(),
	center(c), radius(r), area(2*PI*r), inv_area(1/area), normal(n),sampler_ptr(NULL) {

		normal.normalize();
}

Disk::Disk(const Disk& d) : GeometricObject(d) , center(d.center), radius(d.radius), normal(d.normal), area(d.area), inv_area(d.inv_area) {

	if(d.sampler_ptr)
		sampler_ptr = d.sampler_ptr->clone();
	else
		sampler_ptr = NULL;

}

GeometricObject* Disk::clone(void) const{

	return new Disk(*this);
}

Disk& Disk::operator=(const Disk& rhs){

	if(this == &rhs)
		return *this;

	GeometricObject::operator=(rhs);

	center = rhs.center;
	radius = rhs.radius;
	area = rhs.area;
	inv_area = rhs.area;
	normal = rhs.normal;

	return *this;
}

bool Disk::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{

	float t = (center - ray.o) * normal / (ray.d * normal);

	if( t <= kEpsilon)
		return false;

	Point3D p = ray.o + t *ray.d;
	
	if(center.d_squared(p) < radius*radius){
		tmin = t;
		sr.normal = normal;
		sr.local_hit_point = p;
		return true;
	}
	else
		return false;
}

Normal Disk::get_normal(const Point3D& p){
	return normal;
}

Point3D Disk::sample(void){

	//TODO: Come up with a new asmpleing technique for the disk using area light
	//	Point2D sample_point = sampler_ptr->sample_unit_square();
	return Point3D();//pO + sample_point.x * a + sample_point.y * b;

}

float Disk::pdf(ShadeRec& sr){
	return inv_area;
}

void Disk::set_sampler(Sampler* sampler){
	sampler_ptr = sampler;
}


bool Disk::shadow_hit(const Ray& ray, double& tmin) const{
	if(!shadows)
		return false;


	float t = (center - ray.o) * normal / (ray.d * normal);

	if( t <= kEpsilon)
		return false;

	Point3D p = ray.o + t *ray.d;
	
	if(center.d_squared(p) < radius*radius){
		tmin = t;
		return true;
	}
	else
		return false;
}

Disk::~Disk(void){}
