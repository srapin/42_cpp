/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:58:45 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 01:58:27 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
		Cat();
		Cat(const Cat& other);
		virtual ~Cat();
		Cat& operator=(const Cat& other);
		virtual void makeSound() const;
		Brain& getBrain();
	private:
		Brain *_brain;
};


#endif