/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:01:40 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:39:16 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "IMateriaSource.hpp"
#include <string.h>

class MateriaSource : public IMateriaSource
{
	protected:
        AMateria *_inv[4];
        int _count;
	public:
		MateriaSource();
        MateriaSource(const MateriaSource& other);
        virtual ~MateriaSource();
        MateriaSource &operator=(const MateriaSource& other);
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
		int getCount() const;
        AMateria * const*getInv() const;
        void copyInv(const MateriaSource& other);
};

#endif