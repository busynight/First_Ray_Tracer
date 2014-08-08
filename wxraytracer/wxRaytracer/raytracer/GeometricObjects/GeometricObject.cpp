#include "GeometricObject.h"


GeometricObject::GeometricObject(void) : color(black) {}

GeometricObject::GeometricObject(const GeometricObject& object) : color(object.color) {}

GeometricObject& GeometricObject::operator= (const GeometricObject& rhs) {

	if(this == &rhs)
		return *this;

	color = rhs.color;

	return *this;
}

Material* GeometricObject::get_material(void) const{
	return material_ptr;
}

void GeometricObject::set_material(Material* m){

	material_ptr = m;
}

GeometricObject::~GeometricObject(void){}
