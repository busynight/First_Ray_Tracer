#ifndef __CAMERA__
#define __CAMERA__

#include "Point3D.h"
#include "Vector3D.h"

class World;

class Camera{
public:

	Camera(void);

	virtual ~Camera(void);

	Camera(const Camera& c);

	virtual Camera* clone(void) const = 0;

	virtual void render_scene(const World& w) = 0;	

	void compute_uvw(void);

	void set_eye(const Point3D& p);

	void set_eye(const float x, const float y, const float z);

	void set_lookat(const Point3D& p);

	void set_lookat(const float x, const float y, const float z);

	void set_up_vector(const Vector3D& v);

	void set_up_vector(const float x, const float y, const float z);

	void set_exposure_time(const float exposure);


protected:

	Camera& operator= (const Camera& camera);

	Point3D eye;
	Point3D lookat;

	Vector3D up;
	Vector3D u, v, w;		//Orthonormal Basis Vectors
	float exposure_time;

};

#endif 

inline void Camera::set_eye(const Point3D& p){

	eye = p;
}

inline void Camera::set_eye(const float x, const float y, const float z){

	eye.x = x; eye.y = y; eye.z = z;
}

inline void Camera::set_lookat(const Point3D& p){
	
	lookat = p;
}

inline void Camera::set_lookat(const float x, const float y, const float z){
	
	lookat.x = x; lookat.y = y; lookat.z = z;
}

inline void Camera::set_up_vector(const Vector3D& v){

	up = v;
}

inline void Camera::set_up_vector(const float x, const float y, const float z){

	up.x = x; up.y = y; up.z = z;
}

inline void Camera::set_exposure_time(const float exposure){

	exposure_time = exposure;
}