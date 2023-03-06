#include"Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat " << this->_type << " created(Default Constructor)" << std::endl;
}

Cat::Cat(const Cat &object): Animal(object._type)
{
	this->_brain = new Brain(*object._brain);
	std::cout << "Cat " << this->_type << " created(Copy Constructor)" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat " << this->_type << " destoryed" << std::endl;
}

Cat &Cat::operator=(const Cat &object)
{
	this->_type = object._type;
	delete this->_brain;
	this->_brain = new Brain(*object._brain);
	std::cout << "Cat assigned" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat " << this->_type << " made sound, meow" << std::endl;
}
