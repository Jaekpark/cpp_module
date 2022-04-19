#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	condition(executor);
	WellRandom	gen;
	unsigned int num = gen.getValue(9);
	std::string drill =
						"                      _________\n"
						"                     /~~~~~~~~~\\\n"
						"                    (===========) ______________\n"
						"                    |  ||  ||   ||~~~~~~~~~~~~~~|\n"
						"                    |  ||  ||   ||        (@)   |\n"
						"                    |  ||  ||   ||        //    |\n"
						"                    |  ||  ||   ||       //     |\n"
						"                    |  ||  ||   ||(@)===(o)     |\n"
						"                    |  ||  ||   ||        \\    |\n"
						"                    |           ||         \\   |\n"
						"                    |~~~~~~~~~~~||         (@)  |\n"
						"                    |___________||              |\n"
						"                    (___________)|              |\n"
						"                     (_________) |    @--(o)    |\n"
						"                       |     |   (              (\n"
						"                       |     |    \\      (o)     \\\n"
						"                       |     |     \\     /        \\\n"
						"                       |     |      \\   @          \\\n"
						"                       |_____|       \\              \\\n"
						"                       |_____|        \\              \\\n"
						"                       \\_____/         \\              \\\n"
						"                         |/|            \\              \\\n"
						"                      )  |/|             \\              \\\n"
						"                     (  ,|/|  / '         \\              \\\n"
						"                      \\  |/| ( '           \\              \\\n"
						"                _____  ) |/|' )         _   \\              \\\n"
						"          |    |     |___|/|___________| |   \\              \\\n"
						"          |====|     |_________________| |    \\              \\\n"
						"         =|   _|      |_______________|  |     \\              \\\n"
						"             |                           |      \\              \\\n"
						"        _____|___________________________|_______)______________)\n"
						"       |                                                        |\n"
						"       |                                                        |\n"
						"       |________________________________________________________|\n";
	if (num >= 5) {
		std::cout << std::endl << drill << std::endl;
		Console::panel("Robotomy", MAGENTA);
		std::cout << std::endl << std::endl;
		std::cout << GREEN << "ddddduuuuuuuuududuuuududududududuu" << std::endl;
		std::cout << YELLOW << getName() <<  GREEN " has been robotomized successfully" << EOC << std::endl << std::endl;
	} else {
		Console::panel("Robotomy", MAGENTA);
		std::cout << std::endl << std::endl;
		std::cout << RED "???..ddd....dd..??? (broken...)" << std::endl;
		std::cout << YELLOW << getName() << RED << " failed to be robotomized" << EOC std::endl << std::endl;
	}
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
	return *(dynamic_cast<RobotomyRequestForm*>(&(Form::operator=(ref))));
}

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {
	setFormType(ROBOT_NAME);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, ROBOT_SIGN, ROBOT_EXEC) {
	setFormType(ROBOT_NAME);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : Form(r) {
	setFormType(ROBOT_NAME);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}