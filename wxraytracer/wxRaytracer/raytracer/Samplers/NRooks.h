#ifndef __NROOKS__
#define __NROOKS__


#include "Sampler.h"
class NRooks :	public Sampler{

public:

	NRooks(void);

	NRooks(const int num_samples);

	NRooks(const int num_samples, const int m);

	NRooks(const NRooks& n);

	virtual NRooks* clone(void) const;

	NRooks& operator= (const NRooks& rhs);

	virtual ~NRooks(void);

private:

	virtual void generate_samples(void);

};

#endif