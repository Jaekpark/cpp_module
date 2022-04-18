#include "DiamondTrap.hpp"

int main(void) {
	ClapTrap::printGame();
	DiamondTrap clap("DM4D-TP 00");
	DiamondTrap trap("DM4D-TP 01");

	clap.printStatus();
	trap.printStatus();

	clap.attack(trap.getName());
	trap.takeDamage(6);

	trap.attack(clap.getName());
	clap.takeDamage(5);

	clap.highFivesGuys();
	trap.highFivesGuys();
	clap.beRepaired(3);
	trap.beRepaired(4);
	clap.beRepaired(3);
	trap.beRepaired(4);

	clap.whoAmI();
	trap.whoAmI();

	for (int i = 0; i < 10; i++)
		clap.beRepaired(1);
	clap.printStatus();
	trap.printStatus();

	clap.takeDamage(100);
	clap.printStatus();

	return 0;
}