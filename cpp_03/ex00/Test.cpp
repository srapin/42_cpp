

#include "Test.hpp"

Test::Test(/* args */)
{
	std::cout << "Test: Default constructor" << std::endl;
}

Test::Test(const Test& other) {

	std::cout << "Test: Copy constructor" << std::endl;
}

Test& Test::operator=(const Test& other) {
	std::cout << "Test: Assignment operator" << std::endl;
	return *this;
}

Test::~Test()
{
    std::cout << "Test: Destructor" << std::endl;
}

void Test::clap()
{

	ClapTrap *at;
	ClapTrap *def;

    std::cout << "Creating new ClapTrap: " << std::endl;
    std::cout << "Using accessible construcor\n";
    ClapTrap base("Base");
    ClapTrap other("Other");
    
	at = &base;
	def = &other;

	std::cout << "Using assingnment operator\n";
	ClapTrap assignTest("Before assignment");
	assignTest = base;
	at = &assignTest;

	std::cout << "Using copy construcor\n";
	ClapTrap copyTest = ClapTrap(other);
	def = &copyTest;
	
	at->doClassics(*def, 10);
}
