#include"Character.hpp"

Character::Character(void): _name("[default]")
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "character " << this->_name << " created(default)" << std::endl;
}

Character::Character(std::string name): _name(name)
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "character " << this->_name << " created" << std::endl;
}

Character::Character(const Character &object): _name(object._name)
{
	for(int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = object._inventory[i];
	std::cout << "character " << this->_name << " copied" << std::endl;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		delete this->_inventory[i];
	std::cout << "character " << this->_name << " destructed" << std::endl;
}

Character &Character::operator=(const Character &object)
{
	for(int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = object._inventory[i];
		this->_name = object._name;
	std::cout << "character " << this->_name << " assigned" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{	
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "character " << this->_name << " equipped " << m->getType() << std::endl;
			return;
		}
	std::cout << "character " << this->_name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if(idx < 0 || idx > 3)
	{
		std::cout << "you need to access appropriate index" << std::endl;
		return;
	}
	this->_inventory[idx] = NULL;
	std::cout << "character " << this->_name << " unequipped " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << "character " << this->_name << " ";
	this->_inventory[idx]->use(target);
}
