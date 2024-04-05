/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:15 by srapin            #+#    #+#             */
/*   Updated: 2024/04/05 21:22:37 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP


#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <bits/stdc++.h>
class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::list<int> _lst;
		double _startTime;
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
        // PmergeMe(const PmergeMe& other);
        ~PmergeMe();
        // PmergeMe &operator=(const PmergeMe& other);


		
		void sortVector();
		
        void fordJonhsonVector(std::vector<int> &v, int);
		
        void excludeElemVector(std::vector<int> &, std::vector<int> &, int range);
        void excludeSmallerVector(std::vector<int> &v, std::vector<int> &smaller, int step);
		void insertExcludeVector(std::vector<int> &v, std::vector<int> &alone, int step);
		void insertSmallerVector(std::vector<int> &v, std::vector<int> &smaller, int step);
        void sortGroupVector(std::vector<int> &v, int gap);
		size_t dichotomyInsetrionVector(std::vector<int> &v, int key, int start, int end, int step);
		
        int jacobsthalNumber(int n);
		void getJacobsthalOrder(std::vector<int> &, int size);

		void sortList();

		std::list<int>::iterator getListIterator(std::list<int>, int move);
		
        void fordJonhsonList(std::list<int> &v, int);
		
        void excludeElemList(std::list<int> &, std::list<int> &, int range);
        void excludeSmallerList(std::list<int> &v, std::list<int> &smaller, int step);
		void insertExcludeList(std::list<int> &v, std::list<int> &alone, int step);
		void insertSmallerList(std::list<int> &v, std::list<int> &smaller, int step);
        void sortGroupList(std::list<int> &v, int gap);
		size_t dichotomyInsetrionList(std::list<int> &v, int key, int start, int end, int step);
		void swap_range_list(std::list<int> &lst, int start1, int end1, int size);
};

#endif