#include "Matte.h"


Matte::Matte(void) : Material() , ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian) {}

Matte::Matte(const Matte& m) : Material(m), ambient_brdf(m.ambient_brdf), diffuse_brdf(m.diffuse_brdf) {}

Material* Matte::clone(void) const{

	return new Matte(*this);
}

Matte& Matte::operator=(const Matte& rhs){

	if(this == &rhs)
		return *this;


	ambient_brdf = rhs.ambient_brdf;
	diffuse_brdf = rhs.diffuse_brdf;
	
	return *this;
}

RGBColor Matte::shade(ShadeRec& sr){
	Vector3D	wo = -sr.ray.d;
	RGBColor	L  = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
	int			numLights = sr.w.lights.size();

	for( int j = 0; j < numLights; j++){

		Vector3D wi = sr.w.lights[j]->get_direction(sr);
		float ndotwi = sr.normal * wi;

		if (ndotwi > 0.0){

			bool in_shadow = false;

			if (sr.w.lights[j]->casts_shadows()){

				Ray shadowRay(sr.hit_point, wi);
				in_shadow = sr.w.lights[j]->in_shadow(shadowRay, sr);
			}

			if(!in_shadow)
				L+= diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi;

		}
	}


	return L;
}



Matte::~Matte(void)
{
	if(ambient_brdf){

		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if(diffuse_brdf){

		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}

}
