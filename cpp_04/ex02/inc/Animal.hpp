/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:36:22 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 21:18:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	public :
		virtual void makeSound() const = 0;
		virtual ~Animal();
	protected:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		const std::string getType() const;
		Animal(std::string str);
		std::string type;

};

#endif