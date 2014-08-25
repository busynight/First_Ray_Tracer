#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "GeometricObject.h"

class Triangle : public GeometricObject{

public:
	Triangle(void);
	Triangle(const Point3D& p0, const Point3D& p1, const Point3D& p2);
	Triangle(const Triangle& t);

	virtual GeometricObject* clone (void) const;
	Triangle& operator=(const Triangle& rhs);


	virtual bool hit (const Ray& ray, double& t, ShadeRec& sr) const;
	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

	virtual ~Triangle(void);


	Point3D v0, v1, v2;		//vertices of the triangle
	Normal	normal;


};

#endif