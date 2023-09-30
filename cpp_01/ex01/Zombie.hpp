/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:22:58 by srapin            #+#    #+#             */
/*   Updated: 2023/09/30 22:36:06 by srapin           ###   ########.fr       */
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
        Zombie();
        void set_name(std::string name);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );
// Zombie* newZombie( std::string name );
// void randomChump( std::string name );