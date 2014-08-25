#ifndef __TORUS__
#define __TORUS__

#include "GeometricObject.h"
#include "BBox.h"
class Torus : public GeometricObject {

public:
	Torus(void);

	Torus(const float r1, const float r2);

	Torus(const Torus& t);

	GeometricObject* clone(void) const;

	Torus& operator=(const Torus& rhs);

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

	virtual bool hit (const Ray& ray, double& tmin, ShadeRec& sr) const;

	Normal computeNormal(const Point3D& p) const;

	virtual ~Torus(void);

protected:

	float a;	//	radius from center to ring
	float b;	//	radius of the ring
	BBox bbox;

};

#endif