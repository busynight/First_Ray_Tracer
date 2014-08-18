#ifndef __AREALIGHT__
#define __AREALIGHT__

#include "Light.h"
#include "GeometricObject.h"
#include "Material.h"

class AreaLight : public Light {

public:
	AreaLight(void);

	AreaLight(const AreaLight& a);

	Light* clone(void) const;

	AreaLight& operator=(const AreaLight& rhs);

	virtual Vector3D get_direction(ShadeRec& sr);

	virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

	virtual RGBColor L(ShadeRec& sr);

	virtual float G(const ShadeRec& sr) const;

	virtual float pdf(ShadeRec& sr);

	void set_object(GeometricObject* go);

	virtual ~AreaLight(void);

private:

	GeometricObject* object_ptr;
	Material* material_ptr;			// an emissive material
	Point3D sample_point;			// sample point on the surface
	Normal light_normal;			// at sample point
	Vector3D wi;				// unit vector from hit point to sample point

};

inline void AreaLight::set_object(GeometricObject* go){

	object_ptr = go;
	material_ptr = go->get_material();


}
#endif