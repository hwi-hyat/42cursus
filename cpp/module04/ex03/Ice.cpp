#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "ice created(default)" << std::endl;
}

Ice::Ice(const Ice &object): AMateria(object)
{
	std::cout << "ice created(copy)" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "ice destroyed" << std::endl;
}

Ice &Ice::operator=(const Ice &object)
{
	this->_type = object._type;
	std::cout << "ice assigned" << std::endl;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}