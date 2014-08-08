
#include "Constants.h"
#include "ShadeRec.h"


ShadeRec::ShadeRec(World& wr): hit_an_object (false), material_ptr(NULL),
	hit_point(), local_hit_point(), t(0.0), normal(), ray(), depth(0), dir(), color(black), w(wr){}

ShadeRec::ShadeRec(const ShadeRec& sr) : hit_an_object (sr.hit_an_object), material_ptr(sr.material_ptr),
	hit_point(sr.hit_point), local_hit_point(sr.local_hit_point), 
	t(sr.t), normal(sr.normal), ray(sr.ray), depth(sr.depth), dir(sr.dir), 
	color(sr.color), w(sr.w){}
