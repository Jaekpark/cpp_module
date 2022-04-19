#ifndef FORM_HPP
#define FORM_HPP

#define FORM "Form"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	form_type_;
		const std::string	name_;
		const int			sign_grade_;
		const int			exec_grade_;
		bool				is_signed_;


	public:
		Form(void);
		Form(const std::string& name, const int& sign, const int& exec);
		Form(const Form& ref);
		virtual ~Form(void);

		Form& 				operator=(const Form &ref);
		const std::string	getName(void) const;
		const std::string	getFormType(void) const;
		void				setFormType(const std::string& type);
		const int&			getSignGrade(void) const;
		const int&			getExecGrade(void) const;
		bool				isSigned(void) const;
		void				beSigned(const Bureaucrat& person);
		virtual void 		execute(const Bureaucrat& executor) const = 0;
		void				condition(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class FileFailedException : public std::exception {
			public:
				const char *what(void) const throw();
		};

		class SignRequireException : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& ref);

#endif