#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include"ScavTrap.hpp"
# include"FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &object);
		~DiamondTrap(void);

		DiamondTrap &operator=(DiamondTrap const &object);

		void whoAmI(void);
};

#endif