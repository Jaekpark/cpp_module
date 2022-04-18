#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

#define F_HP 100
#define F_EP 100
#define F_DAMAGE 30
#define F_NAME "FragTrap"

class	FragTrap : public ClapTrap {
	public:
		void	highFivesGuys(void);

		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& ref);
		FragTrap& operator=(const FragTrap& ref);
		~FragTrap(void);
};

#endif