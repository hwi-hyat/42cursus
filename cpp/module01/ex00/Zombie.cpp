#include"Zombie.hpp"

Zombie::Zombie(void): name("noname") {

}

Zombie::Zombie(std::string name): name(name) {

}

Zombie::~Zombie() {
	std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}