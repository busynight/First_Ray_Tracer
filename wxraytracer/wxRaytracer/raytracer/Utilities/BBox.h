#ifndef __BBOX__
#define __BBOX__

#include "Point3D.h"
#include "Ray.h"

class BBox{

public:
	BBox(void);

	BBox(const Point3D& p0, const Point3D& p1);

	BBox(const BBox& bbox);

	BBox& operator= (const BBox& rhs);

	bool hit(const Ray& ray) const;

	bool inside(const Point3D& p) const;

	~BBox(void);


	double x0, y0, z0;
	double x1, y1, z1;
};

#endif