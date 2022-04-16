#include "DiamondTrap.hpp"

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

std::string DiamondTrap::getDiamondName(void) {
	return name_;
}

void DiamondTrap::printDiamondName(std::string str, std::string color) {
	std::cout << color;
	std::cout << "[" << name_ << "] " << str << "\t[clap name : " << ClapTrap::name_ << "]" << std::endl;
	std::cout << EOC;
}

void DiamondTrap::whoAmI(void) const {
	printPanel("WhoAmI", YELLOW);
	std::cout << GREEN << "[" << name_ <<"]" << EOC << std::endl;
}

DiamondTrap::DiamondTrap(void) : ClapTrap(std::string(D_NAME) + "_clap_name") {
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = S_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = NAME;
	name_ = NAME;
	printPanel(NAME, BLUE);
	printDiamondName("Upgrade to DiamondTrap", MAGENTA);
	ClapTrap::setHp(default_hp_);
	ClapTrap::setEp(default_ep_);
	ClapTrap::setDamage(default_damage_);
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(std::string(name) + "_clap_name") {
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = S_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = NAME;
	name_ = name;
	printPanel(NAME, BLUE);
	printDiamondName("Upgrade to DiamondTrap", MAGENTA);
	ClapTrap::setHp(default_hp_);
	ClapTrap::setEp(default_ep_);
	ClapTrap::setDamage(default_damage_);
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) : ClapTrap(ref) {
	*(const_cast<unsigned int *>(&default_hp_)) = F_HP;
	*(const_cast<unsigned int *>(&default_ep_)) = S_EP;
	*(const_cast<unsigned int *>(&default_damage_)) = F_DAMAGE;
	*(const_cast<std::string *>(&trap_name_)) = NAME;
	printPanel(NAME, BLUE);
	printDiamondName("Copy DiamondTrap", MAGENTA);
	name_ = ref.getName();
	hp_ = ref.getHp();
	ep_ = ref.getEp();
	damage_ = ref.getDamage();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref) {
	if (this != &ref) {
		name_ = ref.getName();
		hp_ = ref.getHp();
		ep_ = ref.getEp();
		damage_ = ref.getDamage();
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	ClapTrap::printPanel(DES, YELLOW);
	printDiamondName("DiamondTrap goes back to ClapTrap.", RED);
}