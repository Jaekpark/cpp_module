#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define NAME "DiamondTrap"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name_;

	public:
		void whoAmI(void) const;
		std::string getDiamondName(void);
		void printDiamondName(std::string str, std::string color);
		void attack(const std::string& target);
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& ref);
		DiamondTrap& operator=(const DiamondTrap& ref);
		~DiamondTrap(void);
};

#endif