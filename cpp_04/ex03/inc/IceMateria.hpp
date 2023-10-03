/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceMateria.hpp                                     :+:      :+:    :+:   */
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

class IceMateria : public AMateria
{
	protected:

	public:
		IceMateria();
        IceMateria(const IceMateria& other);
        virtual ~IceMateria();
        IceMateria &operator=(const IceMateria& other);
		virtual IceMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif