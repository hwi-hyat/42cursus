#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <cstdlib>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        void insertion_sort(std::vector<int> &vector);
        void insertion_sort_d(std::deque<int> &deque);
        void devide_to_insertion_sort(std::vector<int> &vector, int unit_size);
        void devide_to_insertion_sort_d(std::deque<int> &deque, int unit_size);
        std::vector<int> merge_sort(std::vector<int> &tmp, std::vector<int> &tmp2);
        std::deque<int> merge_sort_d(std::deque<int> &tmp, std::deque<int> &tmp2);
        void devide_to_merge_sort(std::vector<int> &vector, int unit_size);
        void devide_to_merge_sort_d(std::deque<int> &deque, int unit_size);
        int get_unit_size(int numbers);
    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & object);
        ~PmergeMe(void);
        PmergeMe &operator=(PmergeMe const & object);

        void show_and_load_args(int argc, char **argv);
        void print_sorted_args();
        void sort_vector();
        void sort_deque();
        std::vector<int> sort_with_algorithm();

};



#endif