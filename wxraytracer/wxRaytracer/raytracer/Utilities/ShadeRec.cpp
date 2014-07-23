
#include "Constants.h"
#include "ShadeRec.h"


ShadeRec::ShadeRec(World& wr): hit_an_object (false), local_hit_point(), normal(), color(black), w(wr){}

ShadeRec::ShadeRec(const ShadeRec& sr) : hit_an_object (sr.hit_an_object), local_hit_point(sr.local_hit_point), color(sr.color), w(sr.w){}
