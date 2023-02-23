#include"HumanB.hpp"

HumanB::HumanB(std::string name): name(name) {
	this->weapon = NULL;
}

HumanB::~HumanB(void) {

}

void HumanB::set_weapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	std::cout << this->name << " attacks with his " << this->weapon->get_type() << std::endl;
}