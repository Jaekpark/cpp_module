#include <iostream>
#include "Array.hpp"

#define MAX_VAL 50

void test42(void) {
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	
	std::cout << std::setw(26) << "Array<int>" << " " << std::setw(26) << "int *" << std::endl; 
	std::cout << std::setfill('-') << std::setw(54) << "" << std::endl << std::setfill(' ');
	std::cout << std::endl << "Input Test" << std::endl; 
    
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
		std::cout << "[" << std::setw(7) << i << "]" << std::setw(2)
		<< ": " << std::setw(15) << numbers[i] << " ";
        mirror[i] = value;
		std::cout << "[" << std::setw(7) << i << "]" << std::setw(2)
		<< ": " << std::setw(15) << mirror[i] << std::endl;
    }
    {
		std::cout << std::endl << "Deep Copy Test" << std::endl; 
		numbers.print();
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		tmp.print();
		test.print();
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
}

void testMy(void) {
	double value = 42.195;
	Array<double> origin(MAX_VAL);
	Array<double> assign(MAX_VAL);

	for (int i = 0; i < MAX_VAL; i++) {
		origin[i] = value;
		value++;
	}
	origin.print();

	assign = origin;
	Array<double> copy(origin);
	assign.print();
	copy.print();
}

int main(void) {
	unsigned int size = 5;
	char c = 98;
	int i = 2432;
	double db = 42.195;
	float ft = 423.12;
	
	test42();
	try {
		std::cout << "char" << std::endl;
		testMy(c , size);
		std::cout << "int" << std::endl;
		testMy(i , size);
		std::cout << "double" << std::endl;
		testMy(db , size);
		std::cout << "float" << std::endl;
		testMy(ft, size);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}