/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:58:50 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 01:59:45 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
		Dog();
		Dog(const Dog& other);
		virtual ~Dog();
		Dog& operator=(const Dog& other);
		virtual void makeSound() const;
		Brain& getBrain();
	private:
		Brain *_brain;
};

#endif