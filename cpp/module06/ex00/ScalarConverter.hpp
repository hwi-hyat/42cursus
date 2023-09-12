#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		const std::string	_input;
		double	_double;
		char	_char;
		int		_int;
		float	_float;

		ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& rhs);
	
	public:
		ScalarConverter(std::string mInput);
		ScalarConverter(const ScalarConverter& other);
		virtual ~ScalarConverter();

		void	ToChar() const;
		void	ToInt() const;
		void	ToFloat() const;
		void	ToDouble() const;
		void 	convert() const;
};

#endif
