#ifndef __PERFECTSPECULAR__
#define __PERFECTSPECULAR__

#include "BRDF.h"

class PerfectSpecular : public BRDF{
public:
	PerfectSpecular(void);

	PerfectSpecular(const PerfectSpecular& p);

	virtual BRDF* clone(void) const;

	PerfectSpecular& operator=(const PerfectSpecular& rhs);

	virtual ~PerfectSpecular(void);

	virtual RGBColor f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;

	virtual RGBColor sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;

	virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

private:

	float kr;
	RGBColor cr;
};

#endif