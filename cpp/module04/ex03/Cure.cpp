#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure created(default)" << std::endl;
}

Cure::Cure(const Cure &object): AMateria(object)
{
	std::cout << "Cure created(copy)" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed" << std::endl;
}

Cure &Cure::operator=(const Cure &object)
{
	this->_type = object._type;
	std::cout << "Cure assigned" << std::endl;
	return (*this);
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}