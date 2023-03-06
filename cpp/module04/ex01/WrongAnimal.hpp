#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include<iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &object);
		~WrongAnimal(void);

		WrongAnimal const &operator=(WrongAnimal const &object);

		std::string get_type(void) const;
		void set_type(std::string type);

		void makeSound(void) const;
};

#endif
