#include"Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed(void): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const& object) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = object.getRawBits();
}

Fixed &Fixed::operator=(Fixed const &object) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = object.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

