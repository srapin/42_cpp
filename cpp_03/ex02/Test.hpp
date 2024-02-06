/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:29 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:25:04 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class Test
{
	public :
		static void clap();
		static void scav();
		static void frag();

	private:
		Test();
        Test(const Test& other);
        virtual ~Test();
        Test &operator=(const Test& other);
		
};