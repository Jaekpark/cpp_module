#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int value_;
		const static int	frac_bits_ = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& ref);
		Fixed &operator=(const Fixed &ref);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif