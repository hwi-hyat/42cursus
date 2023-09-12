#ifndef RPN_HPP
# define RPN_HPP

#include<stack>
#include<string>
#include<iostream>

class RPN
{
    private:
        std::stack<float> _stack;
        void operands(char op);
        
    public:
        RPN();
        RPN(RPN const &other);
        ~RPN();
        RPN &operator=(RPN const &other);

        void calculate(std::string &str);
};


#endif