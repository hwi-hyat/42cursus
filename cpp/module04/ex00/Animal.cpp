#include"Animal.hpp"

Animal::Animal(void): _type("undefined")
{
	std::cout << "Animal " << this->_type << " created(Default Constructor)" << std::endl;
}

Animal::Animal(std::string type)
{

}

Animal::Animal(Animal const &object)
{

}

Animal::~Animal(void)
{

}

Animal const &Animal::operator=(Animal const &object)
{

}

std::string const Animal::get_type(void)
{

}

void Animal::set_type(std::string type)
{

}

void Animal::makeSound(void) const
{

}
