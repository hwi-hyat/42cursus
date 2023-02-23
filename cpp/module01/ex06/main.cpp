#include"Harl.hpp"

int main(int argc, char **argv) {
	Harl harlharl;

	if(argc != 2)
		harlharl.whatthehellisproblemwithyou();
	else 
		harlharl.complain(argv[1]);
	return 0;
}