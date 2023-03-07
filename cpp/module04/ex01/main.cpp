#include"Dog.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"

int main()
{
	Animal *array[10];
	for(int i = 0; i < 10; i++)
	{
		if (i % 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	for(int i = 0; i < 10; i++)
		array[i]->makeSound();

	for(int i = 0; i < 10; i++)
		delete array[i];

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Cat *a = new Cat();
	Cat *b = new Cat();

	a->set_idea_from_cat(0, "Idea 0");
	*a = *b;
	b->set_idea_from_cat(0, "Idea 1111111");

	std::cout << "a's [0]" << a->get_idea_from_cat(0) << std::endl;
	std::cout << "b's [0]" << b->get_idea_from_cat(0) << std::endl;

	delete a;
	delete b;

	Animal aa("Animal");
	aa.makeSound();
	return 0;
}