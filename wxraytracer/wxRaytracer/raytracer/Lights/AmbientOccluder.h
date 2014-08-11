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



#endif