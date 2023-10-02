/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:49:38 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 20:50:51 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    private:
        /* data */
    protected:
        FragTrap();
    public:
        FragTrap(std::string name);
        ~FragTrap();
        // FragTrap &operator=(FragTrap const &FragTrap);
        void highFivesGuys(void);
        void attack(const std::string& target);
};




#endif