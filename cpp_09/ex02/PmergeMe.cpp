/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:39 by srapin            #+#    #+#             */
/*   Updated: 2024/04/20 23:44:13 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	std::cout << "Before : ";
	for (int i = 0; i < ac; i++)
	{
		_lst.push_back(atoi(av[i]));
		_vec.push_back(atoi(av[i]));
		std::cout << _vec[i] << " ";
		if (_vec[i] < 0)
		{
			std::cout << std::endl << "Arguments should be positiv integer" << std::endl;
			exit(0);
		}
	}
	std::cout  << std::endl;
	_startTime = clock();
	sortVector();
	_midTime = clock();
	sortList();
	_endTime = clock();

	
	std::cout << "After : \n";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] <<  " ";
		if ((i && _vec[i] < _vec[i - 1]))
			return;
		if ((i && *getListIterator(_lst, i) < *getListIterator(_lst, i- 1)))
			return;
	}
	std::cout  << std::endl;
	std::cout << "Time to process a range of "<< ac <<" elements with std::vector : " << _midTime - _startTime << " us\n";
	std::cout << "Time to process a range of "<< ac <<" elements with std::list : " << _endTime - _midTime << " us\n";
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void) other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void) other;
	return (*this);
}

//return neme jacobstal number
int PmergeMe::jacobsthalNumber(int n)
{
	if (n <= 1)
		return (n);
	return (2 * jacobsthalNumber(n - 2) + jacobsthalNumber(n - 1));
}

void PmergeMe::getJacobsthalOrder(std::vector<int> &v, int size)
/*
Generate insertion order following jacobsthal order.
*/
{
	
	int prevJac = -1;
	int currentJac = jacobsthalNumber(2);
	int nextInsert = currentJac;
	int jacCount = 3;
	
	while(prevJac < size)
	{
		for (; nextInsert > prevJac; nextInsert--)
		{
			v.push_back(nextInsert);
		}
		prevJac = currentJac;
		currentJac = jacobsthalNumber(jacCount);
		nextInsert = currentJac;
		jacCount++;
	}
}

void PmergeMe::sortVector()
/*
launch Ford-Jonhson algorithm
*/
{
	if (_vec.size() < 2)
		return ;
	fordJonhsonVector(_vec, 2);
}

/// @brief move elem that can not be paired
void PmergeMe::excludeElemVector(std::vector<int> &v, std::vector<int> & alone, int groupSize)
/*
move elements that can not be paired from v to alone.
groupSize represent the current size of pair.
*/
{
	if (v.size() % groupSize) //-> some elem won t have a match
	{
		alone.insert(alone.begin(), v.end() - v.size() % groupSize, v.end());
		v.erase(v.end() - v.size() % groupSize, v.end());
	}
}

void PmergeMe::excludeSmallerVector(std::vector<int> &v, std::vector<int> &smaller, int step)
/*
Move smaller element of pair from v to smaller. 
step represent the size of an elements.
*/
{
	for (size_t i = 0; i < v.size() && step > 0; i += step)
    {
        smaller.insert(smaller.end(), v.begin() + i, v.begin() + i + step);
        v.erase(v.begin() + i, v.begin() + i + step);
    }
}


void PmergeMe::sortGroupVector(std::vector<int> &v, int dist)
/*
Sort each pair of size 'dist' 
*/
{
	for (size_t i = dist - 1; i + dist < v.size(); i += 2 * dist)
	{
		if (v[i] > v[i + dist])
		{
			std::vector<int> tmp(v.begin() + i + 1, v.begin() + i + dist + 1);
			std::copy(v.begin() + i - dist + 1, v.begin() + i + 1,  v.begin() + i + 1);
			std::copy(tmp.begin(), tmp.end(), v.begin() + i - dist + 1);
		}
	}
}

size_t PmergeMe::dichotomyInsetrionVector(std::vector<int> &v, int key, int start, int end, int step)
/*
Use dichotomique search to find where to insert key
*/
{
	size_t i;
	int size = end - start + 1;
	
	int nbGroupes = size/step;
	
	if (nbGroupes <= 1) //stop condition
	{
		if (key > v[start + step - 1] )
			return start + step;
		return start;
	}
	
	i = start + (nbGroupes / 2) * step - 1;
	if (key < v[i])
		return dichotomyInsetrionVector(v, key, start, i - step, step);
	else
		return dichotomyInsetrionVector(v, key, i + 1, end, step);
}

void PmergeMe::insertExcludeVector(std::vector<int> &v, std::vector<int> &alone, int step)
/*
insert elem that had no mate
*/
{
	if (alone.size())
	{
		for (size_t i = step - 1; i < alone.size(); i += step)
		{
			size_t place = dichotomyInsetrionVector(v, alone[i], 0, v.size() - 1, step);
			v.insert(v.begin() + place, alone.begin() + i - (step - 1), alone.begin() + i + 1);
			
		}
	}
}

void PmergeMe::insertSmallerVector(std::vector<int> &v, std::vector<int> &smaller, int step)
/*
insert smaller element of each pair into sorted vector
*/
{
	size_t place;
	size_t i;
	size_t keyIndice;
	std::vector<int> insertionOrder;
	int bigger = 0;
	int alreadyInserted = 0;
	getJacobsthalOrder(insertionOrder, smaller.size()/ step);


	for (std::vector<int>::iterator toInsert = insertionOrder.begin(); toInsert != insertionOrder.end(); toInsert++)
	{
		i = (*toInsert) * step;
		keyIndice = i + step - 1;
		if (keyIndice >= smaller.size())
			continue;
		
		place = dichotomyInsetrionVector(v, smaller[keyIndice], 0, keyIndice + alreadyInserted * step - bigger * step, step);
		v.insert(v.begin() + place, smaller.begin() + i, smaller.begin() + keyIndice + 1);	
		if (smaller[keyIndice] >= v[keyIndice + alreadyInserted * step])
			bigger++;
		alreadyInserted++;
		if (toInsert != insertionOrder.begin() && *toInsert > *(toInsert-1))
			bigger = 0;
	}
		
	
}


void PmergeMe::fordJonhsonVector(std::vector<int> &v, int groupSize)
/*
Implements Ford Jonhson algorithme
*/
{
	
	//represent step between significatif elem in paires
	int step = groupSize/2;
	if (v.size() / groupSize < 1) //=> vector is sortVectored
		return;
		
	
	std::vector<int> alone;
	excludeElemVector(v, alone, groupSize);
	//create and sort pair 
	sortGroupVector(v, step);
	
	
	//call ford johnson to sort the vector by biggest elem of each pair
	fordJonhsonVector(v, groupSize * 2);

	//stop condition (a list only 1 element is always sorted)
	groupSize/= 2;
	step = groupSize/2;
	if (!step)
		return;

	//insert smaller elments of each pair
	std::vector<int> smaller;
	excludeSmallerVector(v, smaller, step);
	insertSmallerVector(v, smaller, step);
	
	//insert elements that had no match
	insertExcludeVector(v, alone, step);
}

void PmergeMe::sortList()
{
	if (_lst.size() < 2)
		return ;
	fordJonhsonList(_lst, 2);
}

std::list<int>::iterator PmergeMe::getListIterator(std::list<int> lst, int move)
{
	std::list<int>::iterator it = lst.begin();
	std::advance(it, move);
    return it;
}

std::list<int>::iterator next(std::list<int>::iterator it, int step)
{
    
	// if (step)
	// {
	// 	std::advance(it, step);
	// 	return it;
	// }
	// }
	// if (step > 0)
	// {
	while (++step < 0)
		it--;
	while (--step > 0)
		it++;
    
    return (it);
}

void PmergeMe::fordJonhsonList(std::list<int> &l, int groupSize)
{
	int step = groupSize/2;
	if (l.size() / groupSize < 1)
		return;
		
	std::list<int> alone;
	excludeElemList(l, alone, groupSize);
	sortGroupList(l, step);
	fordJonhsonList(l, groupSize * 2);
	groupSize/= 2;
	step = groupSize/2;
	if (!step)
	{
		insertExcludeList(l, alone, 1);
		return;
	}
	std::list<int> smaller;
	excludeSmallerList(l, smaller, step);
	insertSmallerList(l, smaller, step);
	insertExcludeList(l, alone, step);
}

