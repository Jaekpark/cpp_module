#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap clap("Ash");
	DiamondTrap trap("Kaisa");

	clap.printStatus();
	trap.printStatus();

	clap.attack("Kaisa");
	trap.takeDamage(6);

	trap.attack("Ash");
	clap.takeDamage(5);

	clap.highFivesGuys();
	trap.highFivesGuys();
	clap.beRepaired(3);
	trap.beRepaired(4);
	clap.beRepaired(3);
	trap.beRepaired(4);

	clap.whoAmI();
	trap.whoAmI();
	// trap.attack("Ash");
	// clap.takeDamage(10);

	for (int i = 0; i < 10; i++)
		clap.beRepaired(1);
	clap.printStatus();
	trap.printStatus();

	return 0;
}