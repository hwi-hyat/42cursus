#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include<iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _hp;
		int _energy_points;
		int _damage;
	
	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &object);
		~ClapTrap(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		std::string const	get_name(void) const;
		int const			get_hp(void) const;
		int const			get_energy_points(void) const;
		int const			get_damage(void) const;
		void				set_name(std::string const &name);
		void				set_hp(int const &value);
		void				set_energy_points(int const &value);
		void				set_damage(int const &value);

		ClapTrap &operator=(ClapTrap const &object);
};

#endif