#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", 72, 45), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &object)
: AForm("RobotomyRequestForm", 72, 45), _target(object._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &object)
{
	AForm::operator=(object);
	this->_target = object._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->isItSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
		
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	int random = dis(gen);
	if(random == 0)
	{
		std::cout << "* DRILLING SOUNDS BUZZIN' *" << std::endl;
		std::cout << this->_target << " robotomized" << std::endl;
	}
	else
		std::cout << "Failed to robotomize " << this->_target << std::endl;
}
