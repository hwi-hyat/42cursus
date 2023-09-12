#include "AForm.hpp"

AForm::AForm(void): _name("[noname]"), _signed(false), _g2s(150), _g2e(150)
{

}

AForm::AForm(std::string const name, int g2s, int g2e): _name(name), _signed(false), _g2s(g2s), _g2e(g2e)
{

}

AForm::AForm(AForm const &object): _name(object._name), _signed(object._signed), _g2s(object._g2s), _g2e(object._g2e)
{

}

AForm::~AForm(void)
{
	std::cout << this->_name << " deleted" << std::endl;
}

AForm &AForm::operator=(AForm const &object)
{
	*(const_cast<std::string *>(&(this->_name))) = object._name;
	*(const_cast<int *>(&(this->_g2s))) = object._g2s;
	*(const_cast<int *>(&(this->_g2e))) = object._g2e;
	this->_signed = object._signed;

	return *this;
}

std::string const &AForm::getName(void) const
{
	return this->_name;
}

bool AForm::isItSigned(void) const
{
	return this->_signed;
}

int const &AForm::getGradeToSign(void) const
{
	return this->_g2s;
}

int const &AForm::getGradeToExecute(void) const
{
	return this->_g2e;
}

void AForm::beSigned(Bureaucrat const &object)
{
	if(object.getGrade() > this->_g2s)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "GRADE TOO HIGH";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "GRADE TOO LOW";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "FORM IS NOT SIGNED";
}

std::ostream& operator<<(std::ostream& str, const AForm& object)
{
	str << object.getName() << "(grade to sign: " << object.getGradeToSign() << ", grade to execute: " << object.getGradeToExecute() << ", ";
	if(object.isItSigned())
		str << "signed)";
	else
		str << "not signed)";

	return str;
}