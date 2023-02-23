#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {

	int amount;
	std::string name;
	std::cout << "How many zombies do you want: ";
	std::cin >> amount;
	std::cout << "Enter the name of zombies: ";
	std::cin >> name;

	Zombie *zombies = zombieHorde(amount, name);
	for(int i = 0; i < amount; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}