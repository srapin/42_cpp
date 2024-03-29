/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:39 by srapin            #+#    #+#             */
/*   Updated: 2024/03/29 21:04:24 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	_startTime = clock();
	for (int i = 0; i < ac; i++)
		_vec.push_back(atoi(av[i]));
	if (_vec.size() %2)
		_vec.push_back(-1);
	sort();
}

// PmergeMe::PmergeMe(const PmergeMe &other)
// {
// 	std::cout << "PmergeMe: Copy constructor" << std::endl;
// }

// PmergeMe &PmergeMe::operator=(const PmergeMe &other)
// {
// 	std::cout << "PmergeMe: Assignment operator" << std::endl;
// 	return (*this);
// }

void PmergeMe::sort()
{
	if (_vec.size() < 2)
		return ;
	fordJonhson(0, _vec.size() - 1);
}

void PmergeMe::fordJonhson(int start, int end)
{
	if (start >= end)
		return ;
	// if (end - start == 1)
	// 	return (sort2elem(start, end));
	for (int i = start; i < end; i += 2)
		sort2elem(i, i + 1);
	sortPaires(0, _vec.size() - 2);
	// sortPaires(0, _vec.size(),( _vec.size())/2);
}

void PmergeMe::sort2elem(int f, int s)
{
	if (_vec[f] > _vec[s])
		std::swap(_vec[f], _vec[s]);
}

// void PmergeMe::sortPaires(int b, int e, int mid)
// {
// 	if (e - b <= 2 || mid >= e)
// 		return;
// 	//plus q une paire -> trier les souspartie
// 	// int left_b = b;
// 	// int left_e = mid;
// 	// int left_mid = (left_e - left_b) %2 ? left_e - left_b : left_e - left_b + 1;
// 	sortPaires(b, mid,( (mid - b) / 2) %2 ? (mid - b ) /2 + 1 : (mid - b)/2);
// 	sortPaires(mid, e, ((e - mid)/2) %2 ?(e - mid) / 2 - 1 : (e - mid)/ 2);
// 	std::cout << b << ", " << e << " ," << mid << std::endl;
// }

void PmergeMe::sortPaires(int b, int e)
{
	if (e - b < 2)
		return;

	//0, 6;
	//0, 2
	//4, 6
	// sortPaires(b, mid,( (mid - b) / 2) %2 ? (mid - b ) /2 + 1 : (mid - b)/2);
	// sortPaires(mid, e, ((e - mid)/2) %2 ?(e - mid) / 2 - 1 : (e - mid)/ 2);
	int mid =b +  ((e + 2 - b) / 2);
	if (mid % 2)
		mid ++;
	sortPaires(b, mid - 2);
	sortPaires(mid, e);
	
	int gap =  ceil((e + 2 - b) / 4.0);
	int j;
	while (gap > 0)
	{
		for(int i = b + 1; i + (2 * gap) < e + 1; i +=2 )
        {
            j = i + (2 * gap);
            if (_vec[i] > _vec[j])
			{
                std::swap(_vec[i - 1], _vec[j - 1]);
                std::swap(_vec[i], _vec[j]);
			}
        }
		gap = gap <= 1 ? 0 : ceil(gap/2.0);
	}
}

PmergeMe::~PmergeMe()
{
}

// b1 a1 a2
//b2?