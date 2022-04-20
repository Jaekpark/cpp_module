#include "Convert.hpp"

char	Convert::toChar(void) const {
	return static_cast<char>(value_);
}
int		Convert::toInt(void) const {
	return static_cast<int>(value_);
}
float	Convert::toFloat(void) const {
	return static_cast<float>(value_);
}
double 	Convert::toDouble(void) const {
	return static_cast<double>(value_);
}

Convert::~Convert(void) {}


Convert::Convert(char *input) {
	char *str = NULL;

	value_ = std::strtod(input, &str);
	std::cout << "[" << value_ << "]" << str[0] << std::endl;
	std::cout << "[" << toFloat() << "]" << str[0] << std::endl;
	std::cout << "[" << toInt() << "]" << str[0] << std::endl;
	std::cout << "[" << toChar() << "]" << str[0] << std::endl;
}

Convert::Convert(const Convert& ref) {
	value_ = ref.value_;
	input_ = ref.input_;
}

Convert::Convert(void) : value_(0), input_("") {}

Convert& Convert::operator=(const Convert& ref) {
	value_ = ref.value_;
	input_ = ref.input_;

	return *this;
}
