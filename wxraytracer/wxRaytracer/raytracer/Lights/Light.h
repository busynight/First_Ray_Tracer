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

	virtual ~Light(void);

protected:

	bool shadows;


};

#endif