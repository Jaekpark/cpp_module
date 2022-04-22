#include "finder.hpp"

int main(void) {
	Base *parent = generate();

	identify(parent);
	identify(*parent);
	delete(parent);
	return (0);
}