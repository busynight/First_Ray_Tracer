// this file contains the definition of the World class

#include "wxraytracer.h"

#include "World.h"
#include "Constants.h"

// geometric objects

#include "Plane.h"
#include "Sphere.h"

// tracers

#include "SingleSphere.h"
#include "MultipleObjects.h"

// utilities

#include "Vector3D.h"
#include "Point3D.h"
#include "Point2D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include "Maths.h"
#include "Pinhole.h"

// build functions

//#include "BuildSingleSphere.cpp"
//#include "BuildMultipleObjects.cpp"
#include "BuildBBCoverPic.cpp"

World::World(void) : background_color(black), tracer_ptr(NULL), camera_ptr(NULL) {}

World::~World(void) {
	
	if(tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = NULL;
	}	
	delete_objects();	
}


RGBColor World::max_to_one(const RGBColor& c) const  {
	float max_value = max(c.r, max(c.g, c.b));
	
	if (max_value > 1.0)
		return (c / max_value);
	else
		return (c);
}

void World::set_camera(Camera* c){

	if(camera_ptr) {

		delete camera_ptr;
		camera_ptr = NULL;

	}

	camera_ptr = c;
}

// Set color to red if any component is greater than one
RGBColor World::clamp_to_color(const RGBColor& raw_color) const {
	RGBColor c(raw_color);
	
	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
		c.r = 1.0; c.g = 0.0; c.b = 0.0;
	}
		
	return (c);
}

// raw_color is the pixel color computed by the ray tracer
// its RGB floating point components can be arbitrarily large
// mapped_color has all components in the range [0, 1], but still floating point
// display color has integer components for computer display
// the Mac'pixel_size components are in the range [0, 65535]
// a PC'pixel_size components will probably be in the range [0, 255]
// the system-dependent code is in the function convert_to_display_color
// the function SetCPixel is a Mac OS function
void World::display_pixel(const int row, const int column, const RGBColor& raw_color) const {
	RGBColor mapped_color;

	if (vp.show_out_of_gamut)
		mapped_color = clamp_to_color(raw_color);
	else
		mapped_color = max_to_one(raw_color);
	
	if (vp.gamma != 1.0)
		mapped_color = mapped_color.powc(vp.inv_gamma);
	
   //have to start from max y coordinate to convert to screen coordinates
   int x = column;
   int y = vp.ver_res - row - 1;

   paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
                             (int)(mapped_color.g * 255),
                             (int)(mapped_color.b * 255));
}

ShadeRec World::hit_bare_bones_objects(const Ray& ray) {
	ShadeRec	sr(*this); 
	double		t; 			
	float		tmin 			= kHugeValue;
	int 		num_objects 	= objects.size();
	
	for (int j = 0; j < num_objects; j++)
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object	= true;
			tmin 				= t; 
			sr.color			= objects[j]->get_color(); 
		}
		
	return (sr);   
}

// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it'pixel_size an automatic variable, but it'pixel_size empty 
void World::delete_objects(void) {
	int num_objects = objects.size();
	
	for (int j = 0; j < num_objects; j++) {
		delete objects[j];
		objects[j] = NULL;
	}	
	
	objects.erase (objects.begin(), objects.end());
}


