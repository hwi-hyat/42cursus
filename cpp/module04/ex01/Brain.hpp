#ifndef BRAIN_HPP
# define BRAIN_HPP

# include<iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &object);
		Brain &operator=(const Brain &object);
		~Brain();

		std::string get_idea(int i) const;
		void set_idea(int i, std::string idea);
};

#endif