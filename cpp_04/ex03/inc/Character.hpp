/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:02 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 22:39:38 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
#define CHARACTER

#include "ICharacter.hpp"
#include <string.h>
#include <vector>

class Character : public ICharacter
{
    protected:
        AMateria *_inv[4];
        int _count;
        // std::vector <>;
	public:
		Character(std::string name);
        Character(const Character& other);
        virtual ~Character();
        Character &operator=(const Character& other);
		std::string const & getName() const;
		int getCount() const;
        AMateria * const*getInv() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
        void copyInv(const Character& other);
};

#endif