#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target) {
	printPanel("Scav Attack", YELLOW);
	if (!ClapTrap::getHp()) {
		std::cout << RED << "[" << ClapTrap::getName() << "] " << "already died." << std::endl;
		return ;
	}
	else if (!ClapTrap::getEp()) {
		std::cout << YELLOW << "[" << ClapTrap::getName() << "] " << "can't attack, not enough Energy." << std::endl;
		return ;
	}
	std::cout << YELLOW;
	std::cout << "[" << ClapTrap::getName() << "] " << "attacks " << "[" << target << "]" 
	" causing " << ClapTrap::getDamage() << " points of damage!" << std::endl;
	ClapTrap::setEp(ClapTrap::getEp() - 1);
	std::cout << EOC;
}

void	ScavTrap::guardGate(void) {
	ClapTrap::printPanel("Mode Changed", YELLOW);
	if (!ClapTrap::getHp()) {
		ClapTrap::printName("already died.", RED);
		return ;
	}
	ClapTrap::printName("Gate Keeper mode activated.", YELLOW);
}

ScavTrap::ScavTrap(void) : ClapTrap() {
	*(const_cast<unsigned int *>(&default_hp_)) = S_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = S_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = S_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = S_NAME;
	printPanel(S_NAME, BLUE);
	printName("Upgrade to ScavTrap", BLUE);
	ClapTrap::setHp(100);
	ClapTrap::setEp(50);
	ClapTrap::setDamage(20);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	*(const_cast<unsigned int *>(&default_hp_)) = S_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = S_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = S_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = S_NAME;
	printPanel(S_NAME, BLUE);
	printName("Upgrade to ScavTrap", BLUE);
	ClapTrap::setHp(100);
	ClapTrap::setEp(50);
	ClapTrap::setDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref) {
	ClapTrap::operator=(ref);
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	ClapTrap::printPanel(DES, YELLOW);
	ClapTrap::printName("ScavTrap goes back to ClapTrap.", RED);
}