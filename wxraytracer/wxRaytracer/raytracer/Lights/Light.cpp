#include "Light.h"


Light::Light(void) : shadows(false) {}

Light::Light(const Light& l) : shadows(l.shadows){}

Light& Light::operator=(const Light& rhs){

	if(this == &rhs)
		return *this;

	shadows = rhs.shadows;
	return *this;
}
bool Light::in_shadow(const Ray& ray, const ShadeRec& sr) const{

	return false;
}

float Light::G(const ShadeRec& sr) const{

	return 1.0;
}

float Light::pdf(ShadeRec& sr) const{

	return 1.0;
}

Light::~Light(void){}


