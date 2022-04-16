#include "Fixed.hpp"

int	Fixed::getRawBits(void) const {
	return value_;
}

void Fixed::setRawBits(const int raw) {
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

Fixed::Fixed(void) : value_(0) {}

Fixed::Fixed(const int value) : value_(value << Fixed::frac_bits_) {}

Fixed::Fixed(const float value)
	: value_(static_cast<int>(roundf(value * (1 << frac_bits_)))) {}

Fixed::Fixed(const Fixed &ref) {
	*this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref) {
	if (this != &ref) {
		value_ = ref.getRawBits();
	}
	return *this;
}

bool Fixed::operator<(const Fixed &ref) {
	return value_ < ref.getRawBits();
}

bool Fixed::operator>(const Fixed &ref) {
	return value_ > ref.getRawBits();
}

bool Fixed::operator>=(const Fixed &ref) {
	return value_ >= ref.getRawBits();
}

bool Fixed::operator<=(const Fixed &ref) {
	return value_ <= ref.getRawBits();
}

bool Fixed::operator==(const Fixed &ref) {
	return value_ == ref.getRawBits();
}

bool Fixed::operator!=(const Fixed &ref) {
	return value_ != ref.getRawBits();
}

Fixed Fixed::operator+(const Fixed &ref) {
	Fixed result(this->toFloat() + ref.toFloat());
	return result;
}

Fixed Fixed::operator-(const Fixed &ref) {
	Fixed result(this->toFloat() - ref.toFloat());
	return result;
}

Fixed Fixed::operator*(const Fixed &ref) {
	Fixed result(this->toFloat() * ref.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed &ref) {
	Fixed result(this->toFloat() / ref.toFloat());
	return result;
}

Fixed &Fixed::operator++(void) {
	value_++;
	return *this;
}

Fixed &Fixed::operator--(void) {
	value_--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed result(*this);

	this->value_++;
	return result;
}

Fixed Fixed::operator--(int) {
	Fixed result(*this);

	this->value_--;
	return result;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

Fixed::~Fixed(void) {}