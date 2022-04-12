#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;

	pb.printHeader();
	while (true) {
		pb.printManual();
		pb.getCommand();
		switch(pb.checkCommand()) {
			case ADD:
				pb.executeAdd();
				continue;
			case SEARCH:
				pb.executeSearch();
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
