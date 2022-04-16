#include "WrongCat.hpp"

void	WrongCat::makeSound(void) const {
	printPanel(W_CAT, YELLOW, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Meow~~ Meow~~", GREEN);

}

WrongCat::WrongCat(void) : WrongAnimal() {
	setType(W_CAT);
	printPanel(W_CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Wrong Cat Instance Created.");
}

WrongCat& WrongCat::operator=(const WrongCat& ref) {
	if (this != &ref)
		setType(ref.getType());
	printPanel(W_CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	return *this;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref) {
	printPanel(W_CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Wrong Cat Instance Created.");
}

WrongCat::~WrongCat(void) {
	printPanel(W_CAT, YELLOW, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Wrong Cat Instance deleted.");
}