#include "Zombie.hpp"

void	Zombie::announce(void) const {
	std::cout << CYAN;
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << EOC;
}

void	Zombie::setZombieName(std::string name) {
	_name = name;
}

Zombie::Zombie(std::string name) 
	: _name(name) {
	announce();
}

Zombie::Zombie (void) {
	std::cout << GREEN;
	std::cout << "For The Horde." << std::endl;
	std::cout << EOC;
}

Zombie::~Zombie(void) {
	std::cout << RED;
	std::cout << _name << ": " << "I'll be baaacccccccckkkK..." << std::endl;
	std::cout << EOC;
}