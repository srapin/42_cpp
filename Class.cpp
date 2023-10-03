#include "../inc/Example.hpp"

Example::Example(/* args */)
{
	std::cout << "Example: Default constructor" << std::endl;
}

Example::Example(const Example& other) {

	std::cout << "Example: Copy constructor" << std::endl;
}

Example& Example::operator=(const Example& other) {
	std::cout << "Example: Assignment operator" << std::endl;
	return *this;
}

Example::~Example()
{
    std::cout << "Example: Destructor" << std::endl;
}