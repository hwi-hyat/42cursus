#ifndef DOG_HPP
# define DOG_HPP

# include"Animal.hpp"
# include"Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(const Dog &object);
		~Dog();
		Dog &operator=(const Dog &object);
		
		void makeSound() const;
};

#endif
