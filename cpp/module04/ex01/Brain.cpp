#include"Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "[empty]";
	std::cout << "Brain created with default constructor" << std::endl;
}

Brain::Brain(const Brain &object)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = object.ideas[i];
	std::cout << "Brain created with object constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &object)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = object.ideas[i];
	std::cout << "Brain Assigned" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::get_idea(int i) const
{
	return (this->ideas[i]);
}

void Brain::set_idea(int i, std::string idea)
{
	this->ideas[i] = idea;
}