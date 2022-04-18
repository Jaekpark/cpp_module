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

int main(void) {
	Animal::printHeader();
	Animal* j = new Dog();
	Animal* i = new Cat();

	j->printBrain();
	i->printBrain();

	delete(j);
	delete(i);
	return 0;
}