#include "Constants.h" 
#include "Point3D.h"
#include "Vector3D.h"
#include "Pinhole.h"
#include <math.h>

Pinhole::Pinhole(void) : Camera(), d(500.0), zoom(1.0) {}

Pinhole::Pinhole(const Pinhole& p) : Camera(p), d(p.d), zoom(p.zoom) {}

Camera* Pinhole::clone(void) const{

	return new Pinhole(*this);
}

Pinhole& Pinhole::operator= (const Pinhole& rhs){

	if(this == &rhs)
		return *this;

	Camera::operator=(rhs);

	d = rhs.d;
	zoom = rhs.zoom;

	return *this;
}



void Pinhole::render_scene(const World& w){

	RGBColor L;
	ViewPlane vp(w.vp);
	Ray ray;
	int depth = 0;		//recursion depth
	Point2D sp;			//sample point in [0,1] x [0,1]
	Point2D pp;			//sample point on a pixel

	vp.pixel_size /= zoom;
	ray.o = eye;

	for (int r = 0; r < vp.ver_res; r++){		// up || rows
		for(int c = 0; c < vp.hor_res; c++){	// accross || columns
			L = black;

			for (int i = 0; i < vp.num_samples; i++){

				sp = vp.sampler_ptr->sample_unit_square();
				pp.x = vp.pixel_size * ( c - 0.5 * vp.hor_res + sp.x);
				pp.y = vp.pixel_size * ( r - 0.5 * vp.ver_res + sp.y);
				ray.d = ray_direction(pp);
				L += w.tracer_ptr->trace_ray(ray); //, depth);
			}

			L /= vp.num_samples;
			L *= exposure_time;
			w.display_pixel(r,c,L);
	
		}
	}
}


Vector3D Pinhole::ray_direction(const Point2D& p) const{

	Vector3D direction = p.x * u + p.y * v - d * w;
	direction.normalize();
	return direction;
}

Pinhole::~Pinhole(void)
{
}
