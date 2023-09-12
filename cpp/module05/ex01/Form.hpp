#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include"Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _g2s;
		int const _g2e;

	public:
		Form(void);
		Form(std::string const name, int grade_to_sign, int grade_to_execute);
		Form(Form const &object);
		~Form(void);

		Form &operator=(Form const &object);

		std::string const &getName(void) const;
		bool isItSigned(void) const;
		int const &getGradeToSign(void) const;
		int const &getGradeToExecute(void) const;

		void beSigned(Bureaucrat const &object);

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

std::ostream& operator<<(std::ostream& str, const Form& object);

#endif