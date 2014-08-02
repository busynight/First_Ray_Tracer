#include "Regular.h"


Regular::Regular(void) : Sampler(){

	generate_samples();
}

Regular::Regular(const int num): Sampler(num){

	generate_samples();
}

Regular::Regular(const Regular& r) : Sampler(r) {

	generate_samples();
}

Regular& Regular::operator= (const Regular& rhs){

	if(this == &rhs)

		return *this;

	Sampler::operator= (rhs);

	return *this;
}

Regular* Regular::clone(void) const{

	return new Regular(*this);
}

void Regular::generate_samples(void){

	int n = (int) sqrt( (float) num_samples);

	for( int i = 0; i < num_sets; ++i){
		for (int j = 0; j < n; ++j){

			for(int k = 0; k < n; ++k){
				samples.push_back( Point2D( (k + 0.5) / n, (j + 0.5) / n)); 

			}
		}

	}

}

Regular::~Regular(void){}
