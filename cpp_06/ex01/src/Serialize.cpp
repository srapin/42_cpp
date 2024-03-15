/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:46:46 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 22:53:49 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialize.hpp"

Serialize::Serialize(/* args */)
{
	std::cout << "Serialize: Default constructor" << std::endl;
}

Serialize::Serialize(const Serialize& other) {
	(void) other;
	std::cout << "Serialize: Copy constructor" << std::endl;
}

Serialize& Serialize::operator=(const Serialize& other) {
	(void) other;
	std::cout << "Serialize: Assignment operator" << std::endl;
	return *this;
}

Serialize::~Serialize()
{
    std::cout << "Serialize: Destructor" << std::endl;
}

uintptr_t Serialize::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}