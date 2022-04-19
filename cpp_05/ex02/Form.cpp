#include "Form.hpp"

Form::Form(void)
	: name_("default"), sign_grade_(1), exec_grade_(1), is_signed_(false) {
	Console::panel(FORM, CYAN);
	Console::panel(CONS, GREEN);
	Console::log("Form created.", GREEN);
	if (sign_grade_ < MAX || exec_grade_ < MAX)
		throw Form::GradeTooHighException();
	else if (sign_grade_ > MIN || exec_grade_ > MIN)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string& name, const int& sign, const int& exec)
	: name_(name), sign_grade_(sign), exec_grade_(exec), is_signed_(false) {
	Console::panel(FORM, CYAN);
	Console::panel(CONS, GREEN);
	Console::log("Form created.", GREEN);
	if (sign_grade_ < MAX || exec_grade_ < MAX)
		throw Form::GradeTooHighException();
	else if (sign_grade_ > MIN || exec_grade_ > MIN)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& ref)
	: name_(ref.name_), sign_grade_(ref.sign_grade_)
	, exec_grade_(ref.exec_grade_), is_signed_(ref.is_signed_) {
	Console::panel(FORM, CYAN);
	Console::panel(COPY, GREEN);
	Console::log("Form copied.", GREEN);
	if (sign_grade_ < MAX || exec_grade_ < MAX)
		throw Form::GradeTooHighException();
	else if (sign_grade_ > MIN || exec_grade_ > MIN)
		throw Form::GradeTooLowException();
}

Form::~Form(void) {
	Console::panel(FORM, CYAN);
	Console::panel(DES, RED);
	Console::log("Form deleted.", RED);
}

Form&				Form::operator=(const Form& ref) {
	if (this != &ref) {
		*(const_cast<std::string *>(&name_)) = ref.name_;
		*(const_cast<int *>(&sign_grade_)) = ref.sign_grade_;
		*(const_cast<int *>(&exec_grade_)) = ref.exec_grade_;
		is_signed_ = ref.is_signed_;
	}
	return *this;
}

std::ostream& 		operator<<(std::ostream& out, const Form& ref) {
	out << std::setw(20) << ref.getName() 
	<< std::setw(14) << ref.getSignGrade() 
	<< std::setw(14) << ref.getExecGrade()
	<< std::setw(14) << ref.isSigned();
	return out;
}

const char*			Form::GradeTooHighException::what(void) const throw() {
	return "Unbelievable!!!  Grade too High !!";
}

const char* 		Form::GradeTooLowException::what(void) const throw() {
	return "OMG !! Grade too Low!!";
}

const char* 		Form::AlreadySignedException::what(void) const throw() {
	return "Oops! Already signed!";
}

const char* 		Form::FileFailedException::what(void) const throw() {
	return "File Error.";
}

const char* 		Form::SignRequireException::what(void) const throw() {
	return "This form needs to be signed.";
}

const std::string	Form::getName(void) const {
	return name_;
}

const int&			Form::getSignGrade(void) const {
	return sign_grade_;
}

const int&			Form::getExecGrade(void) const {
	return exec_grade_;
}

bool				Form::isSigned(void) const {
	return is_signed_;
}

void				Form::beSigned(const Bureaucrat& person) {
	std::string name = person.getName();
	const int grade = person.getGrade();
	if (is_signed_ == true)
		throw Form::AlreadySignedException();
	if (grade <= sign_grade_) {
		is_signed_ = true;
		Console::panel(FORM, CYAN);
		Console::panel(FUNC, GREEN);
		name += " signed ";
		name += name_;
		Console::log(name, GREEN);
	} else {
		throw Form::GradeTooLowException();
	}
}

void				Form::condition(const Bureaucrat& executor) const {
	const int grade = executor.getGrade();

	if (!is_signed_)
		throw Form::SignRequireException();
	if (grade > exec_grade_)
		throw Form::GradeTooLowException();
}

void				Form::setFormType(const std::string& type) {
	*(const_cast<std::string *>(&form_type_)) = type;
}
