#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include<iostream>
#include"ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &object);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &object);

		std::string const & getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif