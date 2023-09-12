#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator iter = container.begin();
    typename T::iterator it_end = container.end();

    for(; iter != it_end; iter++)
        if (*iter == n)
            return (iter);
    throw std::exception();
}

#endif