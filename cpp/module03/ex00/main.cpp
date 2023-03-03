#include"ClapTrap.hpp"

int main(void)
{
	ClapTrap a("[THE CLAPTRAP]");
	ClapTrap b = a;

	a.attack("Handsome Jack");
	a.takeDamage(8);
	a.beRepaired(4);
	a.attack("Psycho");
	a.takeDamage(8);
	a.beRepaired(4);
	a.attack("Zer0");

	return 0;
}