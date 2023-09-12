#include "Form.hpp"

Form::Form(void): _name("[noname]"), _signed(false), _g2s(150), _g2e(150)
{

}

Form::Form(std::string const name, int g2s, int g2e): _name(name), _signed(false), _g2s(g2s), _g2e(g2e)
{

}

Form::Form(Form const &object): _name(object._name), _signed(object._signed), _g2s(object._g2s), _g2e(object._g2e)
{

}

Form::~Form(void)
{
	std::cout << this->_name << " deleted" << std::endl;
}

Form &Form::operator=(Form const &object)
{
	*(const_cast<std::string *>(&(this->_name))) = object._name;
	*(const_cast<int *>(&(this->_g2s))) = object._g2s;
	*(const_cast<int *>(&(this->_g2e))) = object._g2e;
	this->_signed = object._signed;

	return *this;
}

std::string const &Form::getName(void) const
{
	return this->_name;
}

bool Form::isItSigned(void) const
{
	return this->_signed;
}

int const &Form::getGradeToSign(void) const
{
	return this->_g2s;
}

int const &Form::getGradeToExecute(void) const
{
	return this->_g2e;
}

void Form::beSigned(Bureaucrat const &object)
{
	if(object.getGrade() > this->_g2s)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "GRADE TOO HIGH";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "GRADE TOO LOW";
}

std::ostream& operator<<(std::ostream& str, const Form& object)
{
	str << object.getName() << "(grade to sign: " << object.getGradeToSign() << ", grade to execute: " << object.getGradeToExecute() << ", ";
	if(object.isItSigned())
		str << "signed)";
	else
		str << "not signed)";

	return str;
}