#ifndef __BRDF__
#define __BRDF__

#include "RGBColor.h"
#include "Sampler.h"
#include "ShadeRec.h"
#include "Vector3D.h"

class BRDF{

public:
	BRDF(void);

	BRDF( const BRDF& brdf);

	virtual BRDF* clone(void) const = 0;

	BRDF& operator= (const BRDF& rhs);
	
	virtual ~BRDF(void);

	void set_sampler(Sampler* sPtr);

	//This is the BRDF function that contains sr, the input vector, and output vector)
	virtual RGBColor f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const = 0;

	virtual RGBColor sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const = 0;

	virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const = 0;

protected:

	Sampler* sampler_ptr;

};

#endif