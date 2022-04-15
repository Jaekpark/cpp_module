#include "Zombie.hpp"

void	Zombie::announce( void ) const {
	std::cout << CYAN;
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << EOC;
}

Zombie::Zombie( std::string name ) 
	: _name(name) {
	announce();
}

Zombie::Zombie ( void ) {
	std::cout << "Unknown : ?" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << RED;
	std::cout << _name << ": " << "I'll be baaacccccccckkkK..." << std::endl;
	std::cout << EOC;
}