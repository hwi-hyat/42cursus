#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat james("james", 1);
		std::cout << james << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat kane("kane", 1);
		kane.increase_grade();
		std::cout << kane << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat helly("helly", 150);

		std::cout << helly << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat helly("helly", 150);
		helly.decrease_grade();
		std::cout << helly << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}