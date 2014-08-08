#include "Light.h"


Light::Light(void) : shadows(false) {}

Light::Light(const Light& l) : shadows(l.shadows){}

Light& Light::operator=(const Light& rhs){

	if(this == &rhs)
		return *this;

	shadows = rhs.shadows;
	return *this;
}
 
Light::~Light(void){}


