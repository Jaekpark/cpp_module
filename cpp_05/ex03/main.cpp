#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	printInfo(std::string str) {
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(70) << str;
	std::cout << std::setw(50) << " " << std::endl;	
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

void	test(Bureaucrat& person, Form* form) {
	person.signForm(*form);
	person.executeForm(*form);
}

int main(void) {
	printInfo("Intern Test");
	std::string unknown_form = "unknown";
	Intern intern;

	Form* shru = intern.makeForm(SC, "shru form");
	Form* robot = intern.makeForm(RR, "robot form");
	Form* pres = intern.makeForm(PP, "pres form");
	Form* unknown = intern.makeForm(unknown_form, "unknown form");

	Bureaucrat biden("Joe Biden", 1);
	Bureaucrat harris("Kamala Harris", 30);
	Bureaucrat putin("Vladimir Putin", 150);

	Console::panel("Intern", BLUE);
	Console::panel("Address", MAGENTA);
	std::cout << " " << unknown << std::endl;
	printInfo(putin.getName());
	test(putin, shru);
	test(putin, robot);
	test(putin, pres);
	printInfo(harris.getName());
	test(harris, shru);
	test(harris, robot);
	test(harris, pres);
	printInfo(biden.getName());
	test(biden, shru);
	test(biden, robot);
	test(biden, pres);

	delete(shru);
	delete(robot);
	delete(pres);
	return 0;
}