#ifndef __DIRECTIONAL__
#define __DIRECTIONAL__

#include "Light.h"
class Directional :	public Light
{
public:
	Directional(void);

	Directional(const Directional& d);

	Directional* clone(void) const;

	Directional& operator= (const Directional& rhs);

	virtual Vector3D get_direction(ShadeRec& sr);

	virtual RGBColor L(ShadeRec& sr);

	virtual ~Directional(void);
	
	void set_color(const float r, const float g, const float b);

	void set_color(const RGBColor& c);

	void set_color(const float c);

	void scale_radiance(const float b);


private:

	RGBColor color;
	float ls;
	Vector3D direction;

};

inline void Directional::scale_radiance(const float b){

	ls = b;
}

inline void Directional::set_color(const float r, const float g, const float b){

	color.r = r; color.g = g; color.b = b;
}

inline void Directional::set_color(const float c){

	color.r = c; color.g = c; color.b = c;
}

inline void Directional::set_color(const RGBColor& c){

	color.r = c.r; color.g = c.g; color.b = c.b;
}

#endif