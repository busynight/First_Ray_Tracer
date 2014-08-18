#include "Emissive.h"


Emissive::Emissive(void) : Material() {}

Emissive::Emissive(const Emissive& e) : Material(e) , ls(e.ls), ce(e.ce) {}

Material* Emissive::clone(void) const{

	return new Emissive(*this);
}

Emissive& Emissive::operator=(const Emissive& rhs){

	if(this == &rhs)
		return *this;

	ls = rhs.ls;
	ce = rhs.ce;

	return *this;
}

RGBColor Emissive::get_Le(ShadeRec& sr) const{

	return ls * ce;
}

RGBColor Emissive::area_light_shade(ShadeRec& sr){

	if(-sr.normal * sr.ray.d > 0.0)
		return ls * ce;
	else
		return black;
}

RGBColor  Emissive::shade(ShadeRec& sr){

	if(-sr.normal * sr.ray.d > 0.0)
		return ls * ce;
	else
		return black;
}


Emissive::~Emissive(void){}
