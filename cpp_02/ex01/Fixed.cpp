#include "Fixed.hpp"

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value_;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	value_ = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(value_) / (1 << frac_bits_);
}

int Fixed::toInt(void) const {
	return value_ >> frac_bits_;
}

std::ostream &operator<<(std::ostream &output, const Fixed &ref) {
	return output << ref.toFloat();
}

Fixed::Fixed(void) : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << Fixed::frac_bits_) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
	: value_(static_cast<int>(roundf(value * (1 << frac_bits_)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref) {
		value_ = ref.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}