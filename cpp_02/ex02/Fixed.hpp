#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value_;
		const static int	frac_bits_ = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& ref);
		~Fixed(void);

		Fixed &operator=(const Fixed &ref);

		bool operator<(const Fixed &ref);
		bool operator>(const Fixed &ref);
		bool operator>=(const Fixed &ref);
		bool operator<=(const Fixed &ref);
		bool operator==(const Fixed &ref);
		bool operator!=(const Fixed &ref);

		Fixed operator+(const Fixed &ref);
		Fixed operator-(const Fixed &ref);
		Fixed operator*(const Fixed &ref);
		Fixed operator/(const Fixed &ref);

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &ref);

#endif