#ifndef __OPENCYLINDER__
#define __OPENCYLINDER__

#include "GeometricObject.h"

class OpenCylinder : public GeometricObject{

public:
	OpenCylinder(void);
	OpenCylinder(const OpenCylinder& oc);
	OpenCylinder(const float p0, const float p1, const float r);

	virtual GeometricObject* clone(void) const;
	
	OpenCylinder& operator=(const OpenCylinder& rhs);

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

	virtual bool hit (const Ray& ray, double& t, ShadeRec& sr) const;

	virtual ~OpenCylinder(void);

protected:

	float y0, y1;
	float radius;
};

#endif