#include "Camera.h"

Camera::Camera(void) :
		eye(0.0 , 0.0 , 500.0), lookat(0), up(0.0, 1.0, 0.0),
		u(1.0, 0.0, 0.0),
		v(0.0, 1.0, 0.0),
		w(0.0, 0.0, 1.0),
		exposure_time(1.0){}
	

Camera::~Camera(void){}

Camera::Camera(const Camera& c) : 
		eye(c.eye), lookat(c.lookat), up(c.up), 
		u(c.u), v(c.v), w(c.w), exposure_time(c.exposure_time){}

Camera& Camera::operator= (const Camera& rhs){

	if (this == &rhs)
		return *this;

	eye = rhs.eye;
	lookat = rhs.lookat;

	up = rhs.up;
	u = rhs.u;
	v = rhs.v;
	w = rhs.w;

	exposure_time = rhs.exposure_time;

	return *this;
}

void Camera::compute_uvw(void){

	w = eye - lookat;
	w.normalize();

	u = up ^ w;
	u.normalize();

	// v =  w cross u
	v = w ^ u;

	// take care of the singularity, p.164
	
	if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y) { // camera looking vertically down
		u = Vector3D(0, 0, 1);
		v = Vector3D(1, 0, 0);
		w = Vector3D(0, 1, 0);	
	}
	
	if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) { // camera looking vertically up
		u = Vector3D(1, 0, 0);
		v = Vector3D(0, 0, 1);
		w = Vector3D(0, -1, 0);
	}
}