#ifndef FIXED_HPP
# define FIXED_HPP

# include<iostream>

class Fixed {
	private:
		int _value;
		static const int _fractional;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &object);
		Fixed &operator=(Fixed const &object);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif