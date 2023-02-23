#include"Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie *zom = newZombie("siykim");
	zom->announce();
	Zombie *zom2 = newZombie("kimsuhanmoo");
	zom2->announce();
	
	randomChump("Lee");
	delete zom;
	delete zom2;
	return 0;
}