#ifndef __LIGHT__
#define __LIGHT__

#include "Vector3D.h"
#include "ShadeRec.h"
#include "RGBColor.h"

class Light {

public:

	Light(void);
	
	Light(const Light& l);

	virtual Light* clone(void) const = 0;

	Light& operator=(const Light& rhs);
	
	virtual Vector3D get_direction(ShadeRec& sr) = 0;

	virtual RGBColor L(ShadeRec& sr) = 0;

	void set_shadows(const bool s);

	bool casts_shadows(void) const;

	virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

	virtual ~Light(void);

protected:

	bool shadows;


};
inline void Light::set_shadows(const bool s){
	shadows = s;
}

inline bool Light::casts_shadows(void) const{
	return shadows;
}
#endif