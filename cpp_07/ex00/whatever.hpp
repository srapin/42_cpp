/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:07:56 by srapin            #+#    #+#             */
/*   Updated: 2024/03/20 16:38:54 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T const &a, T const & b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T const &a, T const &b)
{
	if (a > b)
		return a;
	return b;
}

#endif