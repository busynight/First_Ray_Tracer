#ifndef __PLANE__
#define __PLANE__

#include "GeometricObject.h"

class Plane: public GeometricObject{

public:

	//default constructor
	Plane(void);

	//mutated constructor
	Plane(const Point3D& p, const Normal& n);

	//copy constructor
	Plane(const Plane& plane);

	//virtual copy constructor
	virtual Plane* clone(void) const;

	//assignment operator
	Plane& operator= (const Plane& rhs);

	//destuctor
	virtual ~Plane(void);

	virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

private:

	Point3D		a;		//point that is located within the plane
	Normal		n;		//normal to the plane

	static const double kEpsilon;	//for shadows and secondary rays;
};

#endif