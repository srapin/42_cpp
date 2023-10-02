/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:48:43 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 01:57:13 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"


Brain::Brain()
{
    bzero(this->ideas, sizeof(std::string) * 100);
	std::cout << "Brain: Default constructor" << std::endl;
}
void Brain::copyIdeas(const Brain& other)
{
    for (int i = 0; i < 100; i++)
    {
        std::string lol = other.ideas[i];
        // std::cout << lol << std::endl;
        lol = ideas[i];
        // std::cout << lol << std::endl;
        
        ideas[i] = std::string("lol");
    }
}

Brain::Brain(const Brain& other) 
{
    copyIdeas(other);
	std::cout << "Brain: Copy constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    copyIdeas(other);
	std::cout << "Brain: Assignment operator" << std::endl;
	return *this;
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor" << std::endl;
}