#include"FragTrap.hpp"

int main(void)
{
	FragTrap a("[THE FRAGTRAP]");
	FragTrap b = a;

	a.attack("Handsome Jack");
	a.takeDamage(8);
	a.beRepaired(4);
	a.attack("Psycho");
	a.takeDamage(8);
	a.beRepaired(4);
	a.attack("Zer0");
	a.highFivesGuys();

	return 0;
}