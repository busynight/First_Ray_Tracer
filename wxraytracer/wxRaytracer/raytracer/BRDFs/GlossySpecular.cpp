#include "GlossySpecular.h"


GlossySpecular::GlossySpecular(void) : BRDF(), ks(0.0), cs(1.0), exp(1.0){}

GlossySpecular::GlossySpecular(const GlossySpecular& g): BRDF(g), ks(g.ks), cs(g.cs), exp(g.exp) {}

BRDF* GlossySpecular::clone(void) const{
	
	return new GlossySpecular(*this);
}

GlossySpecular& GlossySpecular::operator=(const GlossySpecular& rhs){

	if(this == &rhs)
		return *this;

	BRDF::operator=(rhs);

	ks = rhs.ks;
	cs = rhs.cs;
	exp = rhs.exp;

	return *this;

}

RGBColor GlossySpecular::f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const{

	RGBColor L;
	float ndotwi = sr.normal * wi;
	Vector3D r(-wi + 2.0 * sr.normal * ndotwi);
	float rdotwo = r * wo;

	if (rdotwo > 0.0)
		L = ks * pow(rdotwo, exp);

	return L;
}

RGBColor GlossySpecular::sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const{
	//chapter 25
	return black;
}

RGBColor GlossySpecular::rho(const ShadeRec& sr, const Vector3D& wo) const{

	return black;
}

GlossySpecular::~GlossySpecular(void){}
