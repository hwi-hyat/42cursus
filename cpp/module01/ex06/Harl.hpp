#ifndef Harl_HPP
# define Harl_HPP

# include<iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl(void);
		~Harl(void);
		void whatthehellisproblemwithyou(void);
		void complain(std::string level);
};

#endif