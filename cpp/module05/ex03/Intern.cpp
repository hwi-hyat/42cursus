#include "Intern.hpp"

Intern::Intern(void)
{

}

Intern::Intern(Intern const &object)
{
	(void)object;
}

Intern::~Intern(void)
{

}

Intern &Intern::operator=(Intern const &object)
{
	(void)object;
	return (*this);
}

AForm *Intern::makeForm(std::string const &type, std::string const &name)
{
	if(type == "presidential pardon")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new PresidentialPardonForm(name));
	}
	else if(type == "robotomy request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new RobotomyRequestForm(name));
	}
	else if(type == "shrubbery creation")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(name));
	}
	else
		throw InvalidFormNameException();
}

const char *Intern::InvalidFormNameException::what() const throw()
{
	return ("Invalid form name");
}