#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

#define SHRU_NAME "ShrubberyCreationForm"
#define SHRU_SIGN 145
#define SHRU_EXEC 137

class ShrubberyCreationForm : public Form {
	private:
		ShrubberyCreationForm(void);

	public:
		void 					execute(const Bureaucrat& executor) const;
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm(void);
};

#endif
