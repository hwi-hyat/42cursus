#include"RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(RPN const &other)
{
    this->_stack = other._stack;
}

RPN::~RPN()
{

}

RPN &RPN::operator=(RPN const &other)
{
    if(this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

void RPN::operands(char op)
{
    int a;
    int b;

    if(this->_stack.size() < 2)
        throw std::exception();
    else if(this->_stack.top() == 0 && op == '/')
        throw std::exception();
    else
    {
        a = this->_stack.top();
        this->_stack.pop();
        b = this->_stack.top();
        this->_stack.pop();
    }

    if(op == '+')
        this->_stack.push(b + a);
    else if(op == '-')
        this->_stack.push(b - a);
    else if(op == '*')
        this->_stack.push(b * a);
    else if(op == '/')
        this->_stack.push(b / a);
}

void RPN::calculate(std::string &str)
{
    std::string::iterator it = str.begin();
    std::string::iterator it_end = str.end();
    
    for(; it < it_end; it++)
    {
        if(*it == ' ')
            continue;
        else if(*it >= '0' && *it <= '9')
            this->_stack.push(*it - '0');
        else if(*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%')
            operands(*it);
        else
            throw std::exception();
    }
    
    if(this->_stack.size() != 1)
        throw std::exception();
    else
        std::cout << this->_stack.top() << std::endl;
}
