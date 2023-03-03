#ifndef HUMANB_HPP
# define HUMANB_HPP

# include"Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void attack(void);
		void set_weapon(Weapon &weapon);
};

#endif