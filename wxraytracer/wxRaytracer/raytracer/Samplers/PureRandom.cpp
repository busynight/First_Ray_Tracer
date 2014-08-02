#include "PureRandom.h"


PureRandom::PureRandom(void) : Sampler() {
	
	generate_samples();
}

PureRandom::PureRandom(const int num) : Sampler(num){

	generate_samples();
}

PureRandom::PureRandom(const PureRandom& p) : Sampler(p){

	generate_samples();
}

PureRandom* PureRandom::clone(void) const{

	return new PureRandom(*this);
}

void PureRandom::generate_samples(){

	for(int i = 0; i < num_sets; ++i){

		for(int j = 0; j < num_samples; ++j){

			samples.push_back( Point2D( rand_float(),rand_float()) );
		}
	}
	
}

PureRandom::~PureRandom(void){}
