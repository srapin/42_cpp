/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:07:56 by srapin            #+#    #+#             */
/*   Updated: 2024/03/18 21:14:37 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}


template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}