#include "Zombie.hpp"

int	main( void ) {
	std::string name;
	std::string count;
	Zombie* horde;
	int	num;

	std::cout << BOLD << "Enter name and number of Zombie." << std::endl;
	std::cout << EOC << std::endl << "Name : ";
	if (!(std::getline(std::cin >> std::ws, name)) || std::cin.eof())
		exit(1);
	std::cout << "Number of Zombie : ";
	if (!(std::getline (std::cin >> std::ws, count)) || std::cin.eof())
		exit(1);
	try {
		num = std::stoi(count, 0, 10);
	} catch (const std::exception& exception) {
		std::cout << RED << "> " << exception.what() << EOC << std::endl;
		return (1);
	}
	if (num <= 0)
		exit(1);
	std::cout << std::endl << "[Zombies are waking up.]" << std::endl;
	horde = Zombie::zombieHorde(num, name);
	if (!horde)
		exit(1);
	std::cout << std::endl << "[A horde of zombies shout and charge.]" << std::endl;
	for (int i = 0; i < num; i++) {
		horde[i].announce();
	}
	std::cout << std::endl << "[Zombies retreat.]" << std::endl;
	delete[]horde;
	return 0;
}