void PmergeMe::excludeElemList(std::list<int> &l, std::list<int> &alone, int range)
{
	if (l.size() % range)
	{
		alone.insert(alone.begin(), next(l.end(), - (l.size() % range + 1)), l.end());
		l.erase(next(l.end(), - (l.size() % range + 1)), l.end());
	}
}

void PmergeMe::excludeSmallerList(std::list<int> &l, std::list<int> &smaller, int step)
{
	for (size_t i = 0; i < l.size() && step > 0; i += step)
    {
        smaller.insert(smaller.end(), next(l.begin(), i),next(l.begin(), i + step));
        l.erase(next(l.begin(), i),next(l.begin(), i + step));
    }
}

void PmergeMe::insertExcludeList(std::list<int> &l, std::list<int> &alone, int step)
{
	if (alone.size())
	{
		for (size_t i = step - 1; i < alone.size(); i += step)
		{
			size_t place = dichotomyInsetrionList(l, *next(alone.begin(), i), 0, l.size() - 1, step);
			l.insert(next(l.begin(), place), next( alone.begin(), i - (step - 1)), next( alone.begin(),i + 1));
			
		}
	}
}

void PmergeMe::insertSmallerList(std::list<int> &l, std::list<int> &smaller, int step)
{
	size_t place;
	size_t i;
	size_t keyIndice;
	std::vector<int> insertionOrder;
	int bigger = 0;
	int alreadyInserted = 0;
	getJacobsthalOrder(insertionOrder, smaller.size()/ step);


	for (std::vector<int>::iterator toInsert = insertionOrder.begin(); toInsert != insertionOrder.end(); toInsert++)
	{
		i = (*toInsert) * step;
		keyIndice = i + step - 1;
		if (keyIndice >= smaller.size())
			continue;
		
		place = dichotomyInsetrionList(l,*next(smaller.begin(), keyIndice), 0, keyIndice + alreadyInserted * step - bigger * step, step);
		l.insert(next(l.begin(), place) , next(smaller.begin(), i), next(smaller.begin(), keyIndice+1) );	
		if (*next(smaller.begin(), keyIndice) >= *next(l.begin(),keyIndice + alreadyInserted * step))
			bigger++;
		alreadyInserted++;
		if (toInsert != insertionOrder.begin() && *toInsert > *(toInsert-1))
			bigger = 0;
	}
}



void PmergeMe::swap_range_list(std::list<int> &lst, int first, int second, int size)
{
    std::list<int>::iterator itFirst = lst.begin();
	std::advance(itFirst, first);

    std::list<int>::iterator itSecond = lst.begin();
	std::advance(itSecond, second);

    std::list<int> tmp(itSecond, next(itSecond, size));
    std::copy(itFirst, next(itFirst, size), itSecond);
    std::copy(tmp.begin(), tmp.end(), itFirst);
}

void PmergeMe::sortGroupList(std::list<int> &l, int dist)
{
	for (size_t i = dist - 1; i + dist < l.size(); i += 2 * dist)
	{
		if (*getListIterator(l, i) > *getListIterator(l, i + dist) )
		{
			swap_range_list(l, i - (dist - 1), i + 1, dist);
			
		}
	}
}



size_t PmergeMe::dichotomyInsetrionList(std::list<int> &l, int key, int start, int end, int step)
{
	size_t i;
	int size = end - start + 1;
	
	int nbGroupes = size/step;
	
	if (nbGroupes <= 1) //stop condition
	{
		if (key > *getListIterator(l, start + step - 1))
			return start + step;
		return start;
	}
	
	i = start + (nbGroupes / 2) * step - 1;
	if (key <*getListIterator(l, i))
		return dichotomyInsetrionList(l, key, start, i - step, step);
	else
		return dichotomyInsetrionList(l, key, i + 1, end, step);
}


PmergeMe::~PmergeMe()
{
}
