#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include"AForm.hpp"
#include<fstream>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &object);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &object);

		void execute(Bureaucrat const &executor) const;
};

#endif