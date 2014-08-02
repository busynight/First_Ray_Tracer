
#ifndef __SAMPLER__
#define __SAMPLER__

#include "Point2D.h"
#include "Point3D.h"

#include "Maths.h"

#include <math.h>
#include <vector>

class Sampler {

public:
	Sampler(void);
	
	
	virtual ~Sampler(void);

	Sampler(const int num);

	Sampler(const int num, const int num_sets);

	Sampler(const Sampler& s);

	Sampler& operator= (const Sampler& rhs);

	void set_num_sets(const int np);

	int get_num_samples(void) const;

	virtual Sampler* clone(void) const = 0;

	// generate sample patterns in a unit square
	virtual void generate_samples(void) = 0;

	// set up the randomly shuffled indices
	void setup_shuffled_indices(void);

	// randomly suffle the samples in the x-direction for each pattern
	void shuffle_x_coordinates(void);

	// randomly suffle the samples in the y-direction for each pattern
	void shuffle_y_coordinates(void);

	void map_samples_to_unit_disk(void);

	// get next sample on unit square
	Point2D sample_unit_square(void);

	Point2D sample_unit_disk(void);

protected:

	int						num_samples;		// the number of sample points in a pattern
	int						num_sets;			// the number of sample sets (patterns) stored
	std::vector<Point2D>	samples;			// sample points on a unit square
	std::vector<Point2D>	disk_samples;		// sample points on a unit circle
	std::vector<int>		shuffled_indices;	// shuffled samples array indices
	unsigned long			count;				// the current number of sample points used
	int						jump;				// random index jump

};

#endif