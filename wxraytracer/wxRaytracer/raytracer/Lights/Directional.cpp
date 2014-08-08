#include "Directional.h"


Directional::Directional(void) : Light(), ls(1.0), color(1.0) , direction(0.0, 1.0, 0.0) {}

Directional::Directional(const Directional& d) : Light(d), ls(d.ls), color(d.color), direction(d.direction) {}

Directional* Directional::clone(void) const{

	return new Directional(*this);
}

Directional& Directional::operator= (const Directional& rhs){

	if(this == &rhs)
		return *this;

	color = rhs.color;
	ls = rhs.ls;
	direction = rhs.direction;

	return *this;
}

Directional::~Directional(void){}

Vector3D Directional::get_direction(ShadeRec& sr){

	return direction;
}

RGBColor Directional::L(ShadeRec& sr){
	return (ls * color);
}