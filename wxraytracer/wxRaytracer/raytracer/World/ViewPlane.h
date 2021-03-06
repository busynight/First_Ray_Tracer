#ifndef __VIEW_PLANE__
#define __VIEW_PLANE__

#include "Sampler.h"
#include "Regular.h"
#include "Jittered.h"
#include "Hammersley.h"
#include "PureRandom.h"
#include "MultiJittered.h"

class ViewPlane{

public:
	
	int		hor_res;				// horizontal image resolution
	int		ver_res;				// vertical image resolution
	int		num_samples;			// number of samples in a pixel, it must be a perfect square
	
	float	pixel_size;				// pixel size

	Sampler* sampler_ptr;

	float	gamma;					// gamma correction factor	
	float	inv_gamma;				// the inverse of the gamma correction factor
	bool	show_out_of_gamut;		// display red if RGBColor out of gamut

public:
	
	// default construct
	ViewPlane(void);

	//copy constructor
	ViewPlane(const ViewPlane& vp);

	//destructor
	~ViewPlane(void);

	//assignment operator
	ViewPlane& operator= (const ViewPlane& rhs);

	void set_sampler(Sampler* sp);

	void set_samples(const int n);

	void set_hor_res(const int h_res);

	void set_ver_res(const int v_res);

	void set_pixel_size(const float size);

	void set_gamma (const float g);

	void set_gamut_display(const bool show);

};

inline void ViewPlane::set_hor_res(const int h_res){

	hor_res = h_res;
}


inline void ViewPlane::set_ver_res(const int v_res){

	ver_res = v_res;
}

inline void ViewPlane::set_pixel_size(const float size){

	pixel_size = size;
}

inline void ViewPlane::set_gamma (const float g){

	gamma = g;

}

inline void ViewPlane::set_gamut_display(const bool show){

	show_out_of_gamut = show;
}

#endif
