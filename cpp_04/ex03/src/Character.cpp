/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:36 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 23:08:42 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(std::string name)
{
    _name = name;
    _count = 0;
    bzero(_inv, 4 * sizeof(AMateria *));
	std::cout << "Character: Default constructor" << std::endl;
}



Character::Character(const Character& other) {
    _name = other.getName();
    copyInv(other);
	std::cout << "Character: Copy constructor" << std::endl;
}

Character& Character::operator=(const Character& other) {
    _name = other.getName();
    copyInv(other);
	std::cout << "Character: Assignment operator" << std::endl;
	return *this;
}

void Character::copyInv(const Character& other)
{
    _count = other.getCount();
    AMateria * const*toCopy = other.getInv();
    for (int i = 0; i < getCount(); i++)
    _inv[i] = toCopy[i]->clone();
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inv[i])
            delete _inv[i];
    }
    std::cout << "Character: Destructor" << std::endl;
}

std::string const & Character::getName() const
{
    return _name;
}

int Character::getCount() const
{
    return _count;
}

AMateria* const* Character::getInv() const
{
    return _inv;
}

void Character::equip(AMateria* m)
{
    int i = 0;
    
    if (getCount() > 3)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (_inv[i] == m)
            return;
    }
    while (_inv[i])
        i++;
    _inv[i] = m;
}

void Character::unequip(int idx)
{
    if (0 <= idx  && idx < 4)
        _inv[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
    if (0 <= idx  && idx < 4 && _inv[idx])
        _inv[idx]->use(target);
}