#include"Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog " << this->_type << " created(Default Constructor)" << std::endl;
}

Dog::Dog(const Dog &object): Animal(object._type)
{
	this->_brain = new Brain(*object._brain);
	std::cout << "Dog " << this->_type << " created(Copy Constructor)" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog " << this->_type << " destoryed" << std::endl;
}

Dog &Dog::operator=(const Dog &object)
{
	this->_type = object._type;
	delete this->_brain;
	this->_brain = new Brain(*object._brain);
	std::cout << "Dog assigned" << std::endl;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog " << this->_type << " made sound, woof woof" << std::endl;
}

void Dog::set_idea_from_dog(int i, std::string str) const
{
	this->_brain->set_idea(i, str);
}

std::string Dog::get_idea_from_dog(int i) const
{
	return this->_brain->get_idea(i);
}
