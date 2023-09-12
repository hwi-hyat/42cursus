#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	
		Bureaucrat biden("biden", 1);
		std::cout << biden << std::endl;

		ShrubberyCreationForm shrub("s-form");
		std::cout << shrub << std::endl;

		biden.signForm(shrub);
		std::cout << shrub << std::endl;

		biden.executeForm(shrub);

	std::cout << std::endl << std::endl;

	
		Bureaucrat trump("trump", 50);
		std::cout << trump << std::endl;

		RobotomyRequestForm robo("r-form");
		std::cout << robo << std::endl;

		trump.signForm(robo);

		trump.executeForm(robo);

	std::cout << std::endl << std::endl;

	
		Bureaucrat powell("powell", 10);
		std::cout << powell << std::endl;

		PresidentialPardonForm pre("p-form");
		std::cout << pre << std::endl;

		powell.signForm(pre);

		powell.executeForm(pre);

	std::cout << std::endl << std::endl;


	return 0;
}