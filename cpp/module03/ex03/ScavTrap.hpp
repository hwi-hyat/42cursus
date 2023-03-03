#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include"ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &object);
		virtual ~ScavTrap(void);

		ScavTrap &operator=(ScavTrap const &object);

		void attack(const std::string& target);
		void guardGate(void);
};

#endif