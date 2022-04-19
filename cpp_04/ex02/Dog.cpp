#include "Dog.hpp"

void	Dog::makeSound(void) const {
	printClassPanel(*this, CYAN);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Bark!!! Bark!!!", GREEN);
}

void	Dog::printBrain(void) {
	brain_->printBrain(id_, type_);
}

void	Dog::printBrain(int index) {
	if (index < 0) {
		return ;
	}
	brain_->printBrainIdea(id_, type_, index);
}

void	Dog::newBrain(void) {
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	std::cout << "     | ";
	brain_ = new Brain();
}

void	Dog::newBrain(const Brain& target) {
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	std::cout << "     | ";
	brain_ = new Brain(target);
}

Dog::Dog(void) : Animal(), brain_(NULL) {
	setType(DOG);
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Dog Instance Created.");
	newBrain();
}

const Dog& Dog::operator=(const Dog& ref) {
	if (this != &ref) {
		type_ = ref.type_;
		*brain_ = *ref.brain_;
	}
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	return *this;
}

Dog::Dog(const Dog& ref) : Animal(ref) {
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Dog Instance Copied.");
	newBrain(*ref.brain_);
}

Dog::~Dog(void) {
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	std::cout << "     | ";
	delete(brain_);
	printClassPanel(*this, CYAN);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Dog Instance deleted.");
}
