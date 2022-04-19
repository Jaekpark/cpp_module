#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

#define PRES_NAME	"PresidentialPardonForm"
#define PRES_SIGN	25
#define PRES_EXEC	5

class PresidentialPardonForm : public Form {
	private:
		PresidentialPardonForm(void);

	public:
		void					execute(const Bureaucrat& executor) const;

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm(void);
};

#endif
