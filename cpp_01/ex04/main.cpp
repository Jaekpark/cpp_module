#include "Replace.hpp"

int main(int argc, char **argv) {
	std::string str(argv[1]);
	Replace r;

	if (argc != 4) {
		std::cerr << argv[0] << ": Try " << argv[0];
		std::cerr << " [File] [Target string] [Replace string]" << std::endl;
		std::cout << std::endl;
		return 1;
	}
	r.replaceFile(str, argv[2], argv[3]);
	
	return 0;
}