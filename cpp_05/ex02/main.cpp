#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void 	userInput(std::string prompt, std::string target) {
	if (!(prompt.empty())) {
		Console::panel("Program", YELLOW);
		Console::panel("Input", CYAN);
		Console::log(prompt, BOLD);
	}
	Console::panel("Program", YELLOW);
	Console::panel(target, CYAN);
	std::cout << " ";
}

int 	isNum(std::string& str) {
	if (str.empty())
		return 1;
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 2;
	}
	return (0);
}

int		getUserInputNum(void) {
	std::string input;
	int result = -1;

	if (!(std::getline(std::cin >> std::ws, input)) || std::cin.eof()) {
			exit(1);
	}
	if (isNum(input))
		return -1;
	std::stringstream ss(input);
	ss >> result;
	return result;
}

std::string getUserInputString(void) {
	std::string input;
	if (!(std::getline(std::cin >> std::ws, input)) || std::cin.eof())
		exit(1);
	return input;
}

void	printStatus(Bureaucrat& target) {
	Console::panel(ME, BLUE);
	Console::panel("Operator", BLUE);
	std::cout << " " << BLUE << target << EOC << std::endl;
}

void	formPanel(void) {
	std::cout << std::endl;
	std::cout << "\t[ Forms ]" << std::endl;
	std::cout << std::endl;
	std::cout << "\t(1) shrubbery creation form\t: Create shrubbery ascii art." << std::endl;
	std::cout << "\t(2) robotomy request form\t: drill a hole somewhere." << std::endl;
	std::cout << "\t(3) president pardon form\t: president pardons someone." << std::endl;
	std::cout << std::endl;
	std::cout << "\t[ Actions ]" << std::endl;
	std::cout << std::endl;
	std::cout << "\t sign\t: signing the form." << std::endl;
	std::cout << "\t exec\t: execute the form." << std::endl;
	std::cout << std::endl;
}

void	formShru(Bureaucrat &e, ShrubberyCreationForm& s, std::string& sign) {
	if (!sign.compare("sign"))
		e.signForm(s);
	else if (!sign.compare("exec"))
		e.executeForm(s);
	else {
		Console::panel("Program", BLUE);
		Console::panel("Error", RED);
		Console::log("Wrong action", RED);
	}
}

void	formPres(Bureaucrat &e, PresidentialPardonForm& s, std::string& sign) {
	if (!sign.compare("sign"))
		e.signForm(s);
	else if (!sign.compare("exec"))
		e.executeForm(s);
	else {
		Console::panel("Program", BLUE);
		Console::panel("Error", RED);
		Console::log("Wrong action", RED);
	}
}

void	formRobo(Bureaucrat &e, RobotomyRequestForm& s, std::string& sign) {
	if (!sign.compare("sign"))
		e.signForm(s);
	else if (!sign.compare("exec"))
		e.executeForm(s);
	else {
		Console::panel("Program", BLUE);
		Console::panel("Error", RED);
		Console::log("Wrong action", RED);
	}
}

void	printFormPanel(void) {
	std::cout << std::endl;
	std::cout << std::endl;
	Console::panel("Name", YELLOW);
	Console::panel("Sign", GREEN, 10);
	Console::panel("exec", BLUE, 10);
	Console::panel("isSigned", MAGENTA, 10);
	std::cout << std::endl;
}

void	formControl(Bureaucrat& executor) {
	ShrubberyCreationForm shru("Shru Form");
	RobotomyRequestForm robo("Robo Form");
	PresidentialPardonForm pres("Pres Form");
	std::string action;

	while (true) {
		int form = -1;
		formPanel();
		userInput("choose form. (0 to close)", "form");
		form = getUserInputNum();
		if (form == 0)
			return ;
		switch (form) {
			case 1:
				printFormPanel();
				std::cout << shru << std::endl << std::endl;
				userInput("choose action.", "action");
				action = getUserInputString();
				formShru(executor, shru, action);
				break ;
			case 2:
				printFormPanel();
				std::cout << robo << std::endl << std::endl;
				userInput("choose action.", "action");
				action = getUserInputString();
				formRobo(executor, robo, action);
				break ;
			case 3:
				printFormPanel();
				std::cout << pres << std::endl << std::endl;
				userInput("choose action.", "action");
				action = getUserInputString();
				formPres(executor, pres, action);
				break ;
			default:
				Console::panel("Program", BLUE);
				Console::panel("Error", RED);
				Console::log("Wrong form. Enter 1 to 3", RED);
				break ;
		}
	}
}

void	controlPanel(void) {
	std::cout << std::endl;
	std::cout << "\texit\t: terminate program" << std::endl;
	std::cout << "\tinc\t: increase bureaucrat grade" << std::endl;
	std::cout << "\tdec\t: decrease bureaucrat grade" << std::endl;
	std::cout << "\tform\t: Form control" << std::endl;
	std::cout << std::endl;
}



void	control(Bureaucrat& target) {
	std::string cmd[4] = {"exit", "inc", "dec", "form"};
	std::string user_cmd;

	while (true) {
		try {
			int index = -1;
			controlPanel();
			userInput("Enter command. (0 to close)", "Command");
			user_cmd = getUserInputString();
			if (!user_cmd.compare("0"))
				return ;
			for (int i = 0; i < 4; i++)
				if (user_cmd == cmd[i])
					index = i;
			switch (index) {
				case 0:
					return ;
				case 1:
					target.increment();
					printStatus(target);
					break ;
				case 2:
					target.decrement();
					printStatus(target);
					break ;
				case 3:
					formControl(target);
					break ;
				default:
					throw user_cmd;
			}
		} catch (std::exception& e) {
			Console::panel("Program", YELLOW);
			Console::panel("Exception", RED);
			std::cout << RED << " " << e.what() << std::endl << EOC;
		} catch (std::string& error) {
			Console::panel("Program", YELLOW);
			Console::panel("Error", RED);
			error += " : Wrong Input.";
			Console::log(error, RED);
		}
	}
}

void	printInfo(std::string str) {
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(70) << str;
	std::cout << std::setw(50) << " " << std::endl;	
	std::cout << std::setw(120) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

int main(void) {
	std::string name;
	std::string grade;
	int			num;

	printInfo("Special Form TEST");	
	printInfo("by Jaekpark");	
	while (true) {
		try {
			userInput("Enter name and grade of the Bureaucrat. (grade 0 to exit)", "Name");
			name = getUserInputString();
			userInput("", "Grade");
			num = getUserInputNum();
			if (num < 0)
				throw name;
			if (num == 0)
				exit(0);
			Bureaucrat person(name, num);
			printStatus(person);
			control(person);
		} catch (std::exception& e) {
			Console::panel("Program", YELLOW);
			Console::panel("Exception", RED);
			std::cout << RED << " " << e.what() << std::endl << EOC;
		} catch (std::string error) {
			Console::panel("Program", YELLOW);
			Console::panel("Error", RED);
			error += " : Wrong Input.";
			Console::log(error, RED);
		}
	}
	return 0;
}