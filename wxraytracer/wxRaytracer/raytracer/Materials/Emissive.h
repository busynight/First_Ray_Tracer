#ifndef __EMISSIVE__
#define __EMISSIVE__

#include "Material.h"

class Emissive : public Material {
public:
	Emissive(void);

	Emissive(const Emissive& e);

	virtual Material* clone(void) const;

	Emissive& operator=(const Emissive& e);

	void scale_radiance(const float l);

	void set_ce(const float r, const float g, const float b);

	void set_ce(const RGBColor& c);

	void set_ce(const float c);

	virtual RGBColor get_Le(ShadeRec& sr) const;

	virtual RGBColor shade(ShadeRec& sr);

	virtual RGBColor area_light_shade(ShadeRec& sr);

	virtual ~Emissive(void);

private:

	float ls;		// radiance scaling factor
	RGBColor ce;	// color
};

inline void Emissive::scale_radiance(const float l){

	ls = l;
}

inline void Emissive::set_ce(const float r, const float g, const float b){

	ce.r = r; ce.g = g; ce.b = b;
}

inline void Emissive::set_ce(const float c){

	ce.r = c; ce.g = c; ce.b = c;
}

inline void Emissive::set_ce(const RGBColor& c){

	ce.r = c.r; ce.g = c.g; ce.b = c.b;
}

#endif
