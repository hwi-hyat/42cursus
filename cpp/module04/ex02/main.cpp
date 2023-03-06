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

	// Animal a;
	// a.makeSound();

	return 0;
}