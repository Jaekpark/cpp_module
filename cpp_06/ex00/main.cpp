#include "Convert.hpp"

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error : Try " << argv[0] << " [Input]" << std::endl;
		return 1;
	}
	float a = sqrtf(-1);
	std::cout << std::showpos << a << std::endl;
	Convert convert(argv[1]);

	return 0;
}