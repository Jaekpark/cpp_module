#include "Zombie.hpp"

int	main( void ) {
	std::string input;
	Zombie *heap = Zombie::newZombie("heapZombie");
	Zombie::randomChump("stackZombie");

	while (true) {
		std::cout << std::endl << "Enter zombie name or \"exit\" if you want to terminate program.";
		std::cout << std::endl << "> ";
		std::getline(std::cin >> std::ws, input);
		if (std::cin.eof())
			exit(1);
		if (input.compare("exit") == 0)
			break ;
		Zombie user(input);
	}
	delete(heap);
}