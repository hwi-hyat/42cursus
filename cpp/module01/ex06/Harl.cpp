#include"Harl.hpp"

Harl::Harl(void) {

}

Harl::~Harl(void) {

}

void Harl::debug(void) {
	std::cout << "DEBUG: I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::whatthehellisproblemwithyou(void) {
	std::cout << "Probably complaining about insignificant problems" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for(int i = 0; i < 4; i++) {
		if(level_arr[i] == level) {
			index = i;
			break;
		}
	}

	switch(index) {
		case 0: (this->*f[0])();
		case 1: (this->*f[1])();
		case 2: (this->*f[2])();
		case 3: (this->*f[3])(); break;
		default: (this->Harl::whatthehellisproblemwithyou)();
	}
}
