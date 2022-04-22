#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <iomanip>


template<typename T>
void	iter(T* array, size_t length, void(*f)(const T&)) {
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void	display(const T& ref) {
	std::cout << std::setw(10) << ref << std::endl;
}
#endif