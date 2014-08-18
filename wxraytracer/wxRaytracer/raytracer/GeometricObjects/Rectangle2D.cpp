#include "Rectangle2D.h"


Rectangle2D::Rectangle2D(void)
	: GeometricObject(), pO(-1.0, 0.0, -1.0), a(0.0,0.0,2.0), b( 2.0, 0.0, 0.0), 
	normal(0.0,1.0,0.0), sampler_ptr(NULL),
	a_len_squared(4.0), b_len_squared(4.0), area(4.0),inv_area(0.25) {}

Rectangle2D::Rectangle2D(const Point3D& p, const Vector3D& new_a, const Vector3D& new_b)
	: GeometricObject(), pO(p), a(new_a), b(new_b), 
	sampler_ptr(NULL),
	a_len_squared(a.len_squared()), b_len_squared(b.len_squared()), area(a.length()*b.length()), inv_area(1.0 / area) {

	normal = a ^ b;
	normal.normalize();
}

Rectangle2D::Rectangle2D(const Point3D& p, const Vector3D& new_a, const Vector3D& new_b, const Vector3D& n)
	: GeometricObject(), pO(p), a(new_a), b(new_b), 
	sampler_ptr(NULL), normal(n),
	a_len_squared(a.len_squared()), b_len_squared(b.len_squared()), area(a.length()*b.length()) , inv_area(1.0/area)
{
	normal.normalize();
}

Rectangle2D::Rectangle2D(const Rectangle2D& r) : GeometricObject(r), 
	pO(r.pO), a(r.a), b(r.b), 
	sampler_ptr(r.sampler_ptr), normal(r.normal),
	a_len_squared(r.a_len_squared), b_len_squared(r.b_len_squared), area(r.area),inv_area(r.inv_area)

{}


GeometricObject* Rectangle2D::clone(void) const{

	return new Rectangle2D(*this);
}

Rectangle2D& Rectangle2D::operator=(const Rectangle2D& rhs){

	if(this == &rhs)
		return *this;

	GeometricObject::operator=(rhs);

	pO = rhs.pO;
	a = rhs.a;
	b = rhs.b;
	normal = rhs.normal;
	inv_area = rhs.inv_area;
	area = rhs.area;
	a_len_squared = rhs.a_len_squared;
	b_len_squared = rhs.b_len_squared;

	if (sampler_ptr){
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if(rhs.sampler_ptr)
		sampler_ptr = rhs.sampler_ptr->clone();

	return *this;
}

Point3D Rectangle2D::sample(void){

	Point2D sample_point = sampler_ptr->sample_unit_square();
	return pO + sample_point.x * a + sample_point.y * b;

}

float Rectangle2D::pdf(ShadeRec& sr){
	return inv_area;
}

Normal Rectangle2D::get_normal(const Point3D& p){
	return normal;
}



void Rectangle2D::set_sampler(Sampler* sampler){
	sampler_ptr = sampler;
}

bool Rectangle2D::hit(const Ray& ray, double& tmin, ShadeRec& sr) const{

	float t = (pO - ray.o) * normal / (ray.d * normal);

	if( t <= kEpsilon)
		return false;

	Point3D p = ray.o + t *ray.d;
	Vector3D d = p - pO;

	float ddota = d * a;

	if(ddota < 0.0 || ddota > a_len_squared)
		return false;

	float ddotb = d * b;

	if(ddotb < 0.0 || ddotb > b_len_squared)
		return false;

	tmin = t;
	sr.normal = normal;
	sr.local_hit_point = p;

	return true;

}

bool Rectangle2D::shadow_hit(const Ray& ray, double& tmin) const{

	if(!shadows)
		return false;

	float t = (pO - ray.o) * normal / (ray.d * normal);

	if( t <= kEpsilon)
		return false;

	Point3D p = ray.o + t *ray.d;
	Vector3D d = p - pO;

	float ddota = d * a;

	if(ddota < 0.0 || ddota > a_len_squared)
		return false;

	float ddotb = d * b;

	if(ddotb < 0.0 || ddotb > b_len_squared)
		return false;

	tmin = t;
	return true;

}

Rectangle2D::~Rectangle2D(void){

	if(sampler_ptr){

		delete sampler_ptr;
		sampler_ptr = NULL;
	}

}
