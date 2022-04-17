#include "PhoneBook.hpp"

void	PhoneBook::printHeader(void) const {
	std::cout << "|" << std::setw(WIDTH) << std::setfill('+') << "|" << std::endl;
	std::cout << "|" << std::setw(WIDTH) << std::setfill(' ') << "|" << std::endl;
	std::cout << "|" << std::setw(WIDTH) << std::setfill(' ') << TITLE << std::endl;
	std::cout << "|" << std::setw(WIDTH) << std::setfill(' ') << "|" << std::endl;
	std::cout << "|" << std::setw(WIDTH) << std::setfill(' ') << AUTHOR << std::endl;
	std::cout << "|" << std::setw(WIDTH) << std::setfill(' ') << "|" << std::endl;
	std::cout << "|" << std::setw(WIDTH) << std::setfill('+') << "|" << std::endl;
	std::cout << std::setfill(' ') << std::endl;
	std::cout << "Welcome to the 80s and their unbelievable technology!" << std::endl;
	std::cout << std::endl << "I'm Crappy Awesome Phone Book!" << std::endl;
}

void	PhoneBook::printManual(void) const {
	std::cout << std::endl << BOLD << "You can use three kinds of commands." << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "(1) " << add_ << "\t\t:	Save a new contact." << std::endl;
	std::cout << BLUE << "(2) " << search_ << "\t:	Display a specific contact." << std::endl;
	std::cout << MAGENTA << "(3) " << exit_ << "\t:	Terminate program." << std::endl;
	std::cout << EOC << std::endl;
}

void	PhoneBook::printAddPanel(void) const {
	int	index = index_ % 8;

	std::cout << std::endl;
	if (index_ < 8) {
		std::cout << GREEN;
		std::cout << ">> Add new contact [";
		std::cout << index_ + 1 << "/" << LIMIT << "]" << std::endl;
		std::cout << EOC;
	}
	else {
		std::cout << RED;
		std::cout << ">> Replace contact [";
		std::cout << index + 1 << "/" << LIMIT << "]" << std::endl;
		std::cout << EOC;
	}
	std::cout << std::endl;
}

void	PhoneBook::printSearchPanel(void) const {
	std::cout << std::endl;
	std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;
	std::cout << std::setfill(' ');
	std::cout << "|" << std::setw(10) << "index"; 
	for (int i = 0; i < 3; i++) {
		std::cout << "|" << std::setw(10) << field_[i]; 
	}
	std::cout << "|" << std::endl;
	std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;
	std::cout << std::setfill(' ');
}

void	PhoneBook::printContact(int index) const {
	std::string	target[3];

	target[0] = contact_[index].getFirstName();
	target[1] = contact_[index].getLastName();
	target[2] = contact_[index].getNickName();
	std::cout << "|" << std::setw(10) << index + 1;
	for (int i = 0; i < 3; i++) {
		if (target[i].length() > 10) {
			target[i] = target[i].substr(0, 9);
			target[i].push_back('.');
		}
		std::cout << "|" << std::setw(10) << target[i];
	}
	std::cout << "|" << std::endl;
}

void	PhoneBook::getCommand(void) {
	std::string cmd;
	std::string message = "Please enter a command.";

	if (getUserInput(&message, &cmd, 1))
		cmd_ = "EOF";
	cmd_ = cmd;
}

void	PhoneBook::eraseWhiteSpace(std::string& target) const {
	std::string whitespaces = " \t\f\v\n\r";
	std::size_t found;

	found = target.find_last_not_of(whitespaces);
	if (found != std::string::npos)
		target.erase(found + 1);
}

int		PhoneBook::checkCommand() {
	if (cmd_.compare(add_) == 0)
		return ADD;
	else if (cmd_.compare(search_) == 0)
		return SEARCH;
	else if (cmd_.compare(exit_) == 0)
		return EXIT;
	return ERROR;
}

void	PhoneBook::executeAdd(void) {
	std::string input[FIELD_COUNT];

	printAddPanel();
	if (getUserInput(field_, input, FIELD_COUNT))
		return ;
	saveContact(input);
	index_++;
}

void	PhoneBook::executeSearch(void) {
	if (index_ == 0) {
		std::cout << RED << ">> " << "Sorry. Phone book is empty." << std::endl;
		std::cout << EOC << std::endl;
		return ;
	}
	while (true) {
		printSearchPanel();
		for (int i = 0; i < LIMIT; i++) {
			if (i >= index_)
				break ;
			printContact(i);
		}
		std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;
		std::cout << std::setfill(' ') << std::endl;
		if (searchContact() == 1)
			break ;
	}
}

void	PhoneBook::saveContact(std::string *input) {
	int index = index_ % 8;

	contact_[index].setContact(FIRST_NAME, input[FIRST_NAME]);
	contact_[index].setContact(LAST_NAME, input[LAST_NAME]);
	contact_[index].setContact(NICK_NAME, input[NICK_NAME]);
	contact_[index].setContact(PHONE_NUMBER, input[PHONE_NUMBER]);
	contact_[index].setContact(SECRET, input[SECRET]);
	if (index_ < 8) {
		std::cout << GREEN;
		std::cout << std::endl << ">> " << "Saved contact. ";
		std::cout << "[" << index + 1 << "/" << LIMIT << "]" << std::endl;
		std::cout << EOC;
	}
	else {
		std::cout << RED;
		std::cout << std::endl << ">> " << "Replaced contact. ";
		std::cout << "[" << index + 1 << "/" << LIMIT << "]" << std::endl;
		std::cout << EOC;
	}
}

int		PhoneBook::searchContact(void) {
	std::string input;
	std::string message = "Please enter the index number of contact. (0 to close)";
	int index;

	getUserInput(&message, &input, 1);
	try {
		index = std::stoi(input, 0, 10);
	} catch (const std::exception& exception) {
		std::cout << RED << ">> " << exception.what() << EOC << std::endl;
		return 3;
	}
	if (index == 0)
		return 1;
	else if (index >= 9 || index < 0 || index >= index_ + 1) {
		std::cout << RED << ">> Out of range." << std::endl;
		std::cout << EOC;
		return 2;
	}
	else {
		std::cout << YELLOW << std::endl;
		std::cout << "Contact [" << index << "]" << std::endl;
		contact_[index - 1].printContact();
		std::cout << EOC;
	}
	return 0;
}

int		PhoneBook::getUserInput(std::string *message, std::string *target, int size) {
	if (!message || !target)
		return 1;
	for (int i = 0; i < size; i++) {
		std::cout << message[i] << " : ";
		if (!(std::getline(std::cin >> std::ws, target[i])) || std::cin.eof()) {
			exit(1);
		}
		eraseWhiteSpace(target[i]);
	}
	return 0;
}

PhoneBook::PhoneBook(void) {
	index_ = 0;
	add_ = "ADD";
	search_ = "SEARCH";
	exit_ = "EXIT";
	field_[0] = "First Name";
	field_[1] = "Last Name";
	field_[2] = "Nickname";
	field_[3] = "Phone Number";
	field_[4] = "Darkest Secret";
}

PhoneBook::~PhoneBook(void) {
	std::cout << YELLOW << std::endl;
	std::cout << "Thank you for using the phone book." << std::endl;
	std::cout << std::endl;
	std::cout << "See you next time." << std::endl;
	std::cout << EOC;
}