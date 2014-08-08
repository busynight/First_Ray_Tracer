#ifndef __POINTLIGHT__
#define __POINTLIGHT__

#include "Light.h"
class PointLight : public Light {
public:
	PointLight(void);
	
	PointLight(const PointLight& p);

	virtual Light* clone(void) const;

	PointLight& operator= (const PointLight& rhs);

	virtual ~PointLight(void);

	virtual Vector3D get_direction(ShadeRec& sr);

	virtual RGBColor L(ShadeRec& sr);

	bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

	void set_color(const float r, const float g, const float b);

	void set_color(const RGBColor& c);

	void set_color(const float c);

	void scale_radiance(const float b);

	void set_location(const float x, const float y, const float z);

	void set_location(const Vector3D& l);

	void set_location(const float c);

private:

	float ls;
	RGBColor color;
	Point3D location;

};

inline void PointLight::scale_radiance(const float b){

	ls = b;
}

inline void PointLight::set_color(const float r, const float g, const float b){

	color.r = r; color.g = g; color.b = b;
}

inline void PointLight::set_color(const float c){

	color.r = c; color.g = c; color.b = c;
}

inline void PointLight::set_color(const RGBColor& c){

	color.r = c.r; color.g = c.g; color.b = c.b;
}

inline void PointLight::set_location(const float x, const float y, const float z){

	location.x = x; location.y = y; location.z = z;
}

inline void PointLight::set_location(const Vector3D& l){

	location.x = l.x; location.y = l.y; location.z = l.z;
}

inline void PointLight::set_location(const float c){

	location.x = c; location.y = c; location.z = c;
}


#endif