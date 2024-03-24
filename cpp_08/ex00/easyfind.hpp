/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:05:57 by srapin            #+#    #+#             */
/*   Updated: 2024/03/24 23:36:16 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T cont, int toFind)
{
	typename T::iterator t = std::find(cont.begin(), cont.end(), toFind);
	return t != cont.end() ? t : throw std::exception();
}