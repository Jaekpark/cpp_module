#include "Contact.hpp"

void Contact::setContact(InputType type, std::string user_input) {
	switch (type) {
		case FIRST_NAME:
			first_name_ = user_input;
			break ;
		case LAST_NAME:
			last_name_ = user_input;
			break ;
		case NICK_NAME:
			nick_name_ = user_input;
			break ;
		case PHONE_NUMBER:
			phone_number_ = user_input;
			break ;
		case SECRET:
			secret_ = user_input;
			break ;
		default:
			break ;
		
	}
}

void Contact::printContact() const {
	std::cout << "1. First Name : " << first_name_ << std::endl;
	std::cout << "2. Last Name : " << last_name_ << std::endl;
	std::cout << "3. Nick Name : " << nick_name_ << std::endl;
	std::cout << "4. Phone Number : " << phone_number_ << std::endl;
	std::cout << "5. Darkest Secret : " << secret_ << std::endl;
}

std::string Contact::getFirstName() const {
	return first_name_;
}

std::string Contact::getLastName() const {
	return last_name_;
}

std::string Contact::getNickName() const {
	return nick_name_;
}

std::string Contact::getPhoneNumber() const {
	return phone_number_;
}

std::string Contact::getSecret() const {
	return secret_;
}

Contact::Contact() {
	first_name_ = "";
	last_name_ = "";
	nick_name_ = "";
	phone_number_ = "";
	secret_ = "";
}

Contact::~Contact() {
}