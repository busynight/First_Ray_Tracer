#include "Phong.h"

Phong::Phong(void) : Material(), ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian), specular_brdf(new GlossySpecular){}

Phong::Phong(const Phong& p) : Material(p), ambient_brdf(p.ambient_brdf), diffuse_brdf(p.diffuse_brdf), specular_brdf(p.specular_brdf){}

Material* Phong::clone(void) const{

	return new Phong(*this);
}

Phong& Phong::operator=(const Phong& rhs){

	if (this == &rhs)
		return *this;

	ambient_brdf = rhs.ambient_brdf;
	diffuse_brdf = rhs.diffuse_brdf;
	specular_brdf = rhs.specular_brdf;

	return *this;
}

RGBColor Phong::shade(ShadeRec& sr){

	// Chapter 15 pg. 282 eq 15.8

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

			if(!in_shadow){

				L+= (diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi
					+ specular_brdf->f(sr, wo, wi)) * sr.w.lights[j]->L(sr) * ndotwi; 

			}
		}
	}

	return L;
}

Phong::~Phong(void){

	if(ambient_brdf){

		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if(diffuse_brdf){

		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}

	if(specular_brdf){

		delete specular_brdf;
		specular_brdf = NULL;
	}
}
