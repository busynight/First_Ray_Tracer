#include "BRDF.h"


BRDF::BRDF(void) : sampler_ptr(NULL){}

BRDF::BRDF(const BRDF& brdf) : sampler_ptr( brdf.sampler_ptr){}

BRDF& BRDF::operator=(const BRDF& rhs){

	if ( this == &rhs) 

		return *this;

	sampler_ptr = rhs.sampler_ptr;
	
	return *this;	
}

void BRDF::set_sampler(Sampler* sPtr){

	sampler_ptr = sPtr;
}

BRDF::~BRDF(void) {

	if(sampler_ptr){

		delete sampler_ptr;

		sampler_ptr = NULL;

	}

}
