#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap::printGame();
	ClapTrap clap("CLP4P_TP 00");
	ClapTrap trap("CLP4P_TP 01");

	clap.printStatus();
	trap.printStatus();

	clap.attack(trap.getName());
	trap.takeDamage(6);

	trap.attack(clap.getName());
	clap.takeDamage(5);

	clap.beRepaired(3);
	trap.beRepaired(4);
	clap.beRepaired(3);
	trap.beRepaired(4);

	for (int i = 0; i < 10; i++)
		clap.beRepaired(1);
	clap.printStatus();
	trap.printStatus();

	clap.takeDamage(100);
	clap.printStatus();
	return 0;
}