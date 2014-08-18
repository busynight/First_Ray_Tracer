#ifndef __BOX__
#define __BOX__

#include "GeometricObject.h"

class Box : public GeometricObject {

public:
	
	Box(void);

	Box(const Point3D& min, const Point3D& max);

	Box(const Box& b);

	GeometricObject* clone(void) const;

	Box& operator=(const Box& rhs);

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

	virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

	Normal get_normal(const int face_hit) const;

	virtual ~Box(void);

private:

	double x0, x1;
	double y0, y1;
	double z0, z1;
};


#endif