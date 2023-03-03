#include"DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_energy_points = ScavTrap::_energy_points;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap " << this->_name << " created by default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name): _name(name)
{
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_energy_points = ScavTrap::_energy_points;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap " << this->_name << " created by default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &object)
{
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	std::cout << "DiamondTrap " << this->_name << " copied" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " is gone" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &object)
{
	std::cout << "Assignment operator for DiamondTrap called." << std::endl;
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am a DiamondTrap named " << this->_name << "!" << std::endl
			<< "And my grandparent ClapTrap's name is " << ClapTrap::_name << "!" << std::endl;
}
