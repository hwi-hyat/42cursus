#include"PmergeMe.hpp"


PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(PmergeMe const & object)
{
    this->_vector = object._vector;
    this->_deque = object._deque;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe &PmergeMe::operator=(PmergeMe const & object)
{
    this->_vector = object._vector;
    this->_deque = object._deque;
    return *this;
}

void PmergeMe::show_and_load_args(int argc, char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
    {
        this->_vector.push_back(std::atoi(argv[i]));
        this->_deque.push_back(std::atoi(argv[i]));
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_sorted_args()
{
    std::deque<int>::iterator it = this->_deque.begin();
    std::deque<int>::iterator it_end = this->_deque.end();

    std::cout << "After: ";
    for (; it != it_end; it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::insertion_sort(std::vector<int> &vector)
{
    int size = vector.size();
    for(int i = 1; i < size; i++)
    {
        int tmp = vector[i];
        for(int j = 0; j < i; j++)
        {
            if (tmp < vector[j])
            {
                vector.erase(vector.begin() + i);
                vector.insert(vector.begin() + j, tmp);
                break;
            }
        }
    }
}

void PmergeMe::insertion_sort_d(std::deque<int> &deque)
{
    int size = deque.size();
    for(int i = 1; i < size; i++)
    {
        int tmp = deque[i];
        for(int j = 0; j < i; j++)
        {
            if (tmp < deque[j])
            {
                deque.erase(deque.begin() + i);
                deque.insert(deque.begin() + j, tmp);
                break;
            }
        }
    }
}

void PmergeMe::devide_to_insertion_sort(std::vector<int> &vector, int unit_size)
{
    int size = vector.size();

    int idx = 0;
    while(idx < size)
    {
        std::vector<int>::iterator start = vector.begin() + idx;
        std::vector<int>::iterator end = vector.begin() + idx + unit_size;
        if (end > vector.end())
            end = vector.end();
        
        std::vector<int> tmp(start, end);
        insertion_sort(tmp);
        for(size_t i = 0; i <tmp.size(); i++)
            *(start + i) = tmp[i];
        idx += unit_size;
    }
}

void PmergeMe::devide_to_insertion_sort_d(std::deque<int> &deque, int unit_size)
{
    int size = deque.size();

    int idx = 0;
    while(idx < size)
    {
        std::deque<int>::iterator start = deque.begin() + idx;
        std::deque<int>::iterator end = deque.begin() + idx + unit_size;
        if (end > deque.end())
            end = deque.end();
        
        std::deque<int> tmp(start, end);
        insertion_sort_d(tmp);
        for(size_t i = 0; i < tmp.size(); i++)
            *(start + i) = tmp[i];
        idx += unit_size;
    }
}

std::vector<int> PmergeMe::merge_sort(std::vector<int> &tmp, std::vector<int> &tmp2)
{
    std::vector<int>::iterator it = tmp.begin();
    std::vector<int>::iterator it2 = tmp2.begin();
    std::vector<int> result;

    while(it != tmp.end() && it2 != tmp2.end())
    {
        if (*it < *it2)
        {
            result.push_back(*it);
            it++;
        }
        else
        {
            result.push_back(*it2);
            it2++;
        }
    }
    while(it != tmp.end())
    {
        result.push_back(*it);
        it++;
    }
    while(it2 != tmp2.end())
    {
        result.push_back(*it2);
        it2++;
    }
    return result;
}

std::deque<int> PmergeMe::merge_sort_d(std::deque<int> &tmp, std::deque<int> &tmp2)
{
    std::deque<int>::iterator it = tmp.begin();
    std::deque<int>::iterator it2 = tmp2.begin();
    std::deque<int> result;

    while(it != tmp.end() && it2 != tmp2.end())
    {
        if (*it < *it2)
        {
            result.push_back(*it);
            it++;
        }
        else
        {
            result.push_back(*it2);
            it2++;
        }
    }
    while(it != tmp.end())
    {
        result.push_back(*it);
        it++;
    }
    while(it2 != tmp2.end())
    {
        result.push_back(*it2);
        it2++;
    }
    return result;
}


void PmergeMe::devide_to_merge_sort(std::vector<int> &vector, int unit_size)
{
    int size = vector.size();

    int idx = 0;
    while(idx < size)
    {
        std::vector<int>::iterator start = vector.begin() + idx;
        std::vector<int>::iterator end = vector.begin() + idx + unit_size;
        if(end > vector.end())
            return;
        
        std::vector<int>::iterator start2 = vector.begin() + idx + unit_size;
        std::vector<int>::iterator end2 = vector.begin() + idx + (unit_size * 2);
        if(end2 > vector.end())
            end2 = vector.end();
        
        std::vector<int> tmp(start, end);
        std::vector<int> tmp2(start2, end2);
        std::vector<int> done = merge_sort(tmp, tmp2);
        
        for(size_t i = 0; i < done.size(); i++)
            *(start + i) = done[i];
        idx += unit_size * 2;
    }
}

void PmergeMe::devide_to_merge_sort_d(std::deque<int> &deque, int unit_size)
{
    int size = deque.size();

    int idx = 0;
    while(idx < size)
    {
        std::deque<int>::iterator start = deque.begin() + idx;
        std::deque<int>::iterator end = deque.begin() + idx + unit_size;
        if(end > deque.end())
            return;

        std::deque<int>::iterator start2 = deque.begin() + idx + unit_size;
        std::deque<int>::iterator end2 = deque.begin() + idx + (unit_size * 2);
        if(end2 > deque.end())
            end2 = deque.end();

        std::deque<int> tmp(start, end);
        std::deque<int> tmp2(start2, end2);
        std::deque<int> done = merge_sort_d(tmp, tmp2);

        for(size_t i = 0; i < done.size(); i++)
            *(start + i) = done[i];
        idx += unit_size * 2;
    }
}

int PmergeMe::get_unit_size(int n)
{
    int ret = 1;
    int def = 1;
    while(def < n)
    {
        if(def <= n && n < def * 2)
            ret = def / 16;
        def *= 2;
    }

    if(ret < 4)
        return 4;
    return ret;
}

void PmergeMe::sort_vector()
{
	int size = this->_vector.size();

    if (size <= 1)
        return;

    int unit_size = get_unit_size(size);
    devide_to_insertion_sort(this->_vector, unit_size);
    while(unit_size < size)
    {
        devide_to_merge_sort(this->_vector, unit_size);
        unit_size *= 2;
    }
}

void PmergeMe::sort_deque()
{
    int size = this->_deque.size();

    if (size <= 1)
        return;

    int unit_size = get_unit_size(size);
    devide_to_insertion_sort_d(this->_deque, unit_size);
    while(unit_size < size)
    {
        devide_to_merge_sort_d(this->_deque, unit_size);
        unit_size *= 2;
    }
}

std::vector<int> PmergeMe::sort_with_algorithm()
{
    std::vector<int> sorted;
    sorted = this->_vector;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}


// 2       4
// 4       4
// 8       4
// 16      4
// 32      4
// 64      4
// 128     8
// 256     16
// 512     32
// 1024    64