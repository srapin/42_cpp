/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureMateria.hpp                                    :+:      :+:    :+:   */
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

class CureMateria :public AMateria
{
	protected:

	public:
		CureMateria();
        CureMateria(const CureMateria& other);
        virtual ~CureMateria();
        CureMateria &operator=(const CureMateria& other);
		virtual CureMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif