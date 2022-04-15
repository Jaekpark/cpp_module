#ifndef WEAPON_H
#define WEAPON_H

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define EOC "\033[0m"
#define BOLD "\033[1m"

#include <string>
#include <iostream>

class Weapon {
	private:
		std::string type_;

	public:
		const std::string	&getType(void) const;
		void				setType(const std::string& type);
		Weapon(const std::string& type);
		~Weapon();
};

#endif