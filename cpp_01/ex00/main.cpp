#include "Zombie.hpp"

int	main(void) {
	std::string	input;
	Zombie		*heap = Zombie::newZombie("heapZombie");
	Zombie::randomChump("stackZombie");

	while (true) {
		std::cout << std::endl << "Enter zombie name or "
		<< RED << "\"exit\" " EOC << "if you want to terminate program.";
		std::cout << std::endl << "> " << EOC;
		if (!(std::getline(std::cin >> std::ws, input)) || std::cin.eof())
			exit(1);
		if (input.compare("exit") == 0)
			break ;
		Zombie user(input);
	}
	delete(heap);
}