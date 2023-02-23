#include"Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::Zombie(void) {
	this->name = "";
}

Zombie::~Zombie() {
	std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name = name;
}