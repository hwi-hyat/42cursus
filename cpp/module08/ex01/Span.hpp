#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
    private:
        std::vector<int> _vec;
        unsigned int _size;
        
        Span();

    public:
        Span(unsigned int n);
        Span(const Span &object);
        ~Span();
        Span &operator=(const Span &object);

        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class FullException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        
        class NoSpanException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};



#endif