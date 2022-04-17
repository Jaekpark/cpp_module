#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

enum	InputType {
	FIRST_NAME = 0,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	SECRET
};

class	Contact {
	private:
		std::string	first_name_;
		std::string	last_name_;
		std::string	nick_name_;
		std::string	phone_number_;
		std::string	secret_;

	public:
		void		setContact(InputType type, std::string user_input);
		void		printContact(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getSecret(void) const;
		Contact(void);
		~Contact(void);
};

#endif
