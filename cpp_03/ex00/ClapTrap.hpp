#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define EOC "\033[0m"
#define BOLD "\033[1m"
#define ANNOUNCE "Announcement"
#define CONS "Constructor"
#define DES "Destructor"
#define ATTACK "Attack"
#define REPAIR "Repair"
#define DAMAGE "Damaged"
#define STATUS "Status"
#define D_NAME "default"
#define D_HP 10
#define D_EP 10
#define D_DAMAGE 0
#define WIDTH 15

#include <iostream>
#include <string>
#include <iomanip>

class ClapTrap {
	private:
		std::string name_;
		const unsigned int default_hp_;
		const unsigned int default_ep_;
		const unsigned int default_damage_;
		unsigned int hp_;
		unsigned int ep_;
		unsigned int damage_;

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	getName(void) const;
		unsigned int getHp(void) const;
		unsigned int getEp(void) const;
		unsigned int getDamage(void) const;
		void	printStatus(void) const;
		void	printName(std::string str, std::string color) const;
		void	printPanel(std::string str, std::string color) const;
		void	setHp(unsigned int hp);
		void	setEp(unsigned int ep);
		void	setDamage(unsigned int damage);

		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap& operator=(const ClapTrap &ref);
		ClapTrap(const ClapTrap &ref);
		~ClapTrap(void);
};

#endif