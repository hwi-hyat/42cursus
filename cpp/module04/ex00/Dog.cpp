#include"Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog " << this->_type << " created(Default Constructor)" << std::endl;
}

Dog::Dog(const Dog &object): Animal(object._type)
{
	std::cout << "Dog " << this->_type << " created(Copy Constructor)" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog " << this->_type << " destoryed" << std::endl;
}

Dog &Dog::operator=(const Dog &object)
{
	this->_type = object._type;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog " << this->_type << " made sound, woof woof" << std::endl;
}
