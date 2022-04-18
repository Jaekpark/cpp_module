#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#define S_HP 100
#define S_EP 50
#define S_DAMAGE 20
#define S_NAME "ScavTrap"

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		void	attack(const std::string& target);
		void	guardGate(void);
		
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& ref);
		ScavTrap& operator=(const ScavTrap& ref);
		~ScavTrap(void);
};

#endif