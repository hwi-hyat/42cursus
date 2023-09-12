#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(std::string input)
	:_input(input)
	, _double(std::strtod(input.c_str(), NULL))
	, _char(static_cast<char>(_double))
	, _int(static_cast<int>(_double))
	, _float(static_cast<float>(_double)) {}

ScalarConverter::ScalarConverter(const ScalarConverter& object)
	:_input(object._input)
	, _double(object._double)
	, _char(object._char)
	, _int(object._int)
	, _float(object._float) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& object)
{
	this->_double = object._double;
	this->_char = object._char;
	this->_int = object._int;
	this->_float = object._float;

	return *this;
}

void	ScalarConverter::ToChar() const
{
	std::cout << "char: ";
	if (std::isprint(_char)) {
		std::cout << "'" << _char << "'" << std::endl;
		return;
	}
	if (_double > std::numeric_limits<char>::min() - 1.0
		&& _double < std::numeric_limits<char>::max() + 1.0) {
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "impossible" << std::endl;
}

void	ScalarConverter::ToInt() const
{
	std::cout << "int: ";
	if (_double > std::numeric_limits<int>::min() - 1.0 \
		&& _double < std::numeric_limits<int>::max() + 1.0) {
		std::cout << _int << std::endl;
		return;
	}
	std::cout << "impossible" << std::endl;
}

void	ScalarConverter::ToFloat() const
{
	std::cout << "float: ";
	if (_double != _double) {
		std::cout << "nanf" << std::endl;
		return;
	}
	if (_double == std::numeric_limits<float>::infinity()) {
		std::cout << "inff" << std::endl;
		return;
	}
	if (_double == -std::numeric_limits<float>::infinity()) {
		std::cout << "-inff" << std::endl;
		return;
	}
	if (_double < std::numeric_limits<float>::min() \
		&& _double > std::numeric_limits<float>::max()) {
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1) << _float << "f" << std::endl;
}

void	ScalarConverter::ToDouble() const
{
	std::cout << "double: ";
	if (_double != _double) {
		std::cout << "nan" << std::endl;
		return;
	}
	if (_double == std::numeric_limits<double>::infinity()) {
		std::cout << "inf" << std::endl;
		return;
	}
	if (_double == -std::numeric_limits<double>::infinity()) {
		std::cout << "-inf" << std::endl;
		return;
	}
	std::cout << std::fixed << std::setprecision(1) << _double << std::endl;
}

void	ScalarConverter::convert() const
{
	ToChar();
	ToInt();
	ToFloat();
	ToDouble();
}
