#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "GeometricObject.h"
#include "Sampler.h"

class Rectangle2D : public GeometricObject
{
public:
	Rectangle2D(void);

	Rectangle2D(const Point3D& p, const Vector3D& new_a, const Vector3D& new_b);

	Rectangle2D(const Point3D& p, const Vector3D& new_a, const Vector3D& new_b, const Vector3D& n);

	Rectangle2D(const Rectangle2D& r);

	virtual GeometricObject* clone(void) const;

	Rectangle2D& operator=(const Rectangle2D& rhs);

	virtual ~Rectangle2D(void);

	void set_sampler(Sampler* sampler);

	virtual bool hit (const Ray& ray, double& tmin, ShadeRec& sr) const;

	virtual bool shadow_hit(const Ray& ray, double& tmin) const;


	// Needed if this is a light_source
	virtual Point3D sample(void);

	virtual float pdf(ShadeRec& sr);

	virtual Normal get_normal(const Point3D& p);

private:

	Point3D pO;
	Vector3D a;
	Vector3D b;
	Normal normal;
	Sampler* sampler_ptr;

	float a_len_squared;
	float b_len_squared;
	float area;
	float inv_area;

};

#endif