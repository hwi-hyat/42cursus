#include"FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hp = 100;
	this->_energy_points = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << this->_name << " created by default constructor" << std::endl;
}

FragTrap::FragTrap(std::string const &name)
{
	this->_hp = 100;
	this->_energy_points = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

FragTrap::FragTrap(FragTrap const &object)
{
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	std::cout << "FragTrap " << this->_name << " copied" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " is gone" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &object)
{
	std::cout << "Assignment operator for FragTrap called." << std::endl;
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if(this->_hp <= 0)
		std::cout << this->_name << " was gone, what are you talkin' about?" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " HIGHFIVES!" << std::endl;
}
