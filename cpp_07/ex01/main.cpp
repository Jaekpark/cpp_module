#include "iter.hpp"
#include <iomanip>

int main(void) {
	std::string str[6] = {"hello", "world", "my", "name", "is", "jaekpark"};
	char c[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int i[6] = {0, 1, 2, 3, 4, 5};
	double db[7] = {3.14, 34.12, 4.2, 42.3, 144.4, 15.5432, 643.56};
	float ft[5] = {2.84, 43.1 ,44.11, 578.23, 1234.123};
	short st[5] = {32, 44, 55, 66, 77};
	unsigned long ulong[5] = {3245343453454342341, 603485920980348, 8902348954390, 2345890543890, 7345890534534};
	int* ptr = new int[5];
	
	std::cout << "[" << std::setw(10) << "string ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(str, 6, &display);
	std::cout << "[" << std::setw(10) << "char ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(c, 6, &display);
	std::cout << "[" << std::setw(10) << "int ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(i, 6, &display);
	std::cout << "[" << std::setw(10) << "double ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(db, 7, &display);
	std::cout << "[" << std::setw(10) << "float ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(ft, 5, &display);
	std::cout << "[" << std::setw(10) << "int * ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(ptr, 5, &display);
	std::cout << "[" << std::setw(10) << "short ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(st, 5, &display);
	std::cout << "[" << std::setw(10) << "ulong ]" << std::endl;
	std::cout << std::setw(10) << std::setfill('-') << "--" << std::endl;
	std::cout << std::setfill(' ');
	iter(ulong, 5, &display);

	delete[]ptr;
}
