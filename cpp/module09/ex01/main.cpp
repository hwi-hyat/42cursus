#include"RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    std::string str(argv[1]);
    RPN rpn;

    try
    {
        rpn.calculate(str);
    }
    catch(std::exception &e)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    return 0;
}