#include "Dog.hpp"

void	Dog::makeSound(void) const {
	printPanel(DOG, CYAN, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Bark!!! Bark!!!", GREEN);
}

void	Dog::printBrain(void) {
	brain_->printBrain(id_, type_);
}

void	Dog::newBrain(void) {
	printPanel("Dog Brain", CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	std::cout << "     | ";
	brain_ = new Brain();
}

Dog::Dog(void) : Animal() {
	setType(DOG);
	printPanel(DOG, CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Dog Instance Created.");
	newBrain();
}

Dog& Dog::operator=(const Dog& ref) {
	if (this != &ref) {
		setType(ref.getType());
		delete(brain_);
		newBrain();
	}
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
	newBrain();
}

Dog::~Dog(void) {
	printPanel("Dog Brain", CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	std::cout << "     | ";
	delete(brain_);
	printPanel(DOG, CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Dog Instance deleted.");
}