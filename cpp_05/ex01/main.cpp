#include "Bureaucrat.hpp"

void	printInfo(std::string str) {
	std::cout << std::setw(80) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(40) << str;
	std::cout << std::setw(40) << " " << std::endl;	
	std::cout << std::setw(80) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

void	printFormPanel(void) {
	Console::panel("Name", YELLOW);
	Console::panel("Sign", GREEN, 10);
	Console::panel("exec", BLUE, 10);
	Console::panel("isSigned", MAGENTA, 10);
}

int main(void) {
	printInfo("Form Test");
	Bureaucrat biden("Joe Biden", 1);
	Bureaucrat harris("Kamala Harris", 10);
	Bureaucrat putin("Vladimir Putin", 50);
	Bureaucrat except_high("some", 0);
	Bureaucrat except_low("some", 160);

	Form nuclear("launch a Nuclear", 1, 1);
	Form tax("Raising taxes", 15, 5);
	Form martial("Martial Law", 20, 10);
	Form resign("Resign", 140, 140);
	Form form_high("high", 0, 130);
	Form form_low("low", 140, 180);

	putin.signForm(nuclear);
	putin.signForm(tax);
	putin.signForm(martial);
	putin.signForm(resign);

	harris.signForm(nuclear);
	harris.signForm(tax);
	harris.signForm(martial);
	harris.signForm(resign);

	biden.signForm(nuclear);
	biden.signForm(tax);
	biden.signForm(martial);
	biden.signForm(resign);

	std::cout << std::endl << std::endl;
	printFormPanel();
	std::cout << std::endl;
	std::cout << nuclear << std::endl;
	std::cout << tax << std::endl;
	std::cout << martial << std::endl;
	std::cout << resign << std::endl;
	std::cout << std::endl << std::endl;

	return 0;
}