/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:39:11 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:11:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
#define AMATERIA

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	// [...]
	public:
		AMateria(std::string const & type);
        AMateria(const AMateria& other);
        virtual ~AMateria();
        AMateria &operator=(const AMateria& other);
		std::string const & getType() const; //Returns the materia type
		void setType(std::string type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};


#endif