#include "Convert.hpp"

void	convertSingleChar(char *input) {
	if (Convert::isNumber(input[0])) {
		Convert number(input);
		return;
	}
	Convert ch(input[0]);
}

int 	main(int argc, char **argv) {
	// Convert::isZeroDecimal(argv[1]);
	try {
		if (argc != 2)
			throw std::logic_error("convert : Try ./convert [target]");
		int len = strlen(argv[1]);
		switch (len) {
			case 0:
				throw std::invalid_argument("Invalid argument : Empty value.");
			case 1: {
				convertSingleChar(argv[1]);
				return 0;
			}
			default:
				Convert a(argv[1]);
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
