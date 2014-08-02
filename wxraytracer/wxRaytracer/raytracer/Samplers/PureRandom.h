
#ifndef __PURERANDOM__
#define __PURERANDOM__

#include "Sampler.h"

class PureRandom : public Sampler{

public:
	PureRandom(void);

	PureRandom(const int num);

	PureRandom(const PureRandom& p);

	PureRandom& operator= (const PureRandom& rhs);

	virtual PureRandom* clone(void) const;

	virtual	~PureRandom(void);

private:

	virtual void generate_samples(void);
};


#endif