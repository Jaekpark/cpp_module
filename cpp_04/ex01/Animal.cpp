#include "Animal.hpp"

int			Animal::animal_count_ = 0;

int			Animal::getAnimalCount(void) {
	return animal_count_;
}

void		Animal::printPanel(const std::string str, const std::string color, int width) {
	std::cout << BOLD << "[" << color << std::setw(width) << getId() << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Animal::printPanel(const std::string str, const std::string color) {

	std::cout << BOLD << "[" << color << std::setw(WIDTH) << id_ << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Animal::printPanel(const std::string str) {
	std::cout << BOLD << "[" << std::setw(WIDTH) << id_ << str << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Animal::printHeader(void) {
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl << std::setfill(' ');
	printPanel("Class Type");
	printPanel("Log Type");
	printPanel("Func Type");

	std::cout << BOLD << "     | Log" << EOC << std::endl;
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl << std::setfill(' ');
}

void		Animal::printLog(const std::string str, const std::string color) const {
	std::cout << std::setw(7) << "| " <<  color << str << EOC << std::endl;
}

void		Animal::printLog(const std::string str) const {
	std::cout << std::setw(7) << "| " << str << EOC << std::endl;
}

void		Animal::printType(void) const {
	if (getType().empty()) {
		printPanel(ANIMAL, EOC);
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

void		Animal::makeSound(void) const {
	printPanel(ANIMAL, EOC, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Make Sound", YELLOW);
	printLog("Unavailable.", RED);
}

void		Animal::printBrain(void) {
	printPanel(ANIMAL, EOC, WIDTH);
	printPanel(FUNC, CYAN, WIDTH);
	printPanel("Print Brain", YELLOW);
	printLog("Unavailable.", RED);
}

int			Animal::getId(void) {
	return id_;
}

std::string Animal::getType(void) const {
	return type_;
}

void		Animal::setType(const std::string& type) {
	type_ = type;
}

Animal::Animal(void) : id_(animal_count_) {
	printPanel(ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(CONS, GREEN, WIDTH);
	printLog("Animal Instance Created.");
	animal_count_++;
}

Animal::Animal(const Animal& ref) : id_(animal_count_) {
	printPanel(ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(COPY, YELLOW, WIDTH);
	printLog("Animal Instance Created.");
	type_ = ref.getType();
	animal_count_++;
}

Animal& Animal::operator=(const Animal& ref) {
	printPanel(ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(ASSG, MAGENTA, WIDTH);
	printLog("Assign Completed.");
	if (this != &ref) {
		type_ = ref.type_;
		id_ = animal_count_;
		animal_count_++;
	}
	return *this;
}

Animal::~Animal(void) {
	printPanel(ANIMAL, EOC, WIDTH);
	printPanel(LOG, BLUE, WIDTH);
	printPanel(DES, RED, WIDTH);
	printLog("Animal Instance deleted.");
	animal_count_--;
}
