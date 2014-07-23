#ifndef __SHADE_REC__
#define __SHADE_REC__

class World;

#include "Point3D.h"
#include "Normal.h"
#include "RGBColor.h"

class ShadeRec{

public:

	bool		hit_an_object;		//did the ray hit an object?
	Point3D		local_hit_point;	//world coordinates of hit point
	Normal		normal;				//normal at the hit point
	RGBColor	color;				//apparently only used for chapter 3 of the book
	World&		w;					//world reference for shading

	//constructor
	ShadeRec(World& w);	

	//copy constructor
	ShadeRec(const ShadeRec& sr); 


};

#endif