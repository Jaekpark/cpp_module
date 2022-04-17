#include "Zombie.hpp"

int isNum(std::string& str) {
	if (str.empty())
		return 1;
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 2;
	}
	return (0);
}

int	main(void) {
	std::string			name;
	std::string			count;
	Zombie* 			horde;
	int					num;

	std::cout << BOLD << "Enter name and number of Zombie." << std::endl;
	std::cout << EOC << std::endl << "Name : ";
	if (!(std::getline(std::cin >> std::ws, name)) || std::cin.eof())
		exit(1);
	std::cout << "Number of Zombie : ";
	if (!(std::getline (std::cin >> std::ws, count)) || std::cin.eof())
		exit(1);
	if (isNum(count)) {
		std::cerr << RED << "> Not a number." << EOC << std::endl;
		exit(1);
	}
	std::stringstream ss(count);
	ss >> num;
	if (num <= 0)
		exit(1);
	std::cout << std::endl << MAGENTA << "[Welcome to Orgrimmar....]" << std::endl;
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