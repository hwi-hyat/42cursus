#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include"AForm.hpp"
#include<fstream>
#include<random>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &object);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &object);

		void execute(Bureaucrat const &executor) const;
};

#endif