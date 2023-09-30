/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:00:47 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 00:08:45 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "error : bad arguments";
		return(1);
	}
    // string 
	Replace	rep(av[1], av[2], av[3]);
	return (0);
}