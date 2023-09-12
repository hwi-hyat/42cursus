#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &object);
		~Intern(void);

		Intern &operator=(Intern const &object);

		AForm *makeForm(std::string const &type, std::string const &name);

		class InvalidFormNameException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif