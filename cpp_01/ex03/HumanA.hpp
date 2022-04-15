#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class	HumanA {
	private:
		std::string name_;
		Weapon &weapon_;

	public:
		void	attack(void) const;
		HumanA(const std::string& name, Weapon &weapon);
		~HumanA(void);
};

#endif