
#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__


#include "RGBColor.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"

class Material;

class GeometricObject{

public:

	//default constructor
	GeometricObject(void);

	//copy constructor
	GeometricObject(const GeometricObject& object);

	//default constructor
	~GeometricObject(void);

	virtual GeometricObject* clone (void) const = 0; // virtual copy constructor

	virtual bool hit (const Ray& ray, double& t, ShadeRec& pixel_size) const = 0;

	//Making three functions that will only be valid for chapter 3

	virtual void set_material(Material* mPtr);

	Material* get_material(void) const;

	void set_color(const RGBColor& c);

	void set_color(const float r, const float g, const float b);

	RGBColor get_color(void);

protected:

	mutable Material* material_ptr;

	RGBColor color;

	//assignment operator
	GeometricObject& operator= (const GeometricObject& rhs);
};


inline void GeometricObject::set_color(const RGBColor& c){
	color = c;
}

inline void GeometricObject::set_color(const float r, const float g, const float b){

	color.r =r;
	color.g = g;
	color.b = b;
}

inline RGBColor GeometricObject::get_color(void){

	return color;
}

#endif

