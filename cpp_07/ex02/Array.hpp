#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>
#include <iomanip>

template <typename T>
class Array {
	private:
		unsigned int	size_;
		T*				arr_;
	
	public:
		Array(void) : size_(0), arr_(NULL) {}

		Array(unsigned int n) : size_(n), arr_(NULL) {
			if (n)
				arr_ = new T[n];
		}

		Array(const Array& ref) : size_(ref.size_), arr_(NULL) {
			if (size_)
				arr_ = new T[size_];
			for (unsigned int i = 0; i < size_; i++)
				arr_[i] = ref.arr_[i];
		}

		~Array(void) {
			if (size_) {
				delete[]arr_;
				arr_ = NULL;
				size_ = 0;
			}
		}

		Array& operator=(const Array& ref) {
			if (this != &ref) {
				if (size_ && arr_) {
					delete[]arr_;
					arr_ = NULL;
					size_ = 0;
				}
				size_ = ref.size_;
				if (size_)
					arr_ = new T[size_];
				for (unsigned int i = 0; i < size_; i++)
					arr_[i] = ref.arr_[i];
			}
			return *this;
		}

		void	print(void) const {
			std::cout << "[" << std::setw(7) << "arrSize" << "]" << ": " << size() << std::endl;
			for (unsigned int i = 0; i < size_; i++) {
				std::cout << "[" << std::setw(7) << i << "]" << std::setw(2)
				<< ": " << std::setw(10) << arr_[i] << std::setw(16) << &arr_[i]
				<< " " << &arr_ << std::endl;
			}
		}

		T& operator[](unsigned int index) {
			if (index >= size_)
				throw OutOfRangeException();
			return arr_[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= size_)
				throw OutOfRangeException();
			return arr_[index];
		}

		unsigned int size(void) const {
			return size_;
		}

		class OutOfRangeException : public std::exception {
			public:
				const char*	what(void) const throw() {
					return "Out of range";
				}
		};
};

template <typename T>
void testMy(T value, unsigned int size) {
	Array<T> origin(size);
	Array<T> assign(size);

	for (unsigned int i = 0; i < size; i++) {
		origin[i] = value;
		value++;
	}
	origin.print();

	assign = origin;
	Array<T> copy(origin);
	assign.print();
	copy.print();
	const Array<T> con(origin);
	std::cout << "constant copy" << std::endl;
	con.print();
}

#endif