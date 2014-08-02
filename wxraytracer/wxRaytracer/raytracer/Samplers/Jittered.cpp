#include "Jittered.h"


Jittered::Jittered(void) : Sampler() {

	generate_samples();
}

Jittered::Jittered(const int num_samples) : Sampler(num_samples){
	generate_samples();
}

Jittered::Jittered(const int num_samples, const int m) : Sampler(num_samples, m){

	generate_samples();
}

Jittered::Jittered(const Jittered& j) : Sampler(j){

	generate_samples();
}

Jittered& Jittered::operator=(const Jittered& rhs){

	if(this == &rhs)
		return *this;

	Sampler::operator= (rhs);

	return *this;

}

Jittered* Jittered::clone(void) const{

	return new Jittered(*this);
}
Jittered::~Jittered(void){}

void Jittered::generate_samples(void){


	int n = (int) sqrt((float)num_samples);

	//for each set
	for( int i = 0; i < num_sets; i++){
		//for each column index
		for(int j = 0; j < n; j++){

			//for each row index
			for(int k = 0; k < n; k++){

				Point2D sp( ( k + rand_float()  )  / n , 
							( j + rand_float()  )  / n ); 			
				samples.push_back(sp);
			}
		}
	}
}