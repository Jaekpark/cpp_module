#include "WellRandom.hpp"

WellRandom::WellRandom(void) : differ_(100) ,index_(0) {
	unsigned int seed = static_cast<unsigned int>(std::time(NULL));

	for (int i = 0; i < SIZE; i++) {
		state_[i] = seed;
		seed += seed + differ_;
	}
}

WellRandom::WellRandom(unsigned int seed) : differ_(100), index_(0) {

	for (int i = 0; i < SIZE; i++) {
		state_[i] = seed;
		seed += seed + differ_;
	}
}

WellRandom::WellRandom(const WellRandom& ref) 
: differ_(ref.differ_), index_(ref.index_) {
	for (int i = 0; i < SIZE; i++) {
		state_[i] = ref.state_[i];
	}
}

WellRandom& WellRandom::operator=(const WellRandom& ref) {
	if (this != &ref) {
		*(const_cast<unsigned int *>(&differ_)) = ref.differ_;
		index_ = ref.index_;
		for (int i = 0; i < SIZE; i++) {
			state_[i] = ref.state_[i];
		}
	}
	return *this;
}

WellRandom::~WellRandom(void) {}

unsigned int	WellRandom::getValue(void) {
	unsigned int a, b, c, d;

	a = state_[index_];
	c = state_[(index_ + 13) & 15];
	b = a ^ c ^ (a << 16) ^ (c << 15);
	c = state_[(index_ + 9) & 15];
	a = state_[index_] = b ^ c;
	d = a ^ ((a << 5) & 0xda442d24U);
	index_ = (index_ + 15) & 15;
	a = state_[index_];
	state_[index_] = a ^ b ^ d ^ (a << 2) ^ (b << 18) ^ (c << 28);
	return state_[index_];
}

unsigned int	WellRandom::getValue(unsigned int max) {
	return getValue() % max;
}

unsigned int	WellRandom::getValue(unsigned int min, unsigned int max) {
	return (unsigned int)((getValue() % (max - min)) + min);
}
