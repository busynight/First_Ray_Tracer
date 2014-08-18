#include "Material.h"
#include "Constants.h"

Material::Material(void) {}

Material::Material(const Material& m) {}

Material& Material::operator=(const Material& rhs){

	if(this == &rhs)
		return *this;

	return *this;
}

RGBColor Material::shade(ShadeRec& sr){

	return black;
}

RGBColor Material::area_light_shade(ShadeRec& sr){

	return black;
}

RGBColor Material::path_shade(ShadeRec& sr){

	return black;
}

RGBColor Material::get_Le(ShadeRec& sr) const{

	return black;
}

Material::~Material(void){}
