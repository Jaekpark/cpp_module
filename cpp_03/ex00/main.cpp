#include "ClapTrap.hpp"

int main(void) {
	ClapTrap::printGame();
	ClapTrap clap("Ash");
	ClapTrap trap("Kaisa");

	clap.printStatus();
	trap.printStatus();

	clap.attack("Kaisa");
	trap.takeDamage(6);

	trap.attack("Ash");
	clap.takeDamage(5);

	clap.beRepaired(3);
	trap.beRepaired(4);
	clap.beRepaired(3);
	trap.beRepaired(4);

	// trap.attack("Ash");
	// clap.takeDamage(10);

	for (int i = 0; i < 10; i++)
		clap.beRepaired(1);
	clap.printStatus();
	trap.printStatus();

	return 0;
}