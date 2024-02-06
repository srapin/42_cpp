/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:29 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 01:16:28 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class Test
{
	public :
		static void clap();

	private:
		Test();
        Test(const Test& other);
        virtual ~Test();
        Test &operator=(const Test& other);
		
};