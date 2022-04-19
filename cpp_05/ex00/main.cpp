#include "Bureaucrat.hpp"

void userInput(std::string prompt, std::string target) {
	if (!(prompt.empty())) {
		Console::panel("Program", YELLOW);
		Console::panel("Input", CYAN);
		Console::log(prompt, BOLD);
	}
	Console::panel("Program", YELLOW);
	Console::panel(target, CYAN);
	std::cout << " ";
}

int isNum(std::string& str) {
	if (str.empty())
		return 1;
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 2;
	}
	return (0);
}

void	printStatus(Bureaucrat& target) {
	Console::panel(ME, BLUE);
	Console::panel("Operator", BLUE);
	std::cout << " " << BLUE << target << EOC << std::endl;
}

void	control(Bureaucrat& target) {
	std::string cmd[3] = {"exit", "inc", "dec"};
	std::string user_cmd;
	int index = -1;

	while (true) {
		try {
			userInput("Enter \"inc\" or \"dec\" or \"exit\"", "Command");
			if (!(std::getline(std::cin >> std::ws, user_cmd)) || std::cin.eof())
				exit(1);
			for (int i = 0; i < 3; i++)
				if (user_cmd == cmd[i])
					index = i;
			switch (index) {
				case 0:
					exit(0);
				case 1:
					target.increment();
					printStatus(target);
					break ;
				case 2:
					target.decrement();
					printStatus(target);
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

int main(void) {
	std::string name;
	std::string grade;
	int			num;


	while (true) {
		try {
			userInput("Enter name and grade of the Bureaucrat.", "Name");
			if (!(std::getline(std::cin >> std::ws, name)) || std::cin.eof())
				exit(1);
			userInput("", "Grade");
			if (!(std::getline(std::cin >> std::ws, grade)) || std::cin.eof())
				exit(1);
			if (isNum(grade))
				throw grade;
			std::stringstream ss(grade);
			ss >> num;
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