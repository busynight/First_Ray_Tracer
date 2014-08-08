#include "PerfectSpecular.h"


PerfectSpecular::PerfectSpecular(void) : BRDF(), kr(1.0), cr(1.0) {}

PerfectSpecular::PerfectSpecular(const PerfectSpecular& p) : BRDF(p), kr(p.kr), cr(p.cr) {}



PerfectSpecular& PerfectSpecular::operator=( const PerfectSpecular& rhs){

	if(this == &rhs)
		*this;

	BRDF::operator=(rhs);

	kr = rhs.kr;
	cr = rhs.cr;

	return *this;

}

RGBColor PerfectSpecular::f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const {

	return black;
}

RGBColor PerfectSpecular::sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const{

	// More details in chapter 24
	return black;
}

RGBColor PerfectSpecular::rho(const ShadeRec& sr, const Vector3D& wo) const{

	return black;
}

BRDF* PerfectSpecular::clone(void) const{

	return new PerfectSpecular(*this);
}

PerfectSpecular::~PerfectSpecular(void){}
