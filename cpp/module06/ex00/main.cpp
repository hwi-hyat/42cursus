#include "ScalarConverter.hpp"

int	main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << "Requires one argument" << std::endl;
		return 1;
	}
    else if (argc > 2) {
        std::cout << "Too many arguments" << std::endl;
        return 1;
    }

	ScalarConverter	converter(argv[1]);
	converter.convert();
}
