/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:11 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:39:32 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUREMATERIA
#define CUREMATERIA

#include "AMateria.hpp"

class Cure :public AMateria
{
	protected:

	public:
		Cure();
        Cure(const Cure& other);
        virtual ~Cure();
        Cure &operator=(const Cure& other);
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif