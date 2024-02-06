/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:04:21 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 22:30:59 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(/* args */)
{
    _count = 0;
    bzero(_inv, 4 * sizeof(AMateria *));
	std::cout << "MateriaSource: Default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    copyInv(other);
	std::cout << "MateriaSource: Copy constructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    copyInv(other);
	std::cout << "MateriaSource: Assignment operator" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inv[i])
            delete _inv[i];
    }
    std::cout << "MateriaSource: Destructor" << std::endl;
}

AMateria* const* MateriaSource::getInv() const
{
    return _inv;
}


int MateriaSource::getCount() const
{
    return _count;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (getCount() < 0 || getCount() > 3)
        return;
    _inv[getCount()] = m;
    _count++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inv[i] && _inv[i]->getType() == type)
            return _inv[i]->clone();
    }
    return (NULL);
}

void MateriaSource::copyInv(const MateriaSource& other)
{
    _count = other.getCount();
    AMateria * const*toCopy = other.getInv();
    for (int i = 0; i < getCount(); i++)
    {
        if (this->_inv[i])
			delete this->_inv[i];
        _inv[i] = toCopy[i]->clone();
    }
}