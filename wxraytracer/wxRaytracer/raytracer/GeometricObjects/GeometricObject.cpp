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

Point3D GeometricObject::sample(void){
	return Point3D(0.0);
}

float GeometricObject::pdf(ShadeRec& sr){
	return 0.0;
}

Normal GeometricObject::get_normal(const Point3D& p){

	return Normal();	
}

GeometricObject::~GeometricObject(void){

	if(material_ptr){

		delete material_ptr;
		material_ptr = NULL;
	}
}
