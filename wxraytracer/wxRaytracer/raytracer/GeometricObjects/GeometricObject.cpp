#include "GeometricObject.h"


GeometricObject::GeometricObject(void) : material_ptr(NULL), shadows(true) {}

GeometricObject::GeometricObject(const GeometricObject& object) : material_ptr(object.material_ptr), shadows(object.shadows) {}

GeometricObject& GeometricObject::operator= (const GeometricObject& rhs) {

	if(this == &rhs)
		return *this;

	material_ptr = rhs.material_ptr;

	return *this;
}

Material* GeometricObject::get_material(void) const{
	return material_ptr;
}

void GeometricObject::set_material(Material* m){

	material_ptr = m;
}

GeometricObject::~GeometricObject(void){

	if(material_ptr){

		delete material_ptr;
		material_ptr = NULL;
	}
}
