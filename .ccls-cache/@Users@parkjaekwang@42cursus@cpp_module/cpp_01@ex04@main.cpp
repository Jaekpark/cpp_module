#include "Replace.hpp"

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cerr << argv[0] << ": Try " << argv[0];
		std::cerr << " [File] [Target string] [Replace string]" << std::endl;
		std::cout << std::endl;
		return 1;
	}
	std::string str(argv[1]);
	Replace::replaceFile(str, argv[2], argv[3]);

	return 0;
}
