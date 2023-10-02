/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:58:50 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 00:18:50 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
    public:
		WrongDog();
		WrongDog(const WrongDog& other);
		virtual ~WrongDog();
		WrongDog& operator=(const WrongDog& other);
		virtual void makeSound() const;
};

#endif