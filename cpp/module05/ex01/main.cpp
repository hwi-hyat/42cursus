#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat biden("biden", 1);
		std::cout << biden << std::endl;

		Form CHIPS("CHIPS", 1, 5);
		std::cout << CHIPS << std::endl;

		biden.signForm(CHIPS);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	try
	{
		Bureaucrat trump("trump", 50);
		std::cout << trump << std::endl;

		Form CHIPS("CHIPS", 1, 5);
		std::cout << CHIPS << std::endl;

		trump.signForm(CHIPS);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}