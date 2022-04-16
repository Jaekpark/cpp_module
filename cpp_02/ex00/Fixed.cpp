#include "Fixed.hpp"

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value_;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	value_ = raw;
}

Fixed::Fixed(void) : value_(0) {
	std::cout << "Default constructor called" << std::endl;
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