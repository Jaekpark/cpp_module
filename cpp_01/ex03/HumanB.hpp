#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class	HumanB {
	private:
		std::string	name_;
		Weapon*		weapon_;
		HumanB(void);

	public:
		void	setWeapon(Weapon& weapon);
		void	attack(void) const;
		HumanB(const std::string& name);
		~HumanB(void);
};

#endif
