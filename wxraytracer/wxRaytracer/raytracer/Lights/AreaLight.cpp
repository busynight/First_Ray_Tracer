#include "AreaLight.h"


AreaLight::AreaLight(void) : Light(), object_ptr(NULL), material_ptr(NULL){

}

AreaLight::AreaLight(const AreaLight& a): Light(a){

	if(a.object_ptr)
		object_ptr = a.object_ptr->clone();
	else
		object_ptr = NULL;

	if(a.material_ptr)
		material_ptr = a.material_ptr->clone();
	else
		material_ptr = NULL;
}

Light* AreaLight::clone(void) const{

	return new AreaLight(*this);
}

AreaLight& AreaLight::operator=(const AreaLight& rhs){

	if(this == &rhs)
		return *this;

	Light::operator=(rhs);

	if(object_ptr){
		delete object_ptr;
		object_ptr = NULL;
	}

	if(rhs.object_ptr)
		object_ptr = rhs.object_ptr->clone();

	if(material_ptr){
		delete material_ptr;
		material_ptr = NULL;
	}

	if(rhs.material_ptr)
		material_ptr = rhs.material_ptr->clone();

	sample_point = rhs.sample_point;
	light_normal = rhs.light_normal;
	wi = rhs.wi;

	return *this;
}

Vector3D AreaLight::get_direction(ShadeRec& sr){
	
	sample_point = object_ptr->sample();
	light_normal = object_ptr->get_normal(sample_point);
	wi = sample_point -  sr.hit_point;
	wi.normalize();

	return wi;
}

bool AreaLight::in_shadow(const Ray& ray, const ShadeRec& sr) const{

	double t;

	int num_objects = sr.w.objects.size();
	float ts = (sample_point - ray.o) * ray.d;

	for(int j = 0; j <num_objects ; ++j){

		if(sr.w.objects[j]->shadow_hit(ray, t) && t < ts){
		
			return true;
		}
	}

	return false;
}

RGBColor AreaLight::L(ShadeRec& sr){
	float ndotd = -light_normal * wi;

	if(ndotd > 0.0)
		return material_ptr->get_Le(sr);
	else
		return black;
}

float AreaLight::G(const ShadeRec& sr) const{

	float ndotd = -light_normal * wi;
	float d2 = sample_point.d_squared(sr.hit_point);

	return ndotd / d2;

}

float AreaLight::pdf(ShadeRec& sr) const{

	return object_ptr->pdf(sr);
}




AreaLight::~AreaLight(void){

	if(object_ptr){
		delete object_ptr;
		object_ptr = NULL;
	}

	if(material_ptr)
		delete material_ptr;
		material_ptr = NULL;
}
