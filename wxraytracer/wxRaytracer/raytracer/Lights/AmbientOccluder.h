#ifndef __AMBIENTOCCLUDER__
#define __AMBIENTOCCLUDER__

#include "Light.h"
#include "Sampler.h"

class AmbientOccluder : public Light
{
public:
	AmbientOccluder(void);

	AmbientOccluder(const AmbientOccluder& l);

	virtual Light* clone(void) const;

	AmbientOccluder& operator=(const AmbientOccluder& rhs);
	
	virtual Vector3D get_direction(ShadeRec& sr);

	virtual RGBColor L(ShadeRec& sr);

	virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

	virtual ~AmbientOccluder(void);

	void set_sampler(Sampler *s_ptr);

	void scale_radiance(const float b);

	void set_color(const float c);

	void set_color(const float r, const float g, const float b);

	void set_color(const RGBColor& c);

	void set_min_amount(const float c);

	void set_min_amount(const RGBColor& c);


private:

	Vector3D u, v, w;
	Sampler* sampler_ptr;
	float ls;
	RGBColor color;
	RGBColor min_amount;

};

inline void AmbientOccluder::scale_radiance(const float b){

	ls = b;
}

inline void AmbientOccluder::set_color(const float c){

	color.r = c; color.g = c; color.b = c;
}

inline void  AmbientOccluder::set_color(const float r, const float g, const float b){

	color.r = r; color.g = g; color.b = b;
}

inline void  AmbientOccluder::set_color(const RGBColor& c){

	color.r = c.r; color.g = c.g; color.b = c.b;
}

inline void  AmbientOccluder::set_min_amount(const float c){

	min_amount.r = c; min_amount.b = c; min_amount.g = c;
}

inline void  AmbientOccluder::set_min_amount(const RGBColor& c){

	min_amount.r = c.r; min_amount.b = c.b; min_amount.g = c.g;
}


#endif