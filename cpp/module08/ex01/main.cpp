#include"Span.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "=============================" << std::endl;

	Span sp2 = Span(10001);

	srand(time(NULL));

	for(int i = 0; i < 10001; i++)
		sp2.addNumber(rand() % 100000);

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	
	return 0;
}