/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:29 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:21:14 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

class Test
{
	public :
		static void clap();
		static void scav();

	private:
		Test();
        Test(const Test& other);
        virtual ~Test();
        Test &operator=(const Test& other);
		
};