#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->get_type() << " " << std::endl;
	std::cout << i->get_type() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "-------------------------" << std::endl;

	const WrongAnimal* wrong = new WrongCat();

	std::cout << wrong->get_type() << " " << std::endl;

	wrong->makeSound();

	delete wrong;
	
	return 0;
}