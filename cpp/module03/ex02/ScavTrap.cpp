#include"ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hp = 100;
	this->_energy_points = 50;
	this->_damage = 20;
	std::cout << "ScavTrap " << this->_name << " created by default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name)
{
	this->_hp = 100;
	this->_energy_points = 50;
	this->_damage = 20;
	std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &object)
{
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	std::cout << "ScavTrap " << this->_name << " copied" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " is gone" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &object)
{
	std::cout << "Assignment operator for ScavTrap called." << std::endl;
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if(this->_hp <= 0)
		std::cout << this->_name << " was gone, what are you talkin' about?" << std::endl;
	else if(!this->_energy_points)
		std::cout << this->_name << " doesn't have enough energy to attack" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	if(this->_hp <= 0)
		std::cout << this->_name << " was gone, what are you talkin' about?" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " guards the gate" << std::endl;
}
