#include "HumanA.hpp"

void	HumanA::attack (void) const {
	std::cout << GREEN;
	std::cout << ">> ";
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
	std::cout << EOC;
}

HumanA::HumanA(const std::string& name, Weapon &weapon) : name_(name), weapon_(weapon) {
	std::cout << YELLOW << "> ";
	std::cout << name_ << " has been created." << " he was armed with a(an) " << weapon_.getType() << std::endl;
	std::cout << EOC;
};

HumanA::~HumanA(void) {
	std::cout << RED << "> ";
	std::cout << name_ << " died." << std::endl;
	std::cout << EOC;
}
