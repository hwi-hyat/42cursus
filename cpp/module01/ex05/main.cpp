#include"Harl.hpp"

int main(int argc, char **argv) {
	Harl harlharl;
	if(argc != 2) {
		harlharl.whatthehellisproblemwithyou();
		return 0;
	}

	harlharl.complain(argv[1]);
	std::cout << "what";
	return 0;
}