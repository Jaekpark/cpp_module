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

void	test(void) {
	int num = 30;
	Animal* animals[num];

	for (int i = 0; i < num; i++){
		if (i < (num / 2)) {
			animals[num] = new Dog();
		} else {
			animals[num] = new Cat();
		}
	}
	for (int i = 0; i < num; i++)
		delete animals[i];
}

int main(void) {
	Animal::printHeader();
	Animal* j = new Dog();
	Animal* i = new Cat();

	j->printBrain();
	i->printBrain();

	delete(j);
	delete(i);

	test();
	
	return 0;
}