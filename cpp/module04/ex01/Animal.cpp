#include"Animal.hpp"

Animal::Animal(void): _type("undefined")
{
	std::cout << "Animal " << this->_type << " created(Default Constructor)" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal " << this->_type << " created" << std::endl;
}

Animal::Animal(Animal const &object): _type(object._type)
{
	std::cout << "Animal " << this->_type << " created(Copy Constructor)" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destoryed" << std::endl;
}

Animal const &Animal::operator=(Animal const &object)
{
	this->_type = object._type;
	return(*this);
}

std::string Animal::get_type(void) const
{
	return _type;
}

void Animal::set_type(std::string type)
{
	this->_type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal " << this->_type << " made sound ..." << std::endl;
}
