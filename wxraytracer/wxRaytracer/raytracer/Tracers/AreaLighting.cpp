#include "AreaLighting.h"
#include "ShadeRec.h"
#include "World.h"
#include "Material.h"

AreaLighting::AreaLighting(void) : Tracer() {}

AreaLighting::AreaLighting(World* new_world_ptr) : Tracer(new_world_ptr) {}

RGBColor AreaLighting::trace_ray(const Ray ray, const int depth) const{

	ShadeRec sr(world_ptr->hit_objects(ray));

	if (sr.hit_an_object) {
		sr.ray = ray;
		return sr.material_ptr->area_light_shade(sr);
	}
	else
		return world_ptr->background_color;
}

AreaLighting::~AreaLighting(void){}
