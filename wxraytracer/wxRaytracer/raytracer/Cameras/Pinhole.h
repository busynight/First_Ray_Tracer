#ifndef __PINHOLE__
#define __PINHOLE__

#include "World.h"

class Pinhole : public Camera
{
public:
	Pinhole(void);

	Pinhole(const Pinhole& p);

	virtual Camera* clone(void) const;

	Pinhole& operator= (const Pinhole& rhs);

	virtual void render_scene(const World& w);

	virtual ~Pinhole(void);

	Vector3D ray_direction(const Point2D& p) const;

	void set_view_distance(const float distance);

	void set_zoom(const float z);

protected:

	float d;
	float zoom;
};

#endif

inline void Pinhole::set_view_distance(const float distance){

	d = distance;
}

inline void Pinhole::set_zoom(const float z){

	zoom = z;
}