#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("undefined")
{
	std::cout << "WrongAnimal " << this->_type << " created(Default Constructor)" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal " << this->_type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &object): _type(object._type)
{
	std::cout << "WrongAnimal " << this->_type << " created(Copy Constructor)" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << this->_type << " destoryed" << std::endl;
}

WrongAnimal const &WrongAnimal::operator=(WrongAnimal const &object)
{
	this->_type = object._type;
	return(*this);
}

std::string WrongAnimal::get_type(void) const
{
	return _type;
}

void WrongAnimal::set_type(std::string type)
{
	this->_type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal " << this->_type << " made sound ..." << std::endl;
}
