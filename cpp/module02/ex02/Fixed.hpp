#ifndef FIXED_HPP
# define FIXED_HPP

# include<iostream>
# include<cmath>

class Fixed {
	private:
		int _value;
		static const int _fractional;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed(Fixed const &object);

		Fixed &operator=(Fixed const &object);
		Fixed operator+(Fixed const &object) const;
		Fixed operator-(Fixed const &object) const;
		Fixed operator*(Fixed const &object) const;
		Fixed operator/(Fixed const &object) const;
		bool operator==(Fixed const &object) const;
		bool operator!=(Fixed const &object) const;
		bool operator<=(Fixed const &object) const;
		bool operator>=(Fixed const &object) const;
		bool operator>(Fixed const &object) const;
		bool operator<(Fixed const &object) const;
		
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int value);
		Fixed operator--(int value);

		static const Fixed &min(Fixed const &a, Fixed const &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fp);

#endif