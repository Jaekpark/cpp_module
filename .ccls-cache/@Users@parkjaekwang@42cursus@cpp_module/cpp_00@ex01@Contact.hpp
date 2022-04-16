#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

enum InputType {
	FIRST_NAME = 0,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	SECRET
};

class Contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nick_name_;
		std::string phone_number_;
		std::string secret_;

	public:
		void setContact(InputType type, std::string user_input);
		void printContact() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getSecret() const;
		Contact();
		~Contact();
};

#endif