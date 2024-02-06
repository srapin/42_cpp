/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:15 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:39:28 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICEMATERIA
#define ICEMATERIA

#include "AMateria.hpp"

class Ice : public AMateria
{
	protected:

	public:
		Ice();
        Ice(const Ice& other);
        virtual ~Ice();
        Ice &operator=(const Ice& other);
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif