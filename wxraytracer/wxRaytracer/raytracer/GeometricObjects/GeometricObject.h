
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

	virtual bool shadow_hit(const Ray& ray, float& tmin) const = 0;

protected:

	mutable Material* material_ptr;

	RGBColor color;
	bool shadows;

	//assignment operator
	GeometricObject& operator= (const GeometricObject& rhs);
};



#endif

