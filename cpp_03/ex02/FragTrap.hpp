/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:49:38 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 02:01:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        /* data */
    protected:
        FragTrap();
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap &operator=(FragTrap const &FragTrap);
        ~FragTrap();
        void highFivesGuys(void);
        virtual void attack(const std::string& target);
        virtual void doSpecifics();
};




#endif