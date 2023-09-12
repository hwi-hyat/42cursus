#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", 25, 5), _target("default")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &object)
: AForm("PresidentialPardonForm", 25, 5), _target(object._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &object)
{
	AForm::operator=(object);
	this->_target = object._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->isItSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
