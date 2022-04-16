#ifndef WRONGCAT_H
#define WRONGCAT_H

#define W_CAT "Cat"

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:
		void	makeSound(void) const;

		WrongCat(void);
		WrongCat(const WrongCat& ref);
		WrongCat& operator=(const WrongCat& ref);
		~WrongCat(void);
};

#endif