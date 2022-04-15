#include "Harl.hpp"

void Harl::debug(void) {
		std::cout << "[DEBUG]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
		<< std::endl << "I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]" << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger!" << std::endl
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string index[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int filter = -1;

	for (int i = 0; i < 4; i++)
		if (level == index[i])
			filter = i;
	switch (filter) {
		case 0:
			(this->*(f[0]))();
		case 1:
			(this->*(f[1]))();
		case 2:
			(this->*(f[2]))();
		case 3:
			(this->*(f[3]))();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

Harl::Harl (void) {}
Harl::~Harl (void) {}