#include "PointLight.h"
#include "World.h"

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

bool PointLight::in_shadow(const Ray& ray, const ShadeRec& sr) const{

	float t;
	int num_objects = sr.w.objects.size();
	float d = location.distance(ray.o);

	for(int j = 0; j < num_objects; j++){

		if(sr.w.objects[j]->shadow_hit(ray, t) && t < d)
			return true;
	}
	return false;
}

Vector3D PointLight::get_direction(ShadeRec& sr){

	return (location - sr.local_hit_point).hat();
}

RGBColor PointLight::L(ShadeRec& sr){
	return (ls * color);
}

PointLight::~PointLight(void){}
