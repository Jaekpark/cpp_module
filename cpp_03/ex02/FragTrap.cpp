#include "FragTrap.hpp"

void	FragTrap::highFivesGuys(void) {
	printPanel("High_Five", YELLOW);
	printName("gives a High Five", YELLOW);
}

FragTrap::FragTrap(void) : ClapTrap() {
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = F_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = F_NAME;
	printPanel(F_NAME, BLUE);
	printName("Upgrade to FragTrap", BLUE);
	ClapTrap::setHp(100);
	ClapTrap::setEp(100);
	ClapTrap::setDamage(30);
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = F_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = F_NAME;
	printPanel(F_NAME, BLUE);
	printName("Upgrade to FragTrap", BLUE);
	ClapTrap::setHp(100);
	ClapTrap::setEp(100);
	ClapTrap::setDamage(30);
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref) {
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = F_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = F_NAME;
	printPanel(F_NAME, BLUE);
	printName("Upgrade to FragTrap", BLUE);
	ClapTrap::setHp(100);
	ClapTrap::setEp(100);
	ClapTrap::setDamage(30);
}

FragTrap& FragTrap::operator=(const FragTrap& ref) {
	ClapTrap::operator=(ref);
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = F_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = F_NAME;
	printPanel(F_NAME, BLUE);
	printName("Upgrade to FragTrap", BLUE);
	ClapTrap::setHp(100);
	ClapTrap::setEp(100);
	ClapTrap::setDamage(30);
	return (*this);
}

FragTrap::~FragTrap(void) {
	ClapTrap::printPanel(DES, YELLOW);
	ClapTrap::printName("FragTrap goes back to ClapTrap.", RED);
}