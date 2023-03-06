#include "AMateria.hpp"

AMateria::AMateria(void): _type("(default)")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &object): _type(object._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &object)
{
	this->_type = object._type;
	return (*this);
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << " used " << this->_type << " to "<< target.getName() << std::endl;
}
