#include "ViewPlane.h"


ViewPlane::ViewPlane(void) : hor_res(600), ver_res(600), pixel_size(1.0), gamma(1.0), inv_gamma(1.0), 
							show_out_of_gamut(false), num_samples(1){}

ViewPlane::ViewPlane(const ViewPlane& vp) : hor_res(vp.hor_res), ver_res(vp.ver_res), pixel_size(vp.pixel_size), 
											gamma (vp.gamma), inv_gamma(vp.inv_gamma), show_out_of_gamut(vp.show_out_of_gamut),
											num_samples(vp.num_samples) {}

ViewPlane::~ViewPlane(void){}

ViewPlane& ViewPlane::operator= (const ViewPlane& rhs) {

	if (this == &rhs)
		return *this;

	hor_res = rhs.hor_res;
	ver_res = rhs.ver_res;
	pixel_size = rhs.pixel_size;
	gamma = rhs.gamma;
	inv_gamma = rhs.inv_gamma;
	show_out_of_gamut = rhs.show_out_of_gamut;
	num_samples = rhs.num_samples;

	return *this;
}