#include "AmbientOccluder.h"
#include "World.h"

AmbientOccluder::AmbientOccluder(void) : Light(), u(1.0,0.0,0.0), v(0.0,1.0,0.0), w(0.0,0.0,1.0), sampler_ptr(NULL), min_amount(0.0), ls(1.0), color(white){ }

AmbientOccluder::AmbientOccluder(const AmbientOccluder& a) : Light(a), ls(a.ls), color(a.color),
							u(a.u), v(a.v), w(a.w), sampler_ptr(a.sampler_ptr), min_amount(a.min_amount){ }

Light* AmbientOccluder::clone(void) const{

	return new AmbientOccluder(*this);
}

AmbientOccluder& AmbientOccluder::operator= (const AmbientOccluder& rhs){

	if(this == &rhs)
		return *this;

	Light::operator=(rhs);

	u = rhs.u;
	v = rhs.v;
	w = rhs.w;
	color = rhs.color;
	ls = rhs.ls;
	sampler_ptr = rhs.sampler_ptr;
	min_amount = rhs.min_amount;

	return *this;

}

Vector3D AmbientOccluder::get_direction(ShadeRec& sr){

	Point3D sp = sampler_ptr->sample_hemisphere();

	return (sp.x * u + sp.y * v + sp.z * w);
}

RGBColor AmbientOccluder::L(ShadeRec& sr){

	w = sr.normal;

	// jitter up vector in case normal is vertical;
	v = w ^ Vector3D(0.0072, 1.0 , 0.0034);
	v.normalize();

	u = v ^ w;

	Ray shadow_ray;
	shadow_ray.o = sr.hit_an_object;
	shadow_ray.d = get_direction(sr);

	if( in_shadow(shadow_ray, sr))
		return min_amount * ls * color;
	else
		return ls * color;

}

bool AmbientOccluder::in_shadow(const Ray& ray, const ShadeRec& sr) const{
	
	double t;
	int num_objects = sr.w.objects.size();

	for (int i = 0; i < num_objects; ++i){

		if(sr.w.objects[i]->shadow_hit(ray, t))
			return true;

	}
	return false;
}

void AmbientOccluder::set_sampler(Sampler* s_ptr){

	if(sampler_ptr){
		
		delete sampler_ptr;
		sampler_ptr = NULL;

	}

	sampler_ptr = s_ptr;
	sampler_ptr->map_samples_to_hemisphere(1);
}

AmbientOccluder::~AmbientOccluder(void)
{
	if(sampler_ptr){
		
		delete sampler_ptr;
		sampler_ptr = NULL;

	}
}
