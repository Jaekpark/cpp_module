#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>
#include <iomanip>

class Brain {
	private:

	public:
	
	Brain(void);
	Brain(const Brain& ref);
	Brain& operator=(const Brain& ref);
	~Brain();
};

#endif