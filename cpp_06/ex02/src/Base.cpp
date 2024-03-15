/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:13:03 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 23:40:52 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int rand = (std::rand() % 3);
	if (rand == 0)
	{
		std::cout << "creating A" << std::endl;
		return new A;
	}
	else if (rand == 1)
	{
		std::cout << "creating B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "creating C" << std::endl;
		return new C;
	}
}


void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
			
}

void identify(Base& p)
{
	try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" << std::endl;
        (void)a;
		return;
    } catch(const std::exception & e) {}
	try {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" << std::endl;
        (void)b;
		return;
    } catch(const std::exception & e) {}
	try {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" << std::endl;
        (void)c;
		return;
    } catch(const std::exception & e) {}
	std::cout << "Unknown" << std::endl;
}