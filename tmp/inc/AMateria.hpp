/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:39:11 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 18:45:43 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA
#define AMATERIA

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	// [...]
	public:
		AMateria(std::string const & type);
		// [...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};

#endif