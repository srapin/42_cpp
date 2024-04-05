/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:15 by srapin            #+#    #+#             */
/*   Updated: 2024/04/04 18:22:06 by srapin           ###   ########.fr       */
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
		void exchangeGroup(int , int , int);
        void fordJonhson(std::vector<int> &v, int);
		
        void excludeElem(std::vector<int> &, std::vector<int> &, int range);
        void excludeSmaller(std::vector<int> &v, std::vector<int> &smaller, int step);
		void insertExclude(std::vector<int> &v, std::vector<int> &alone, int step);
		void insertSmaller(std::vector<int> &v, std::vector<int> &smaller, int step);
        void sortGroup(std::vector<int> &v, int gap);
        int jacobsthalNumber(int n);
		void getJacobsthalOrder(std::vector<int> &v, int step);
};

#endif