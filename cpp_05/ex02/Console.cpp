#include "Console.hpp"

Console::Console(void) : id_(0) {}

Console::Console(const Console& ref) : id_(ref.id_) {}

Console& Console::operator=(const Console& ref) {
	if (this != &ref)
		id_ = ref.id_;
	return *this;
}

Console::~Console(void) {}

void		Console::panel(const std::string type, const std::string color, int width) {
	std::cout << BOLD << "[" << color << std::setw(width) << type << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Console::panel(const std::string type, const std::string color) {

	std::cout << BOLD << "[" << color << std::setw(WIDTH) << type << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Console::panel(const std::string type) {
	std::cout << BOLD << "[" << std::setw(WIDTH) << type << EOC;
	std::cout << BOLD << " ] " << EOC;
}

void		Console::header(std::string* title, int size) {
	if (!title || size <= 0)
		return ;
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl << std::setfill(' ');
	for (int i = 0; i < size; i++)
		panel(title[i]);
	std::cout << BOLD << "     | Log" << EOC << std::endl;
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl << std::setfill(' ');
}

void		Console::log(const std::string log, const std::string color) {
	std::cout << " " <<  color << log << EOC << std::endl;
}

void		Console::log(const std::string log) {
	std::cout << " " << log << EOC << std::endl;
}

void		Console::pad(int size) {
	if (size == 0)
		return ;
	std::cout << std::setw(size) << std::setfill(' ') << " ";
}