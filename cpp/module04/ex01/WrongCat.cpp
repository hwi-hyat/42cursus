#include"WrongCat.hpp"

WrongCat ::WrongCat (void): WrongAnimal("WrongCat ")
{
	std::cout << "WrongCat " << this->_type << " created(Default Constructor)" << std::endl;
}

WrongCat ::WrongCat (const WrongCat  &object): WrongAnimal(object._type)
{
	std::cout << "WrongCat " << this->_type << " created(Copy Constructor)" << std::endl;
}

WrongCat ::~WrongCat ()
{
	std::cout << "WrongCat " << this->_type << " destoryed" << std::endl;
}

WrongCat  &WrongCat ::operator=(const WrongCat  &object)
{
	this->_type = object._type;
	return(*this);
}

void WrongCat ::makeSound() const
{
	std::cout << "WrongCat " << this->_type << " made sound, meow" << std::endl;
}
