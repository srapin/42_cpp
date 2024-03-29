/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:15 by srapin            #+#    #+#             */
/*   Updated: 2024/03/29 20:30:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>
class PmergeMe
{
	private:
		std::vector<int> _vec;
		double _startTime;
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
        // PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        // PmergeMe &operator=(const PmergeMe& other);
		void sort();
		void fordJonhson(int start, int end);
		void sort2elem(int , int );
		// void sortPaires(int b, int e, int mid);
		void sortPaires(int b, int e);
};

#endif