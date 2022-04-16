#include "Cat.hpp"

void	Cat::makeSound(void) const {
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Meow~~ Meow~~", GREEN);

}

Cat::Cat(void) : Animal() {
	setType(CAT);
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Cat Instance Created.");
}

Cat& Cat::operator=(const Cat& ref) {
	if (this != &ref)
		setType(ref.getType());
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
}

Cat::~Cat(void) {
	printPanel(CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Cat Instance deleted.");
}