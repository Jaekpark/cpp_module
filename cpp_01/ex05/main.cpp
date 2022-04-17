#include "Harl.hpp"

int main(void) {
	Harl harl;

	harl.complain("");
	harl.complain(" ");
	harl.complain("abc");
	harl.complain("123");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return 0;
}