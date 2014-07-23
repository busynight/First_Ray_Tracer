#ifndef __RGBCOLOR__
#define __RGBCOLOR__


class RGBColor
{
public:

		// default constructor
		RGBColor(void);
		
		RGBColor(float c);
		RGBColor(float red, float green, float blue);
		RGBColor(const RGBColor& c);

		~RGBColor(void);

		// assignment operator
		RGBColor& operator= (const RGBColor& rhs); 

		// overloaded operators
		RGBColor	operator+  (const RGBColor& c) const;	
		RGBColor&	operator+= (const RGBColor& c);
		RGBColor	operator*  (const float a) const;
		RGBColor&	operator*= (const float a);					
		RGBColor	operator/  (const float a) const;
		RGBColor&	operator/= (const float a); 
		RGBColor	operator*  (const RGBColor& c) const;
		bool		operator== (const RGBColor& c) const;				
		
		// raise components to a power
		RGBColor powc(float p) const;
		
		float average(void) const;
public:

	float r, g, b;
};

// inlined member functions
// addition of two colors

inline RGBColor RGBColor::operator+ (const RGBColor& c) const {
	return (RGBColor(r + c.r, g + c.g, b + c.b));
}

// compound addition of two colors
inline RGBColor& RGBColor::operator+= (const RGBColor& c) {
	r += c.r; g += c.g; b += c.b;
    return (*this);
}

// multiplication by a float on the right
inline RGBColor RGBColor::operator* (const float a) const {
	return (RGBColor (r * a, g * a, b * a));	
}

// compound multiplication by a float on the right
inline RGBColor& RGBColor::operator*= (const float a) {
	r *= a; g *= a; b *= a;
	return (*this);
}

// division by float
inline RGBColor RGBColor::operator/ (const float a) const {
	return (RGBColor (r / a, g / a, b / a));
}

// compound division by float
inline RGBColor& RGBColor::operator/= (const float a) {	
	r /= a; g /= a; b /= a;
	return (*this);
}

// component-wise multiplication of two colors
inline RGBColor RGBColor::operator* (const RGBColor& c) const {
	return (RGBColor (r * c.r, g * c.g, b * c.b));
} 

// are two RGBColors the same?
inline bool RGBColor::operator== (const RGBColor& c) const {
	return (r == c.r && g == c.g && b == c.b);
}

// the average of the three components
inline float RGBColor::average(void) const {
	return (0.333333333333 * (r + g + b));
}

// inlined non-member function

// multiplication by a float on the left

RGBColor operator* (const float a, const RGBColor& c);

inline RGBColor operator* (const float a, const RGBColor& c) {
	return (RGBColor (a * c.r, a * c.g, a * c.b));	
}


#endif
