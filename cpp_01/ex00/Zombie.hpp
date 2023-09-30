/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:22:58 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 22:25:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
class Zombie
{
    private:
        std::string _name;
    public:
        void announce( void );
        Zombie(std::string name);
        ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );