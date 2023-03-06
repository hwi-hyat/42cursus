#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include"WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat (void);
		WrongCat (const WrongCat  &object);
		~WrongCat ();
		WrongCat  &operator=(const WrongCat  &object);
		
		void makeSound() const;
};

#endif
