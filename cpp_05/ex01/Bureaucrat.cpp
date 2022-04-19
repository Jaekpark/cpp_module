#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name_("default"), grade_(150) {
	Console::panel(ME, BLUE);
	Console::panel(CONS, GREEN);
	Console::log("Bureaucrat created.", GREEN);
}

Bureaucrat::Bureaucrat(const std::string name) : name_(name), grade_(150) {
	Console::panel(ME, BLUE);
	Console::panel(CONS, GREEN);
	Console::log("Bureaucrat created.", GREEN);
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: name_(name), grade_(grade) {
	if (grade_ < MAX)
		throw GradeTooHighException();
	if (grade_ > MIN)
		throw GradeTooLowException();
	Console::panel(ME, BLUE);
	Console::panel(CONS, GREEN);
	Console::log("Bureaucrat created.", GREEN);
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
	: name_(ref.name_), grade_(ref.grade_) {
	if (grade_ < MAX)
		throw GradeTooHighException();
	if (grade_ > MIN)
		throw GradeTooLowException();	
	Console::panel(ME, BLUE);
	Console::panel(COPY, MAGENTA);
	Console::log("Bureaucrat copied.", MAGENTA);
}

Bureaucrat::~Bureaucrat(void) {
	Console::panel(ME, BLUE);
	Console::panel(DES, RED);
	Console::log("Bureaucrat deleted.", RED);
}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat& ref) {
	if (this != &ref) {
		*(const_cast<std::string *>(&name_)) = ref.name_;
		grade_ = ref.grade_;
	}
	if (grade_ < MAX)
		throw GradeTooHighException();
	if (grade_ > MIN)
		throw GradeTooLowException();
	Console::panel(ME, BLUE);
	Console::panel(ASSG, BLUE);
	Console::log("Bureaucrat assigned.");
	return *this;
}

std::ostream&		operator<<(std::ostream& out, const Bureaucrat& ref) {
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return out;
}

void				Bureaucrat::signForm(Form& doc) {
	try {
		doc.beSigned(*this);
		Console::panel(getName(), BLUE);
		Console::panel(doc.getName(), BLUE);
		std::string f_name(doc.getName());
		f_name += " sign complete.";
		Console::log(f_name, GREEN);
	} catch (std::exception& e) {
		Console::panel(getName(), BLUE);
		Console::panel(doc.getName(), YELLOW);
		std::cout << " " << getName() << " cannot sign " << doc.getName() << " because ";
		std::cout << YELLOW << e.what() << std::endl << EOC;
	}
}

const char*			Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Oh my god. Grade too high. (available 150 to 1)";
}

const char*			Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Oops! Grade too low. Work harder. (available 150 to 1)";
}

int					Bureaucrat::getGrade(void) const {
	return grade_;
}

const std::string	Bureaucrat::getName(void) const {
	return name_;
}

void				Bureaucrat::increment(void) {
	if (grade_ <= MAX)
		throw GradeTooHighException();
	grade_--;
	Console::panel(ME, BLUE);
	Console::panel(FUNC, MAGENTA);
	Console::log("Increment grade.", GREEN);
}

void				Bureaucrat::decrement(void) {
	if (grade_ >= MIN)
		throw GradeTooLowException();
	grade_++;
	Console::panel(ME, BLUE);
	Console::panel(FUNC, MAGENTA);
	Console::log("Decrement grade.", YELLOW);
}