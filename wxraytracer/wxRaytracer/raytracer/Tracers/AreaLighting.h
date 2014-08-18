#ifndef __AREALIGHTING__
#define __AREALIGHTING__

#include "Tracer.h"


class AreaLighting : public Tracer{

public:
	AreaLighting(void);

	AreaLighting(World* new_world_ptr);

	virtual RGBColor trace_ray(const Ray ray, const int depth) const;

	virtual ~AreaLighting(void);
};


#endif