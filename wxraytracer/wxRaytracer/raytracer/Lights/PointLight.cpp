#include "PointLight.h"


PointLight::PointLight(void) : Light(), ls(1.0), color(1.0), location(0.0) {}

PointLight::PointLight(const PointLight& p) : Light() , ls(p.ls), color(p.ls), location(p.ls) {}

Light* PointLight::clone(void) const {
	return new PointLight(*this);
}

PointLight& PointLight::operator=(const PointLight& rhs){

	if(this == &rhs)
		return *this;

	ls		= rhs.ls;
	color	= rhs.color;
	location = rhs.location;

	return *this;

}

Vector3D PointLight::get_direction(ShadeRec& sr){

	return (location - sr.local_hit_point).hat();
}

RGBColor PointLight::L(ShadeRec& sr){
	return (ls * color);
}

PointLight::~PointLight(void){}
