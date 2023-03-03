#include"HumanB.hpp"

HumanB::HumanB(void): name("noname"), weapon(NULL) {

}

HumanB::HumanB(std::string name): name(name), weapon(NULL) {
	
}

HumanB::~HumanB(void) {

}

void HumanB::set_weapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	std::cout << this->name << " attacks with his " << this->weapon->get_type() << std::endl;
}