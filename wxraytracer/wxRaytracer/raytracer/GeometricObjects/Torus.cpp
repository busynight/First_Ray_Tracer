#include "Torus.h"
#include "Maths.h"

Torus::Torus(void) : GeometricObject(), a(2.0), b(1.0) {}

Torus::Torus(const float r1, const float r2) : GeometricObject(), a(r1), b(r2) {}

Torus::Torus(const Torus& t) : GeometricObject(), a(t.a), b(t.b) {}

GeometricObject* Torus::clone(void) const{

	return new Torus(*this);
}

Torus& Torus::operator=(const Torus& rhs){

	if(this == &rhs)
		return *this;

	GeometricObject::operator=(rhs);

	a = rhs.a;
	b = rhs.b;

	return *this;
}


bool Torus::hit (const Ray& ray, double& tmin, ShadeRec& sr) const{
	/*
	if(!bbox.hit(ray))
		return false;

	*/

	double x1 = ray.o.x; double y1 = ray.o.y; double z1 = ray.o.z;
	double d1 = ray.d.x; double d2 = ray.d.y; double d3 = ray.d.z;

	double coeffs[5];
	double roots[4];

	//define the coefficients

	double sum_d_sqrd = d1 * d1 + d2 * d2 + d3 * d3;
	double e = x1 * x1 + y1 * y1 + z1 * z1 - a * a - b * b;
	double f = x1 * d1 + y1 * d2 + z1 * d3;
	double four_a_sqrd = 4.0 * a * a;

	coeffs[0] = e * e - four_a_sqrd * (b * b - y1 * y1);	//constant term
	coeffs[1] = 4.0 * f * e + 2.0 * four_a_sqrd * y1 * d2;
	coeffs[2] = 2.0 * sum_d_sqrd * e + 4.0 * f * f + four_a_sqrd * d2 * d2;
	coeffs[3] = 4.0 * sum_d_sqrd * f;
	coeffs[4] = sum_d_sqrd * sum_d_sqrd;			// coefficient of t^4	

	//find the roots

	int num_real_roots = SolveQuartic(coeffs, roots);

	bool intersected = false;
	double t = kHugeValue;
	
	if(num_real_roots = 0)	//ray miss the torus
		return false;

	//find the smallest root greater than kEpsilon, if any

	for(int j = 0; j < num_real_roots; ++j){

		if(roots[j] > kEpsilon){
			intersected = true;
			if(roots[j] < t)
				t = roots[j];
		}
	}

	if (!intersected)
		return false;

	tmin = t;
	sr.local_hit_point = ray.o + t * ray.d;
	sr.normal = computeNormal(sr.local_hit_point);

	return true;
}

Normal Torus::computeNormal(const Point3D& p) const{

	Normal n;
	
	double px = p.x; double py = p.y; double pz = p.z;

	double x_squared = px * px; double y_squared = py * py; double z_squared = pz * pz;

	double a_squared = a * a;

	double g = x_squared + y_squared + z_squared - (a_squared + b * b);

	n.x = 4.0 * px * g;
	n.y = 4.0 * py * (g + 2 * a_squared);
	n.z = 4.0 * pz * g;

	n.normalize();

	return n;
}

bool Torus::shadow_hit(const Ray& ray, double& tmin) const{

	if(!shadows)
		return false;
	/*
	if(!bbox.hit(ray))
		return false;

	*/

	double x1 = ray.o.x; double y1 = ray.o.y; double z1 = ray.o.z;
	double d1 = ray.d.x; double d2 = ray.d.y; double d3 = ray.d.z;

	double coeffs[5];
	double roots[4];

	//define the coefficients

	double sum_d_sqrd = d1 * d1 + d2 * d2 + d3 * d3;
	double e = x1 * x1 + y1 * y1 + z1 * z1 - a * a - b * b;
	double f = x1 * d1 + y1 * d2 + z1 * d3;
	double four_a_sqrd = 4.0 * a * a;

	coeffs[0] = e * e - four_a_sqrd * (b * b - y1 * y1);	//constant term
	coeffs[1] = 4.0 * f * e + 2.0 * four_a_sqrd * y1 * d2;
	coeffs[2] = 2.0 * sum_d_sqrd * e + 4.0 * f * f + four_a_sqrd * d2 * d2;
	coeffs[3] = 4.0 * sum_d_sqrd * f;
	coeffs[4] = sum_d_sqrd * sum_d_sqrd;			// coefficient of t^4	

	//find the roots

	int num_real_roots = SolveQuartic(coeffs, roots);

	bool intersected = false;
	double t = kHugeValue;
	
	if(num_real_roots = 0)	//ray miss the torus
		return false;

	//find the smallest root greater than kEpsilon, if any

	for(int j = 0; j < num_real_roots; ++j){

		if(roots[j] > kEpsilon){
			intersected = true;
			if(roots[j] < t)
				t = roots[j];
		}
	}

	if (!intersected)
		return false;

	tmin = t;
	return true;
}


Torus::~Torus(void)
{
}
