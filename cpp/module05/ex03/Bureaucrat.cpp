#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("[noname]"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &object): _name(object._name), _grade(object._grade)
{

}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->_name << " left the office" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &object)
{
	*(const_cast<std::string *>(&(this->_name))) = object._name;
	this->_grade = object._grade;

	return *this;
}

std::string const &Bureaucrat::getName(void) const
{
	return this->_name;
}

int const &Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::increase_grade(void)
{
	this->_grade--;
	if(this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrease_grade(void)
{
	this->_grade++;
	if(this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm &object)
{
	try
	{
		object.beSigned(*this);
		std::cout << this->_name << " signed " << object.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << object.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GRADE TOO HIGH";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GRADE TOO LOW";
}

std::ostream &operator<<(std::ostream &str, Bureaucrat const &object)
{
	return str << object.getName() << "(" << object.getGrade() << ")";
}