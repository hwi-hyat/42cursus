#include"PmergeMe.hpp"
#include<ctime>

int main(int argc, char **argv)
{
    PmergeMe p;
    p.show_and_load_args(argc, argv);
    
    clock_t start_time = clock();
    p.sort_vector();
    clock_t vector_time = clock();
    p.sort_deque();
    clock_t deque_time = clock();

    p.print_sorted_args();
    
    double vector_elapsed = static_cast<double>(vector_time - start_time) / CLOCKS_PER_SEC * 1000;
    double deque_elapsed = static_cast<double>(deque_time - vector_time) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : " << vector_elapsed << "ms" << std::endl;
    std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque : " << deque_elapsed << "ms" << std::endl;

    return 0;
}