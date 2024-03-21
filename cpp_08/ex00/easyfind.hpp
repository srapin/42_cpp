/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:05:57 by srapin            #+#    #+#             */
/*   Updated: 2024/03/21 13:39:12 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator>

template <typename T>
int easyfind(T cont, int toFind)
{
	int i = 0;
	// auto it;
	for (typename T::iterator it = cont.begin(); it != cont.end() && *it != toFind; it++)
		i++;
	return i < cont.size() ? i : -1;
	
}