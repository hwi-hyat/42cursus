#include"Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed(void): _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _value(value << Fixed::_fractional) {
	std::cout << "Int constructor called" << std::endl;

}

Fixed::Fixed(const float value): _value(static_cast<int>(roundf(value * (1 << Fixed::_fractional)))) {
	std::cout << "Float constructor called" << std::endl;
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

Fixed Fixed::operator+(Fixed const &object) const
{
	Fixed result(this->toFloat() + object.toFloat());
	return (result);
}

Fixed Fixed::operator-(Fixed const &object) const
{
	Fixed result(this->toFloat() - object.toFloat());
	return (result);
}

Fixed Fixed::operator*(Fixed const &object) const
{
	Fixed result(this->toFloat() * object.toFloat());
	return (result);
}

Fixed Fixed::operator/(Fixed const &object) const
{
	Fixed result(this->toFloat() / object.toFloat());
	return (result);
}

bool	Fixed::operator==(const Fixed &object) const
{
	return (this->toFloat() == object.toFloat());
}

bool	Fixed::operator!=(const Fixed &object) const
{
	return (this->toFloat() != object.toFloat());
}

bool	Fixed::operator<=(const Fixed &object) const
{
	return (this->toFloat() <= object.toFloat());
}

bool	Fixed::operator>=(const Fixed &object) const
{
	return (this->toFloat() >= object.toFloat());
}

bool	Fixed::operator<(const Fixed &object) const
{
	return (this->toFloat() < object.toFloat());
}

bool	Fixed::operator>(const Fixed &object) const
{
	return (this->toFloat() > object.toFloat());
}

Fixed &Fixed::operator++(void)
{
	++(this->_value);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--(this->_value);
	return (*this);
}

Fixed Fixed::operator++(int value)
{
	Fixed tmp = *this;
	++(this->_value);
	return (tmp);
}

Fixed Fixed::operator--(int value)
{
	Fixed tmp = *this;
	--(this->_value);
	return (tmp);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return b;
	return a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a < b)
		return b;
	return a;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(this->_value) / (1 << Fixed::_fractional));
}

int Fixed::toInt( void ) const {
	return (_value >> Fixed::_fractional);
}

std::ostream &operator<<(std::ostream &str, Fixed const &fp) {
	return (str << fp.toFloat());
}
