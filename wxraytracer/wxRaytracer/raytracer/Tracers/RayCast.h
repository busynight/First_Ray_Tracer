#ifndef __RAYCAST__
#define __RAYCAST__

#include "Tracer.h"



class RayCast : public Tracer {

public:
	
	RayCast(void);

	RayCast(World* new_world_ptr);

	virtual RGBColor trace_ray(const Ray ray, const int depth) const;

	virtual ~RayCast(void);

};

#endif