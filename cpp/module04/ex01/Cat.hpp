#ifndef CAT_HPP
# define CAT_HPP

# include"Animal.hpp"
# include"Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(const Cat &object);
		~Cat();
		Cat &operator=(const Cat &object);
		
		void makeSound() const;
		void set_idea_from_cat(int i, std::string str) const;
		std::string get_idea_from_cat(int i) const;
};

#endif
