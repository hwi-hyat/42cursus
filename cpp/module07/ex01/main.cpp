#include "iter.hpp"

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };

    iter(array, 5, print);
    std::cout << std::endl;

    std::string str_arr[] = { "Hello", "World", "!" };
    
    iter(str_arr, 3, print);
    std::cout << std::endl;

    return 0;
}