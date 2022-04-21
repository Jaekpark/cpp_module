#include "Cat.hpp"

void	Cat::makeSound(void) const {
	printClassPanel(*this, YELLOW);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Meow~~ Meow~~", GREEN);

}

void	Cat::printBrain(void) {
	brain_->printBrain(id_, type_);
}

void	Cat::printBrain(int index) {
	if (index < 0) {
		return ;
	}
	brain_->printBrainIdea(id_, type_, index);
}

void	Cat::newBrain(void) {
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	std::cout << "     | ";
	brain_ = new Brain();
}

void	Cat::newBrain(const Brain& target) {
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	std::cout << "     | ";
	brain_ = new Brain(target);
}


Cat::Cat(void) : Animal() {
	setType(CAT);
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Cat Instance Created.");
	newBrain();
}

Cat& Cat::operator=(const Cat& ref) {
	if (this != &ref) {
		setType(ref.getType());
		delete(brain_);
		newBrain();
	}
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	return *this;
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Cat Instance Created.");
	newBrain(*ref.brain_);
}

Cat::~Cat(void) {
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	std::cout << "     | ";
	delete(brain_);
	printClassPanel(*this, YELLOW);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Cat Instance deleted.");
}