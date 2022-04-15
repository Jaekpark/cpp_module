#include "Weapon.hpp"

const std::string &Weapon::getType(void) const {
	return type_;
}

void	Weapon::setType(const std::string &type) {
	std::cout << BLUE << "> ";
	std::cout << "Weapon type is chaged : " << type_ << " -> " << type << std::endl;
	std::cout << EOC;
	type_ = type;
}

Weapon::Weapon(const std::string& type) : type_(type) {
	std::cout << BLUE << "> ";
	std::cout << "Weapon is created : " << type_ << std::endl;
	std::cout << EOC;
}

Weapon::~Weapon(void) {
	std::cout << RED << "> ";
	std::cout << "Weapon destroyed : " << type_ << std::endl;
	std::cout << EOC;
}