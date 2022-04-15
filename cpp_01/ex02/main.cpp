#include <iostream>
#include <string>

int	main(void) {
	std::string	var = std::string("HI THIS IS BRAIN");
	std::string	*stringPTR = &var;
	std::string	&stringREF = var;

	std::cout << "Origin string address	: " << &var << std::endl;
	std::cout << "stringPTR address	: " << stringPTR << std::endl;
	std::cout << "stringREF address	: " << &stringREF << std::endl;

	std::cout << "Origin string		: " << var << std::endl;
	std::cout << "stringPTR string	: " << *stringPTR << std::endl;
	std::cout << "stringREF string	: " << stringREF << std::endl;

	return 0;
}