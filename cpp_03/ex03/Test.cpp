

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


void Test::scav()
{

	ScavTrap *at;
	ScavTrap *def;

    // std::cout << "Creating new ScavTrap: " << std::endl;
    // std::cout << "Using accessible construcor\n";
    ScavTrap base("Base");
    ScavTrap other("Other");
    
	at = &base;
	def = &other;

	// std::cout << "Using assingnment operator\n";
	ScavTrap assignTest("Before assignment");
	assignTest = base;
	at = &assignTest;

	// std::cout << "Using copy construcor\n";
	ScavTrap copyTest = ScavTrap(other);
	def = &copyTest;
	
	at->doClassics(*def, 10);
}

void Test::clap()
{

	ClapTrap *at;
	ClapTrap *def;

    // std::cout << "Creating new ClapTrap: " << std::endl;
    // std::cout << "Using accessible construcor\n";
    ClapTrap base("Base");
    ClapTrap other("Other");
    
	at = &base;
	def = &other;

	// std::cout << "Using assingnment operator\n";
	ClapTrap assignTest("Before assignment");
	assignTest = base;
	at = &assignTest;

	// std::cout << "Using copy construcor\n";
	ClapTrap copyTest = ClapTrap(other);
	def = &copyTest;
	
	at->doClassics(*def, 10);
}

void Test::frag()
{

	FragTrap *at;
	FragTrap *def;

    // std::cout << "Creating new FragTrap: " << std::endl;
    // std::cout << "Using accessible construcor\n";
    FragTrap base("Base");
    FragTrap other("Other");
    
	at = &base;
	def = &other;

	// std::cout << "Using assingnment operator\n";
	FragTrap assignTest("Before assignment");
	assignTest = base;
	at = &assignTest;

	// std::cout << "Using copy construcor\n";
	FragTrap copyTest = FragTrap(other);
	def = &copyTest;
	
	at->doClassics(*def, 10);
}

void Test::diamond()
{

	DiamondTrap *at;
	DiamondTrap *def;

    std::cout << "Creating new DiamondTrap: " << std::endl;
    std::cout << "Using accessible construcor\n";
    DiamondTrap base("Base");
    DiamondTrap other("Other");

	std::cout << "Using assingnment operator\n";
	DiamondTrap assignTest("Before assignment");
	assignTest = base;

	std::cout << "Using copy construcor\n";
	DiamondTrap copyTest = DiamondTrap(other);


	at = &assignTest;
	def = &copyTest;
	
	at->doClassics(*def, 10);
	def->doClassics(*at, 100);
}