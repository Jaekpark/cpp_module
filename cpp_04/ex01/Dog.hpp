#ifndef DOG_HPP
#define DOG_HPP

#define DOG "Dog"

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	private:
		Brain*	brain_;
		void	newBrain(void);
		void	newBrain(const Brain& target);

	public:
		void	makeSound(void) const;
		void	printBrain(void);
		void	printBrain(int index);

		Dog(void);
		Dog(const Dog& ref);
		const Dog& operator=(const Dog& ref);
		~Dog(void);
};

#endif