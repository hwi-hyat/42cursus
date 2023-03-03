#include"ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("noname"), _hp(10), _energy_points(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created by default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): _name(name), _hp(10), _energy_points(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &object): _name(object.get_name()), _hp(object.get_hp()), _energy_points(object.get_energy_points()), _damage(object.get_damage())
{
	std::cout << "ClapTrap " << this->_name << " copied" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " is gone" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if(this->_hp <= 0)
		std::cout << this->_name << " was gone, what are you talkin' about?" << std::endl;
	else if(!this->_energy_points)
		std::cout << this->_name << " doesn't have enough energy to attack" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hp <= 0)
	{
		std::cout << this->_name << "was gone, what are you talkin' about?" << std::endl;
		return;
	}

	this->_hp -= amount;
	if(this->_hp > 0)
		std::cout << "ClapTrap " << this->_name << " took " << amount << " damage!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_hp <= 0)
	{
		std::cout << this->_name << " was gone, what are you talkin' about?" << std::endl;
		return;
	}

	if(!this->_energy_points)
		std::cout << this->_name << " doesn't have enough energy to repair itself" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " repairs " << amount << " points!" << std::endl;
	}
}


std::string const	ClapTrap::get_name(void) const
{
	return this->_name;
}

int const			ClapTrap::get_hp(void) const
{
	return this->_hp;
}

int const			ClapTrap::get_energy_points(void) const
{
	return this->_energy_points;
}

int const			ClapTrap::get_damage(void) const
{
	return this->_damage;
}

void				ClapTrap::set_name(std::string const &name)
{
	this->_name = name;
}

void				ClapTrap::set_hp(int const &value)
{
	this->_hp = value;
}

void				ClapTrap::set_energy_points(int const &value)
{
	this->_energy_points = value;
}

void				ClapTrap::set_damage(int const &value)
{
	this->_damage = value;
}


ClapTrap &ClapTrap::operator=(ClapTrap const &object)
{
	std::cout << "Assignment operator for ClapTrap called." << std::endl;
	this->_name = object.get_name();
	this->_hp = object.get_hp();
	this->_energy_points = object.get_energy_points();
	this->_damage = object.get_damage();
	return (*this);
}
