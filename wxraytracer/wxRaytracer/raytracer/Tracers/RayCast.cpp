#include "RayCast.h"
#include "ShadeRec.h"
#include "World.h"
#include "Material.h"

RayCast::RayCast(void) : Tracer(){}

RayCast::RayCast(World* new_world_ptr): Tracer(new_world_ptr) {}


RGBColor RayCast::trace_ray(const Ray ray, const int depth) const{
	ShadeRec sr(world_ptr->hit_objects(ray));

	if (sr.hit_an_object){

		sr.ray = ray;
		return sr.material_ptr->shade(sr);
	}
	else
		return world_ptr->background_color;
}

RayCast::~RayCast(void){}
