#ifndef DOG_H
#define DOG_H

#define DOG "Dog"

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private:
		Brain* brain_;

	public:
		void	makeSound(void) const;

		Dog(void);
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		~Dog(void);
};

#endif