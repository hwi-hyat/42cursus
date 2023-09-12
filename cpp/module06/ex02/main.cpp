#include "A.h"
#include "B.h"
#include "C.h"
#include <random>
#include <iostream>

Base* generate(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    Base*   ret;

    switch (dis(gen))
    {
        case 0:
            ret = new A;
            std::cout << "A generated" << std::endl;
            break; 
        case 1:
            ret = new B;
            std::cout << "B generated" << std::endl;
            break; 
        case 2:
            ret = new C;
            std::cout << "C generated" << std::endl;
    }
    return ret;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "It's A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "It's B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "It's C" << std::endl;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        static_cast<void>(a);
        std::cout << "A Confirm" << std::endl;
    }
    catch (std::bad_cast& e) {
    }
    try {
        B& b = dynamic_cast<B&>(p);
        static_cast<void>(b);
        std::cout << "B Confirm" << std::endl;
    }
    catch (std::bad_cast& e) {
    }
    try {
        C& c = dynamic_cast<C&>(p);
        static_cast<void>(c);
        std::cout << "C Confirm" << std::endl;
    }
    catch (std::bad_cast& e) {
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(time(NULL)));

    Base*   base = generate();

    identify(base);
    identify(*base);

    delete base;
}
