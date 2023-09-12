#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_form(AForm *form, Bureaucrat &beau)
{
	std::cout << *form << std::endl;
	std::cout << beau << std::endl;

	beau.signForm(*form);
	beau.executeForm(*form);

	delete form;

	std::cout << std::endl;
}

int main(void)
{
	Intern newbie;

	Bureaucrat beau("chief", 1);
	std::cout << beau << std::endl;

	test_form(newbie.makeForm("presidential pardon", "president"), beau);
	test_form(newbie.makeForm("robotomy request", "robot"), beau);
	test_form(newbie.makeForm("shrubbery creation", "shrub"), beau);

	return 0;
}