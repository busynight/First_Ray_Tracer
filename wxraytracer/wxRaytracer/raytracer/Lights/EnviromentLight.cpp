#include "EnviromentLight.h"


EnviromentLight::EnviromentLight(void) : Light(), sampler_ptr(NULL), material_ptr(NULL), u(1.0,0.0,0.0), v(0.0,1.0,0.0), w(0.0,0.0,1.0),
	wi(0.0) {}

EnviromentLight::EnviromentLight(const EnviromentLight& e) : Light(e), u(e.u), v(e.v), w(e.w), wi(e.wi){

	if(e.sampler_ptr)
		sampler_ptr = e.sampler_ptr->clone();
	else
		sampler_ptr = NULL;

	if(e.material_ptr)
		material_ptr = e.material_ptr->clone();
	else
		material_ptr = NULL;
}

Light* EnviromentLight::clone(void) const{

	return new EnviromentLight(*this);
}

EnviromentLight& EnviromentLight::operator=(const EnviromentLight& rhs){

	if(this == &rhs)
		return *this;

	Light::operator=(rhs);

	if(rhs.sampler_ptr)
		sampler_ptr = rhs.sampler_ptr->clone();
	else
		sampler_ptr = NULL;

	if(rhs.material_ptr)
		material_ptr = rhs.material_ptr->clone();
	else
		material_ptr = NULL;

	u = rhs.u;
	v = rhs.v;
	w = rhs.w;
	wi = rhs.wi;

	return *this;

}

void EnviromentLight::set_sampler(Sampler* sampler){

	if(sampler_ptr){
		delete sampler_ptr;
		sampler_ptr =NULL;
	}
	sampler_ptr = sampler->clone();
	sampler_ptr->map_samples_to_hemisphere(1);
}

void EnviromentLight::set_material(Material* material){

	if(material_ptr){
		delete material_ptr;
		sampler_ptr = NULL;
	}

	if(material){
		material_ptr = material->clone();
	}

}

Vector3D EnviromentLight::get_direction(ShadeRec& sr){

	w = sr.normal;
	v = Vector3D(0.0034, 1.0, 0.0071) ^ w;
	v.normalize();

	u = v ^ w;

	Point3D sp = sampler_ptr->sample_hemisphere();
	wi = sp.x * u + sp.y * v + sp.z * w;

	return wi;

}

RGBColor EnviromentLight::L(ShadeRec& sr){
	return material_ptr->get_Le(sr);
}

bool EnviromentLight::in_shadow(const Ray& ray, const ShadeRec& sr) const{

	double t;
	int num_objects = sr.w.objects.size();

	for (int i = 0; i < num_objects; ++i){

		if(sr.w.objects[i]->shadow_hit(ray, t))
			return true;

	}
	return false;
}

float EnviromentLight::pdf(ShadeRec& sr) const{

	float ndotwi = sr.normal * wi;

	return ndotwi * invPI;

}

EnviromentLight::~EnviromentLight(void)
{
	if(sampler_ptr){
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if(material_ptr){
		delete material_ptr;
		material_ptr = NULL;
	}
}


