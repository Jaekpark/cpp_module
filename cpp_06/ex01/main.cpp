#include "Data.hpp"

void	printInfo(std::string str) {
	std::cout << std::setw(80) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(45) << str;
	std::cout << std::setw(35) << " " << std::endl;	
	std::cout << std::setw(80) << std::setfill('=') << " " << std::endl;
	std::cout << std::setfill(' ');
}

void	printData(Data* ref) {
	Console::panel("Address", MAGENTA);
	std::cout << GREEN << ref << EOC << std::endl;
	Console::panel("Name", YELLOW);
	std::cout << ref->getName() << std::endl;
	Console::panel("Speed", YELLOW);
	std::cout << ref->getSpeed() << std::endl;
	Console::panel("AD", YELLOW);
	std::cout << ref->getAd() << std::endl;
	Console::panel("AP", YELLOW);
	std::cout << ref->getAp() << std::endl;
}

void	test(void) {
	printInfo("before");
	Data* kaisa = new Data();
	printData(kaisa);
	uintptr_t k_ptr = serialize(kaisa);
	
	std::cout << std::endl;
	Data *ash = new Data("Ash", 330, 60, 47);
	printData(ash);
	uintptr_t a_ptr = serialize(ash);

	printInfo("after");
	Data *ds_kaisa = deserialize(k_ptr);
	Data *ds_ash = deserialize(a_ptr);
	printData(ds_kaisa);
	std::cout << std::endl;
	printData(ds_ash);

	delete(kaisa);
	delete(ash);
}

int main(void) {
	test();

	int *aa = new int();
	short cc = 123;
	// int intp = reinterpret_cast<int>(aa);
	short charp = reinterpret_cast<short>(cc);
	// unsigned int uintp = reinterpret_cast<char>(aa);
	// unsigned int uint1 = reinterpret_cast<unsigned int>(aa);
	unsigned long longp = reinterpret_cast<unsigned long>(aa);
	size_t sizep = reinterpret_cast<size_t>(aa);
	// std::cout << intp << std::endl;
	// std::cout << charp << std::endl;
	// std::cout << uintp << std::endl;
	// std::cout << uint1 << std::endl;
	std::cout << charp << std::endl;
	std::cout << longp << std::endl;
	std::cout << sizep << std::endl;
	std::cout << reinterpret_cast<int *>(longp) << std::endl;
	// float floatp = reinterpret_cast<float>(aa)
	// double doublep = reinterpret_cast<double>(aa);

	return 0;
}
