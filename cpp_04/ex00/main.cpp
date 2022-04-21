#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void	printInfo(std::string str) {
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(60) << str;
	std::cout << std::setw(60) << " " << std::endl;	
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

void firstTest(void) {
	printInfo("Basic");
	Animal::printHeader();

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->printType();
	i->printType();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);
	std::cout << std::endl;
}

void	secondTest(void) {	
	printInfo("Animal (virtual)");
	Animal::printHeader();

	const Animal* correct_meta = new Animal();
	const Animal* correct = new Cat();
	const Cat* cc = new Cat();

	correct_meta->printType();
	correct->printType();
	correct_meta->makeSound();
	correct->makeSound();
	cc->makeSound();
	
	delete(correct_meta);
	delete(correct);
	delete(cc);

	std::cout << std::endl;
	printInfo("Wrong Animal (non-virtual)");

	WrongAnimal::printHeader();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong = new WrongCat();
	const WrongCat* wc = new WrongCat();

	wrong_meta->printType();
	wrong->printType();
	wrong_meta->makeSound();
	wrong->makeSound();
	wc->makeSound();

	delete(wrong_meta);
	delete(wrong);
	delete(wc);
}

int main(void) {
	firstTest();
	secondTest();
	return 0;
}