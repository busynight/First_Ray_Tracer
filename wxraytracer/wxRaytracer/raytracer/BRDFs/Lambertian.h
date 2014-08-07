#ifndef __LAMBERTIAN__
#define __LAMBERTIAN__

#include "BRDF.h"

class Lambertian : public BRDF{

public:
	Lambertian(void);

	Lambertian(const Lambertian& l);

	virtual ~Lambertian(void);

	Lambertian* clone(void) const;

	Lambertian& operator=(const Lambertian& rhs);

	virtual RGBColor f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;

	virtual RGBColor sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;

	virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

	void set_kd( const float k);

	void set_cd(const float r, const float g, const float b);

	void set_cd(const RGBColor& c);

	void set_cd(const float c);

private:

	float kd;		// diffuse reflection coefficient
	RGBColor cd;	// diffuse color
};

inline void Lambertian::set_kd(const float k){

	kd = k;
}

inline void Lambertian::set_cd(const float r, const float g, const float b){

	cd.r = r; cd.g = g; cd.b = b;
}

inline void Lambertian::set_cd(const float c){

	cd.r = c; cd.g = c; cd.b = c;
}

inline void Lambertian::set_cd(const RGBColor& c){

	cd.r = c.r; cd.g = c.g; cd.b = c.b;
}

#endif