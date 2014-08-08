#ifndef __SHADE_REC__
#define __SHADE_REC__


#include "Point3D.h"
#include "Normal.h"
#include "RGBColor.h"
#include "Ray.h"

class World;
class Material;


class ShadeRec{

public:

	bool		hit_an_object;		//did the ray hit an object?
	Material*	material_ptr;		//nearest object's material
	Point3D		hit_point;			//world coordinates of hitpoint
	Point3D		local_hit_point;	//for attaching textures to objects
	Normal		normal;				//normal at the hit point
	Ray			ray;				// for specular hightlights
	int			depth;				// recursion depth
	double		t;					// ray parameter
	Vector3D	dir;				// for area lights
	World&		w;					//world reference for shading

	//constructor
	ShadeRec(World& w);	

	//copy constructor
	ShadeRec(const ShadeRec& sr); 

};

#endif