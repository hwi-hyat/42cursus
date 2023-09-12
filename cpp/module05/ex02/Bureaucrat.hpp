#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &object);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &object);

		std::string const &getName(void) const;
		int const &getGrade(void) const;

		void increase_grade(void);
		void decrease_grade(void);
		void signForm(AForm &object);
		void executeForm(AForm const &form);
	
		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &object);

#endif

