#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	condition(executor);
	std::cout << std::endl;
	std::cout << YELLOW << getName() << GREEN << " has been pardoned by Zafod Beeblebrox" << std::endl;
	std::cout << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
  	return *(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(ref))));
}

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form() {
	setFormType(PRES_NAME);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form(target, PRES_SIGN, PRES_EXEC) {
	setFormType(PRES_NAME);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : Form(p) {
	setFormType(PRES_NAME);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}