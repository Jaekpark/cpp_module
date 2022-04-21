#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#define W_CAT "Wrong Cat"

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