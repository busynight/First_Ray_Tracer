
#include <algorithm>
#include <ctime>
#include "Constants.h"
#include "Sampler.h"


Sampler::Sampler(void) : num_samples(1), num_sets(83), count(0), jump(0){

	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const int num) : num_samples(num), num_sets(83), count(0), jump(0){

	samples.reserve(num_samples * num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const int num, const int ns) : num_samples(num), num_sets(ns), count(0), jump(0){

	samples.reserve( num_samples * num_sets);
	setup_shuffled_indices();
}

Sampler::Sampler(const Sampler& s) : 
			num_samples(s.num_samples), num_sets(s.num_sets), 
				count(s.count), jump(s.jump), samples(s.samples),
				shuffled_indices( s.shuffled_indices){
}

Sampler& Sampler::operator= (const Sampler& rhs){

	if( this == &rhs)

		return *this;

	num_samples = rhs.num_samples;
	num_sets = rhs.num_sets;
	samples = rhs.samples;
	shuffled_indices = rhs.shuffled_indices;
	count = rhs.count;
	jump = rhs.jump;

	return *this;
}

void Sampler::set_num_sets(const int np){

	num_sets = np;
}

int Sampler::get_num_samples(void) const{
	return num_sets;
}

void Sampler::shuffle_x_coordinates(void){

	for (int p = 0; p < num_sets; p++){

		for(int i = 0; i < num_samples - 1; i++){
			//simple swap, difficult indices
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].x;
			samples[i + p * num_samples + 1].x = samples[target].x;
			samples[target].x = temp;

		}

	}

}


void Sampler::shuffle_y_coordinates(void){

	for (int p = 0; p < num_sets; p++){

		for(int i = 0; i < num_samples - 1; i++){
			//simple swap, difficult indices
			int target = rand_int() % num_samples + p * num_samples;
			float temp = samples[i + p * num_samples + 1].y;
			samples[i + p * num_samples + 1].y = samples[target].y;
			samples[target].y = temp;

		}

	}

}
Point2D Sampler::sample_unit_square(void){

	if (count % num_samples == 0)
		jump = (rand_int() % num_sets) * num_samples;

	return( samples[ 
					jump + shuffled_indices[  jump + count++ % num_samples ]] );
}

void Sampler::setup_shuffled_indices(void){

	shuffled_indices.reserve(num_samples * num_sets);

	std::vector<int> indices;

	for (unsigned int j = 0; j < num_samples; j++)
		indices.push_back(j);

	for(unsigned int p = 0; p < num_sets; p++) {

		random_shuffle(indices.begin(), indices.end());

		for(int j =0; j < num_samples; j++)
			shuffled_indices.push_back(indices[j]);

	}
}

Sampler::~Sampler(void)
{
}
