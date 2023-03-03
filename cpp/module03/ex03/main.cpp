#include"DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a("[THE DIAMONDTRAP]");
	DiamondTrap b = a;

	std::cout << a.get_name() << std::endl
			<< a.get_hp() << std::endl
			<< a.get_energy_points() << std::endl
			<< a.get_damage() << std::endl;

	a.attack("Handsome Jack");
	std::cout << std::endl;
	a.takeDamage(8);
	std::cout << std::endl;
	a.beRepaired(4);
	std::cout << std::endl;
	a.attack("Psycho");
	std::cout << std::endl;
	a.takeDamage(8);
	std::cout << std::endl;
	a.beRepaired(4);
	std::cout << std::endl;
	a.attack("Zer0");
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;

	return 0;
}