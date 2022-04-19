#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& i) {
	static_cast<void>(i); 
}

Intern::~Intern(void) {}

Form*		Intern::makeForm(const std::string& name, const std::string& target) {
	std::string Forms[3] = { SC, RR, PP };

	try {
		for (int i = 0 ; i < 3 ; ++i) {
			if (Forms[i] == name) {
				switch (i) {
				Console::panel("Intern", BLUE);
				Console::panel("Make Form", GREEN);
				std::cout << GREEN << "Intern creates " << name << " Form" << std::endl;
				case 0:
					return new ShrubberyCreationForm(target);
					break;
				case 1:
					return new RobotomyRequestForm(target);
					break;
				case 2:
					return new PresidentialPardonForm(target);
					break;
				default:
					throw Intern::UnavailFormTypeException();
					break ;
				}
			}
		}
		throw Intern::UnavailFormTypeException();
	} catch (std::exception& e) {
		Console::panel("Intern", BLUE);
		Console::panel("Error", RED);
		std::cerr << " " << e.what() << std::endl;
		return NULL;
	}
}

const char*		Intern::UnavailFormTypeException::what(void) const throw () {
	return "Intern can't create Form. Unavailable Type.";
}

Intern& 		Intern::operator=(const Intern& ref) {
	static_cast<void>(ref);

	return *this;
}

std::ostream&	operator<<( std::ostream& out, const Intern& ref) {
	static_cast<void>(ref);

	out << "I'm Intern... Please....";
	return out;
}