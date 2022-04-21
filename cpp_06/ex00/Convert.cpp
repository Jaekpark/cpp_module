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

int		Convert::toInt(char c) const {
	return static_cast<int>(c);
}

float	Convert::toFloat(char c) const {
	return static_cast<float>(c);
}

double 	Convert::toDouble(char c) const {
	return static_cast<double>(c);
}

bool		Convert::isPrintable(char c) {
	if (c >= MIN_PRINTABLE && c <= MAX_PRINTABLE)
		return true;
	return false;
}

bool		Convert::isNumber(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

void Convert::printChar(void) {
	try {
		if (value_ == HUGE_VAL || value_ == -HUGE_VAL || isnan(value_))
			throw impossible();
		if (isPrintable(toChar()))
			std::cout << CHR << "\'" << toChar() << "\'" << std::endl;
		else
			throw Convert::nonDisplayable();
	} catch (std::exception& e) {
		std::cout << CHR << e.what() << std::endl;
	}
}

void Convert::printInt(void) {
	try {
		if (value_ == HUGE_VAL || value_ == -HUGE_VAL)
			throw impossible();
		if (isnan(value_))
			throw impossible();
		std::cout << INT << toInt() << std::endl;
	} catch (std::exception& e) {
		std::cout << INT << e.what() << std::endl;
	}
}

void Convert::printFloat(void) {
	int prec = std::numeric_limits<float>::digits10;

	try {
		std::stringstream ss;
		ss << toFloat();
		std::string flt(ss.str());
		size_t found = flt.find(".");
		if (found == std::string::npos)
			std::cout << FLT << std::setprecision(prec) << flt << SUFIX_FLT_DEC << std::endl;
		else
			std::cout << FLT << std::setprecision(prec) << flt << SUFIX_FLT << std::endl;
	} catch (std::exception& e) {
		std::cout << FLT << e.what() << SUFIX_FLT <<std::endl;
	}
}

void Convert::printDouble(void) {
	int prec = std::numeric_limits<double>::digits10;

	try {
		std::stringstream ss;
		ss << toDouble();
		std::string dbl(ss.str());
		size_t found = dbl.find(".");
		if (found == std::string::npos)
			std::cout << DBL << std::setprecision(prec) << toDouble() << SUFIX_DEC << std::endl;
		else
			std::cout << DBL << std::setprecision(prec) << toDouble() << std::endl;
	} catch (std::exception& e) {
		std::cout << DBL << e.what() << std::endl;
	}
}

Convert::Convert(char c) {
	if (isPrintable(c))
		std::cout << CHR << "\'" << c << "\'" << std::endl;
	else
		std::cout << CHR << NON_PRINTABLE << std::endl;
	std::cout << INT << toInt(c) << std::endl;
	std::cout << FLT << toFloat(c) << SUFIX_DEC << SUFIX_FLT << std::endl;
	std::cout << INT << toDouble(c) << SUFIX_DEC << std::endl;
}

Convert::Convert(char *input) {
	char *str = NULL;
	if (!input)
		throw std::invalid_argument("Invalid argument : null");
	try {
		value_ = strtod(input, &str);
		if (strlen(str) > 1)
			throw inputUnavailable();
		printChar();
		printInt();
		printFloat();
		printDouble();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Convert::~Convert(void) {}

Convert::Convert(const Convert& ref) {
	value_ = ref.value_;
}

Convert::Convert(void) : value_(0) {}

Convert& Convert::operator=(const Convert& ref) {
	value_ = ref.value_;

	return *this;
}

const char* Convert::inputUnavailable::what(void) const throw() {
	return "Input value not available.";
}

const char* Convert::nonDisplayable::what(void) const throw() {
	return "Non Displayable";
}

const char* Convert::impossible::what(void) const throw() {
	return "impossible";
}
