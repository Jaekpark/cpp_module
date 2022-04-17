#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phone_book;

	phone_book.printHeader();
	while (true) {
		phone_book.printManual();
		phone_book.getCommand();
		switch(phone_book.checkCommand()) {
			case ADD:
				phone_book.executeAdd();
				continue;
			case SEARCH:
				phone_book.executeSearch();
				continue;
			case EXIT:
				return 0;
			case ERROR:
				std::cout << RED << "> Invalid Command." << EOC << std::endl;
				continue;
			default:
				continue;
		}
	}
}
