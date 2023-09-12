#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include"Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _g2s;
		int const _g2e;

	public:
		AForm(void);
		AForm(std::string const name, int grade_to_sign, int grade_to_execute);
		AForm(AForm const &object);
		virtual ~AForm(void);

		AForm &operator=(AForm const &object);

		std::string const &getName(void) const;
		bool isItSigned(void) const;
		int const &getGradeToSign(void) const;
		int const &getGradeToExecute(void) const;

		void beSigned(Bureaucrat const &object);
		virtual void execute(Bureaucrat const &executor) const = 0;
		void check_execute(Bureaucrat const &executor) const;

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

		class FormNotSignedException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& str, const AForm& object);

#endif