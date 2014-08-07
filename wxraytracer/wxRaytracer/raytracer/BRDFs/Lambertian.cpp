#include "Lambertian.h"


Lambertian::Lambertian(void) : BRDF() , kd (0.0), cd(0.0) {}

Lambertian::Lambertian(const Lambertian& l) : BRDF(l), kd(l.kd), cd(l.cd)  {}

Lambertian* Lambertian::clone(void) const{

	return new Lambertian(*this);
}

Lambertian& Lambertian::operator=(const Lambertian& rhs){

	if( this == &rhs)

		return *this;

	kd = rhs.kd;
	cd = rhs.cd;

	return *this;

}

RGBColor Lambertian::f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const{
	// invPI = 1 / PI
	return kd * cd * invPI;
}

RGBColor Lambertian::sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const{

	return black;
}

RGBColor Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const {

	return kd * cd;
}

Lambertian::~Lambertian(void){}
