#include "Data.hpp"

Data::Data(void) : name_(NAME), speed_(SPEED), ad_(AD), ap_(AP) {}

Data::Data(std::string name, int speed, int ad, int ap)
	: name_(name), speed_(speed), ad_(ad), ap_(ap) {}

Data::Data(const Data& ref)
	: name_(ref.getName()), speed_(ref.getSpeed()), ad_(ref.getAd()), ap_(ref.getAp()) {}

Data& Data::operator=(const Data& ref) {
	if (this != &ref) {
		name_ = ref.name_;
		speed_ = ref.speed_;
		ad_ = ref.ad_;
		ap_ = ref.ap_;
	}
	return *this;
}

Data::~Data(void) {}

std::string Data::getName(void) const {
	return name_;
}

int			Data::getSpeed(void) const {
	return speed_;
}

int			Data::getAd(void) const {
	return ad_;
}

int			Data::getAp(void) const {
	return ap_;
}

uintptr_t		serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*			deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

std::ostream&	operator<<(std::ostream& out, const Data& ref) {
	out << &ref;

	return out;
}
