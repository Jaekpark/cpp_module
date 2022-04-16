#include "WrongAnimal.hpp"

void		WrongAnimal::printPanel(const std::string str, const std::string color, int width) {
	std::cout << BOLD << "[" << color << std::setw(width) << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		WrongAnimal::printPanel(const std::string str, const std::string color) {
	std::cout << BOLD << "[" << color << std::setw(WIDTH) << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		WrongAnimal::printPanel(const std::string str) {
	std::cout << BOLD << "[" << std::setw(WIDTH) << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		WrongAnimal::printHeader(void) {
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl << std::setfill(' ');
	printPanel("Class Type");
	printPanel("Log Type");
	printPanel("Func Type");

	std::cout << BOLD << "     | Log" << EOC << std::endl;
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl << std::setfill(' ');
}

void		WrongAnimal::printLog(const std::string str, const std::string color) const {
	std::cout << std::setw(7) << "| " <<  color << str << EOC << std::endl;
}

void		WrongAnimal::printLog(const std::string str) const {
	std::cout << std::setw(7) << "| " << str << EOC << std::endl;
}

void		WrongAnimal::printType(void) const {
	if (getType().empty()) {
		printPanel(W_ANIMAL, EOC);
		printPanel(FUNC, CYAN);
		printPanel("Print Type", BLUE);
		printLog("Type is empty.");

	} else {
		printPanel(getType(), YELLOW);
		printPanel(FUNC, CYAN);
		printPanel("Print Type", BLUE);
		printLog(getType());
	}
}

void		WrongAnimal::makeSound(void) const {
	printPanel(W_ANIMAL, EOC, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Unavailable.", RED);
}

std::string WrongAnimal::getType(void) const {
	return type_;
}

void		WrongAnimal::setType(const std::string& type) {
	type_ = type;
}

WrongAnimal::WrongAnimal(void) {
	printPanel(W_ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Wrong Animal Instance Created.");
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref) {
	printPanel(W_ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Wrong Animal Instance Created.");
	type_ = ref.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref) {
	printPanel(W_ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	if (this != &ref) {
		type_ = ref.type_;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	printPanel(W_ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Wrong Animal Instance deleted.");
}
