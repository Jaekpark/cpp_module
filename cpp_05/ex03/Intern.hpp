#ifndef INTERN_HPP
#define INTERN_HPP

#define SC "shrubbery creation"
#define RR "robotomy request"
#define PP "presidential pardon"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public :
		Intern(void);
		Intern(const Intern& i);
		~Intern(void);
		
		Intern&	operator=(const Intern& i);
		Form*	makeForm(const std::string& name, const std::string& target);
	
		class UnavailFormTypeException : public std::exception {
			const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Intern& ref);

#endif