#include "NRooks.h"
#include "Maths.h"

NRooks::NRooks(void) : Sampler(){

	generate_samples();
}

NRooks::NRooks(const int num_samples) : Sampler( num_samples ){

	generate_samples();
}

NRooks::NRooks(const int num_samples, const int m) : Sampler( num_samples, m) {

	generate_samples();
}

NRooks::NRooks(const NRooks& n) : Sampler(n) {

	generate_samples();
}

NRooks* NRooks::clone(void) const{

	return new NRooks(*this);
}

NRooks& NRooks::operator=(const NRooks& rhs){

	if(this == &rhs)
		return *this;

	Sampler::operator=(rhs);

	return *this;

}

NRooks::~NRooks(void) {}

void NRooks::generate_samples(void){
	

	// generate samples along the main diagonal

	for (int i = 0; i < num_sets; i++){

		for( int j = 0; j < num_samples; j++){

			Point2D pv;
			pv.x = (j + rand_float() ) / num_samples ;
			pv.y = (j + rand_float() ) / num_samples;
			samples.push_back(pv);
		}
	}

	Sampler::shuffle_x_coordinates();
	Sampler::shuffle_y_coordinates();
}