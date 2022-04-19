#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include "Console.hpp"

#define MIN 150
#define MAX 1
#define ME "Bureaucrat"

class Bureaucrat {
	private:
		const std::string	name_;
		int					grade_;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat(void);

		Bureaucrat&			operator=(const Bureaucrat& ref);
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);

		void				printClassPanel(const Bureaucrat& target) const;


		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);

#endif
