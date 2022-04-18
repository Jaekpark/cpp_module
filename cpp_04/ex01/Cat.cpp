#include "Cat.hpp"

void	Cat::makeSound(void) const {
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Meow~~ Meow~~", GREEN);

}

void	Cat::printBrain(void) {
	brain_->printBrain(id_, type_);
}

void	Cat::newBrain(void) {
	printPanel("Cat Brain", CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	std::cout << "     | ";
	brain_ = new Brain();
}

Cat::Cat(void) : Animal() {
	setType(CAT);
	printPanel(CAT, YELLOW, WIDTH);
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
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	return *this;
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Cat Instance Created.");
	newBrain();
}

Cat::~Cat(void) {
	printPanel("Cat Brain", CYAN, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	std::cout << "     | ";
	delete(brain_);
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Cat Instance deleted.");
}