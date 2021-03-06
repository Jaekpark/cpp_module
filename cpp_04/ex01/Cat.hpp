#ifndef CAT_HPP
#define CAT_HPP

#define CAT "Cat"

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	private:
		Brain*	brain_;
		void	newBrain(void);
		void	newBrain(const Brain& target);

	public:
		void	makeSound(void) const;
		void	printBrain(void);
		void	printBrain(int index);

		Cat(void);
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		~Cat(void);
};

#endif