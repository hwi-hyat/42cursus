#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include<iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &object);
		virtual ~Animal(void);

		Animal const &operator=(Animal const &object);

		std::string get_type(void) const;
		void set_type(std::string type);

		virtual void makeSound(void) const;
};

#endif
