#ifndef CAT_H
#define CAT_H

#define CAT "Cat"

#include "Animal.hpp"

class	Cat : public Animal {
	public:
		void	makeSound(void) const;

		Cat(void);
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		~Cat(void);
};

#endif