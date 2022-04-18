#ifndef DOG_H
#define DOG_H

#define DOG "Dog"

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private:
		Brain*	brain_;
		void	newBrain(void);

	public:
		void	makeSound(void) const;
		void	printBrain(void);
		Dog(void);
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		~Dog(void);
};

#endif