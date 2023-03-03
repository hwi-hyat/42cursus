#include"ScavTrap.hpp"

int main(void)
{
	ScavTrap a("[THE SCAVTRAP]");
	ScavTrap b = a;

	a.attack("Handsome Jack");
	a.takeDamage(8);
	a.beRepaired(4);
	a.attack("Psycho");
	a.takeDamage(8);
	a.beRepaired(4);
	a.attack("Zer0");
	a.guardGate();

	return 0;
}