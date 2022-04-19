#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void	printInfo(std::string str) {
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(60) << str;
	std::cout << std::setw(60) << " " << std::endl;	
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

int isNum(std::string& str) {
	if (str.empty())
		return 1;
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 2;
	}
	return (0);
}

void	test(void) {
	int num = 30;
	std::string input;
	int	animal_index;
	Animal* animals[num];

	Animal::printHeader();
	for (int i = 0; i < num; i++){
		if (i < (num / 2)) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	while (true) {
		printInfo("Brain Search");
		std::cout << "> If you wanna know Animal's Ideas, Enter index of Animal. (or \"exit\" to terminate program.)" << std::endl;
		if (!(std::getline(std::cin >> std::ws, input)) || std::cin.eof()) {
			std::cerr << "error " << std::endl;
			for (int j = 0; j < num; j++)
				delete animals[j];
			exit(1);
		}
		if (input.compare("exit") == 0) {
			std::cout << "> Exit command execute" << std::endl;
			break ;
		}
		if (isNum(input) != 0) {
			std::cout << "> Not a number." << std::endl;
		} else {
			std::stringstream ss(input);
			ss >> animal_index;
			std::cout << animal_index << std::endl;
			if (animal_index >= 0 && animal_index < num) {
				animals[animal_index]->printBrain();
			} else {
				std::cout << "> Out of range." << std::endl;
			}
		}
	}
	for (int j = 0; j < num; j++)
		delete animals[j];
	printInfo("End Animals Array Test.");
}

int main(void) {
	printInfo("Animals Array Test");
	test();
	printInfo("Default Test");
	Animal::printHeader();
	Animal* j = new Dog(); // 0
	Animal* i = new Cat(); // 1
	Dog	*dog = new Dog(); // 2
	Cat *cat = new Cat(); // 3
	Dog *copy_dog = new Dog(*dog); // 4
	Cat *copy_cat = new Cat(*cat); // 5

	j->printBrain(1);
	i->printBrain(1);
	dog->printBrain(1);
	cat->printBrain(1);
	copy_dog->printBrain(1);
	copy_cat->printBrain(1);

	delete(j);
	delete(i);
	delete(dog);
	delete(cat);
	delete(copy_dog);
	delete(copy_cat);
	printInfo("End Default Test");
	return 0;
}