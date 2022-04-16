#include "Dog.hpp"

void	Dog::makeSound(void) const {
	printPanel(DOG, CYAN, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Bark!!! Bark!!!", GREEN);
}

Dog::Dog(void) : Animal() {
	setType(DOG);
	printPanel(DOG, CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Dog Instance Created.");
}

Dog& Dog::operator=(const Dog& ref) {
	if (this != &ref)
		setType(ref.getType());
	printPanel(DOG, CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	return *this;
}

Dog::Dog(const Dog& ref) : Animal(ref) {
	printPanel(DOG, CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Dog Instance Created.");
}

Dog::~Dog(void) {
	printPanel(DOG, CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Dog Instance deleted.");
}