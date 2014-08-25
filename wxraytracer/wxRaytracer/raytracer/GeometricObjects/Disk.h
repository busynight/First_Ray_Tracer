#ifndef __DISK__
#define __DISK__

#include "GeometricObject.h"
#include "Sampler.h"

class Disk : public GeometricObject{

public:
	Disk(void);

	Disk(const Point3D& center, const float radius, const Normal n);

	Disk(const Disk& d);

	virtual GeometricObject* clone (void) const;

	Disk& operator=(const Disk& rhs);

	virtual bool hit (const Ray& ray, double& t, ShadeRec& sr) const;

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

	void set_sampler(Sampler* sampler);

	virtual ~Disk(void);

	// Needed if this is a light_source
	virtual Point3D sample(void);

	virtual float pdf(ShadeRec& sr);

	virtual Normal get_normal(const Point3D& p);

private:

	Point3D center;	//center
	float radius;	//radius
	float area;
	float inv_area;

	Vector3D u, v, w;
	Normal normal;
	Sampler* sampler_ptr;
};

#endif