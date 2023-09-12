#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include"easyfind.hpp"

void no_existence(int n)
{
    std::cout << "There's no " << n << std::endl;
}

int main()
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    for(int i = 10; i < 100; i += 10)
    {
        v.push_back(i);
        l.push_back(i);
        d.push_back(i);
    }

    int input;
    std::cout << "Put a number to find in containers" << std::endl;
    std::cin >> input;
    try {
        std::cout << "vector: " << *easyfind(v, input) << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "vector: ";
        no_existence(input);
    }
    try {
        std::cout << "list: " << *easyfind(l, input) << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "list: ";
        no_existence(input);
    }
    try {
        std::cout << "deque: " << *easyfind(d, input) << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "deque: ";
        no_existence(input);
    }

    return 0;
}