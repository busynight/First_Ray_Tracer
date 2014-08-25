#ifndef __ENVIROMENTLIGHT__
#define __ENVIROMENTLIGHT__

#include "Light.h"
#include "Sampler.h"
#include "Material.h"

class EnviromentLight : public Light
{
public:
	EnviromentLight(void);

	EnviromentLight(const EnviromentLight& e);

	virtual Light* clone(void) const;

	EnviromentLight& operator=(const EnviromentLight& rhs);

	void set_sampler(Sampler* sampler);

	void set_material(Material* material);

	virtual Vector3D get_direction(ShadeRec& s);

	virtual RGBColor L(ShadeRec& sr);

	virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

	virtual float pdf(ShadeRec& sr) const;

	virtual ~EnviromentLight(void);

private:

	Sampler* sampler_ptr;
	Material* material_ptr;
	Vector3D u, v, w;
	Vector3D wi;

};

#endif