#include "ScavTrap.hpp"

int main(void) {
	ScavTrap clap("Ash");
	ScavTrap trap("Kaisa");

	clap.printStatus();
	trap.printStatus();

	clap.attack("Kaisa");
	trap.takeDamage(6);

	trap.attack("Ash");
	clap.takeDamage(5);

	clap.guardGate();
	trap.guardGate();
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