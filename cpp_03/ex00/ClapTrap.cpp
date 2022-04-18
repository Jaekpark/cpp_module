#include "ClapTrap.hpp"

std::string ClapTrap::getName(void) const {
	return this->name_;
}

unsigned int ClapTrap::getHp(void) const {
	return this->hp_;
}
unsigned int ClapTrap::getEp(void) const {
	return this->ep_;
}
unsigned int ClapTrap::getDamage(void) const {
	return this->damage_;
}

void	ClapTrap::setHp(unsigned int hp) {
	this->hp_ = hp;
}

void	ClapTrap::setEp(unsigned int ep) {
	this->ep_ = ep;
}

void	ClapTrap::setDamage(unsigned int damage) {
	this->damage_ = damage;
}

void	ClapTrap::attack(const std::string& target) {
	printPanel("Clap Attack", YELLOW);
	if (!this->hp_) {
		std::cout << RED << "[" << name_ << "] " << "already died." << std::endl;
		return ;
	}
	else if (!this->ep_) {
		std::cout << YELLOW << "[" << name_ << "] " << "can't attack, not enough Energy." << std::endl;
		return ;
	}
	std::cout << YELLOW;
	std::cout << "[" << name_ << "] " << "attacks " << "[" << target << "]" 
	" causing " << this->damage_ << " points of damage!" << std::endl;
	ep_--;
	std::cout << EOC;
}

void ClapTrap::takeDamage(unsigned int amount) {
	printPanel(DAMAGE, CYAN);
	if (!hp_) {
		printName("already died.", RED);
		return ;
	}
	else if (static_cast<int>(hp_ - amount) <= 0) {
		printName("has been slain.", RED);
		hp_ = 0;
		return ;
	}
	std::cout << CYAN;
	std::cout << "[" << name_ << "] was damaged by " << amount;
	std::cout << "\t[" << hp_ << " - " << amount << " = ";
	hp_ -= amount;
	std::cout << hp_ << "]" << EOC << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->ep_) {
		printPanel(REPAIR, BLUE);
		printName("Can't repair, not enough Energy.", BLUE);
		return ;
	}
	else if (!this->hp_) {
		printPanel(REPAIR, BLUE);
		printName("already died.", RED);
		return ;
	}
	printPanel(REPAIR, BLUE);
	std::cout << GREEN;
	std::cout << "[" << name_ << "] repaired " << amount << "\t[" << amount <<  " + " << hp_;
	this->ep_--;
	this->hp_ += amount;
	if (hp_ > default_hp_)
		hp_ = default_hp_;
	std::cout << " = " << hp_  << "]" << EOC << std::endl;
}

void	ClapTrap::printPanel(std::string str, std::string color) const {
	std::cout << color << "[" << std::setw(WIDTH) << str << "]";
	std::cout << "\t" << EOC;
}

void	ClapTrap::printStatus(void) const {
	printPanel(STATUS, MAGENTA);
	printName("Status", MAGENTA);
	std::cout << std::setw(WIDTH) << GREEN << "NAME\t:\t" << name_ << std::endl;
	std::cout << std::setw(WIDTH) << YELLOW << "HP\t:\t" << hp_ << std::endl;
	std::cout << std::setw(WIDTH) << BLUE << "EP\t:\t" << ep_ << std::endl;
	std::cout << std::setw(WIDTH) << CYAN << "DAMAGE\t:\t" << damage_ << std::endl << std::endl << EOC;
}

void	ClapTrap::printName(std::string str, std::string color) const {
	std::cout << color;
	std::cout << "[" << this->name_ << "] " << str << std::endl;
	std::cout << EOC;
}

ClapTrap::ClapTrap(void) 
	: name_(D_NAME), hp_(D_HP), ep_(D_EP), damage_(D_DAMAGE), default_hp_(D_HP), default_ep_(D_EP), default_damage_(D_DAMAGE) {
	printPanel(D_NAME, YELLOW);
	printName("Welcome to Borderlands.", GREEN);
}

ClapTrap::ClapTrap(const std::string &name)
	: name_(name), hp_(D_HP), ep_(D_EP), damage_(D_DAMAGE), default_hp_(D_HP), default_ep_(D_EP), default_damage_(D_DAMAGE) {
	printPanel(D_NAME, YELLOW);
	printName("Welcome to Borderlands.", GREEN);
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref) {
	if (this != &ref) {
		name_ = ref.getName();
		hp_ = ref.getHp();
		ep_ = ref.getEp();
		damage_ = ref.getDamage();
		default_hp_ = D_HP;
		default_ep_ = D_EP;
		default_damage_ = D_DAMAGE;
	}
	printPanel(D_NAME, YELLOW);
	printName("Welcome to Borderlands.", GREEN);
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &ref) 
	: name_(ref.getName()), hp_(ref.getHp()), ep_(ref.getEp()), damage_(ref.getDamage())
	, default_damage_(ref.default_damage_), default_ep_(ref.default_ep_), default_hp_(ref.default_hp_) {
	printPanel(D_NAME, YELLOW);
	printName("Welcome to Borderlands.", GREEN);
}

ClapTrap::~ClapTrap(void) {
	printPanel(DES, YELLOW);
	printName("Deleted.", RED);
}