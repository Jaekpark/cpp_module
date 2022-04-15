#ifndef ZOMBIE_H
#define ZOMBIE_H

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define EOC "\033[0m"
#define BOLD "\033[1m"

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	_name;
		Zombie(void);
	public:
		void			setZombieName( std::string name );
		void			announce( void ) const;
		static Zombie*	zombieHorde( int N, std::string name );
		Zombie( std::string name );
		~Zombie( void );
};

#endif
