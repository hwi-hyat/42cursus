#include"Span.hpp"
#include<iostream>

Span::Span() {}

Span::Span(unsigned int n): _size(n)
{
    this->_vec.reserve(this->_size);
}

Span::Span(const Span &object)
{
    this->_vec = object._vec;
    this->_size = object._size;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &object)
{
    if(this == &object)
        return *this;
    
    this->_vec = object._vec;
    this->_size = object._size;
    return *this;
}

void Span::addNumber(int n)
{
    if(this->_vec.size() == this->_size)
        throw Span::FullException();
    
    std::vector<int>::iterator it = this->_vec.begin();
    std::vector<int>::iterator it_end = this->_vec.end();

    for(; it <= it_end; it++)
    {
        if(it == it_end)
        {
            this->_vec.push_back(n);
            break;
        }
        
        if(n <= *it)
        {
            this->_vec.insert(it, n);
            break;
        }
    }
}

unsigned int Span::shortestSpan()
{
    if(this->_vec.size() <= 1)
        throw Span::NoSpanException();

    std::vector<int>::iterator it = this->_vec.begin();
    std::vector<int>::iterator it_end = this->_vec.end();
    unsigned int min = std::numeric_limits<int>::max();
    unsigned int span;

    for(; it < it_end - 1; it++)
    {
        span = std::abs(*it - *(it + 1));
        if(span < min)
            min = span;
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if(this->_vec.size() <= 1)
        throw Span::NoSpanException();

    std::vector<int>::iterator it = this->_vec.begin();
    std::vector<int>::iterator it_end = this->_vec.end();

    return std::abs(*it - *(it_end - 1));
}

const char *Span::FullException::what() const throw()
{
	return "There's full of integers in here";
}

const char *Span::NoSpanException::what() const throw()
{
	return "I cannot measure any span between integers";
}