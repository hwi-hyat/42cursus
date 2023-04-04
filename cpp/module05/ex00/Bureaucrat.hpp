#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

		std::string const getName() const;
		int const getGrade() const;
	
};




#endif