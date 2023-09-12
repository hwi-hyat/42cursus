#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include"AForm.hpp"
#include<fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &object);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &object);

		void execute(Bureaucrat const &executor) const;

		class CouldNotOpenFileException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif