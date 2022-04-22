#include "finder.hpp"

static void	printInfo(std::string str) {
	std::cout << std::setw(80) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(45) << str;
	std::cout << std::setw(35) << " " << std::endl;	
	std::cout << std::setw(80) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

Base* generate(void) {
	printInfo("Generate Class");
	srand(std::time(NULL));
	int	num = rand() % 3;
	switch (num) {
		case 0:
			Console::panel("Generated", YELLOW);
			Console::log("A class", GREEN);
			return new A();
		case 1:
			Console::panel("Generated", YELLOW);
			Console::log("B class", GREEN);
			return new B();
		case 2:
			Console::panel("Generated", YELLOW);
			Console::log("C class", GREEN);
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	printInfo("Using Pointer");
	if (dynamic_cast<A*>(p)) {
		Console::panel("Answer", YELLOW);
		Console::log("This is A class", GREEN);
	}
	else if (dynamic_cast<B*>(p)) {
		Console::panel("Answer", YELLOW);
		Console::log("This is B class", GREEN);
	}
	else if (dynamic_cast<C*>(p)) {
		Console::panel("Answer", YELLOW);
		Console::log("This is C class", GREEN);
	}
}

static void whoAmI(Base& p, std::string type) {
	try {
		if (type == "A") {
			(void)dynamic_cast<const A&>(p);
			Console::panel("Answer", YELLOW);
			Console::log("This is A class", GREEN);
		} else if (type == "B") {
			(void)dynamic_cast<const B&>(p);
			Console::panel("Answer", YELLOW);
			Console::log("This is B class", GREEN);
		} else if (type == "C") {
			(void)dynamic_cast<const C&>(p);
			Console::panel("Answer", YELLOW);
			Console::log("This is C class", GREEN);
		}
	} catch (std::exception&) {}
}

void identify(Base& p) {
	printInfo("Using Reference");
	std::string type[3] = {"A", "B", "C"};
	for (int i = 0; i < 3; i++)
		whoAmI(p, type[i]);
}
