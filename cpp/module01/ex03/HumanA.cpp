#include"HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon) {

}

HumanA::~HumanA(void) {

}

void HumanA::set_weapon(Weapon weapon) {
	this->weapon = weapon;
}

void HumanA::attack(void) {
	std::cout << this->name << " attacks with his " << this->weapon.get_type() << std::endl;
}