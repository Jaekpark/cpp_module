#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
	std::cout << YELLOW << "> ";
	std::cout << name_ << " armed " << weapon_->getType() << std::endl;
	std::cout << EOC;
}

void	HumanB::attack(void) const {
	std::cout << std::endl;
	if (!weapon_) {
		std::cout << RED << "> ";
		std::cout << name_ << "has no weapons. Set up his weapon please." << std::endl;
		std::cout << EOC;
	}
	std::cout << GREEN;
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
	std::cout << EOC;
	std::cout << std::endl;
}

HumanB::HumanB(const std::string &name) :name_(name) {
	std::cout << YELLOW << "> ";
	std::cout << name_ << " has been created." << " he need weapon." << std::endl;
	std::cout << EOC;
}

HumanB::~HumanB(void) {
	std::cout << RED << "> ";
	std::cout << name_ << " died." << std::endl;
	std::cout << EOC;
}