#include "Tracer.h"


Tracer::Tracer(void) :world_ptr(NULL){}

Tracer::Tracer(World* new_world_ptr) : world_ptr(new_world_ptr){}


RGBColor Tracer::trace_ray(const Ray& ray) const{

	return black;
}

RGBColor  Tracer::trace_ray(const Ray ray, const int depth) const{


	return black;
}

RGBColor Tracer::trace_ray(const Ray ray, float& tmin, const int depth) const {

	return black;
}

Tracer::~Tracer(void){
	
	if (world_ptr)
		world_ptr = NULL;
}
