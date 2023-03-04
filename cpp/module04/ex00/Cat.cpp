#include"Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat " << this->_type << " created(Default Constructor)" << std::endl;
}

Cat::Cat(const Cat &object): Animal(object._type)
{
	std::cout << "Cat " << this->_type << " created(Copy Constructor)" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat " << this->_type << " destoryed" << std::endl;
}

Cat &Cat::operator=(const Cat &object)
{
	this->_type = object._type;
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat " << this->_type << " made sound, meow" << std::endl;
}
