#ifndef __SPHERE__
#define __SPHERE__

#include "GeometricObject.h"

class Sphere : public GeometricObject {

public:

	//default constructor
	Sphere(void);

	//copy constructor
	Sphere(const Sphere& sphere);

	//Virtual copy constructor

	virtual Sphere* clone (void) const;

	//Mutated constructor
	Sphere(Point3D cener, double r);

	//destructor
	virtual ~Sphere(void);

	//assignment operator
	Sphere& operator= (const Sphere& rhs);

	void set_center(const Point3D& c);

	void set_center(const double x, const double y, const double z);

	void set_radius(const double r);

	virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;

private:

	//center of the sphere
	Point3D		center;
	//radius of the sphere
	double		radius;

	static const double kEpsilon;

};

inline void Sphere::set_center(const Point3D& c){

	center = c;

}

inline void Sphere::set_center(const double x, const double y, const double z){

	center.x = x;
	center.y = y;
	center.z = z;
}

inline void Sphere::set_radius(const double r){
	
	radius = r;
}

#endif
