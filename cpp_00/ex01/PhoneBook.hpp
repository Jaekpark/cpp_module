#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

#define LIMIT 8
#define FIELD_COUNT 5
#define WIDTH 50
#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define EOC "\033[0m"
#define BOLD "\033[1m"
#define TITLE "Crappy Awesome Phone Book |"
#define AUTHOR "Created by Jaekpark |"

enum Command {
	EXIT,
	ADD,
	SEARCH,
	ERROR
};

class PhoneBook {
	private:
		int			index_;
		std::string	cmd_;
		std::string	add_;
		std::string	search_;
		std::string	exit_;
		std::string	field_[5];
		Contact		contact_[LIMIT];
	
	public:
		void	executeAdd(void);
		void	executeSearch(void);
		void	printHeader(void) const;
		void	printManual(void) const;
		void	printAddPanel(void) const;
		void	printSearchPanel(void) const;
		void	printContact(int index) const;
		void	getCommand(void);
		int		checkCommand(void);
		void	saveContact(std::string *input);
		int		searchContact(void);
		int		getUserInput(std::string *message, std::string *target, int size);
		void	eraseWhiteSpace(std::string& target) const;
		PhoneBook(void);
		~PhoneBook(void);
};

#endif
