/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:39 by srapin            #+#    #+#             */
/*   Updated: 2024/04/05 22:03:37 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	_startTime = clock();
	// std::cout << "Before : ";
	// for (int i = 0; i < ac; i++)
	// {
	// 	_vec.push_back(atoi(av[i]));
	// 	std::cout << _vec[i] << " ";
	// }
	// sortVector();
	// std::cout << "After : \n";
	// for (size_t i = 0; i < _vec.size(); i++)
	// {
	// 	std::cout << _vec[i] <<  " ";
	// 	if ((i && _vec[i] < _vec[i - 1]))
	// 		return;
	// }
	// std::cout  << std::endl;
	// std::cout << "Time to process a range of "<< ac <<" elements with std::vector : " << clock() - _startTime << " us\n";
	// 	std::cout << _vec.size() << "  " << ac;
	for (int i = 0; i < ac; i++)
	{
		_lst.push_back(atoi(av[i]));
		std::cout << *getListIterator(_lst, i) << " ";
	}
	std::cout << std::endl;
	sortList();
	for (int i = 0; i < ac; i++)
	{
		std::cout << *getListIterator(_lst, i) << " ";
		if ((i && *getListIterator(_lst, i) < *getListIterator(_lst, i- 1)))
		{
			std::cout << "oup<\n";
			return;
		}
	}
	std::cout <<std::endl << _lst.size() << "  " << ac;
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

void PmergeMe::sortVector()
{
	if (_vec.size() < 2)
		return ;
	fordJonhsonVector(_vec, 2);
}

/// @brief move elem that can not be paired
void PmergeMe::excludeElemVector(std::vector<int> &v, std::vector<int> & alone, int groupSize)
{
	if (v.size() % groupSize) //-> some elem won t have a match
	{
		alone.insert(alone.begin(), v.end() - v.size() % groupSize, v.end());
		v.erase(v.end() - v.size() % groupSize, v.end());
	}
}

void PmergeMe::excludeSmallerVector(std::vector<int> &v, std::vector<int> &smaller, int step)
{
	for (size_t i = 0; i < v.size() && step > 0; i += step)
    {
        smaller.insert(smaller.end(), v.begin() + i, v.begin() + i + step);
        v.erase(v.begin() + i, v.begin() + i + step);
    }
}


//sortVector pair
void PmergeMe::sortGroupVector(std::vector<int> &v, int dist)
{
	for (size_t i = dist - 1; i + dist < v.size(); i += 2 * dist)
	{
		if (v[i] > v[i + dist])
		{
			//swap groups
			std::vector<int> tmp(v.begin() + i + 1, v.begin() + i + dist + 1);
			std::copy(v.begin() + i - dist + 1, v.begin() + i + 1,  v.begin() + i + 1);
			std::copy(tmp.begin(), tmp.end(), v.begin() + i - dist + 1);
		}
	}
}

//return neme jacobstal number
int PmergeMe::jacobsthalNumber(int n)
{
	if (n <= 1)
		return (n);
	return (2 * jacobsthalNumber(n - 2) + jacobsthalNumber(n - 1));
}

void PmergeMe::getJacobsthalOrder(std::vector<int> &v, int size)
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

	// while(move--);
	// 	it++;
    return it;
}

std::list<int>::iterator next(std::list<int>::iterator it, int step)
{
    
	while (++step < 0)
		it--;
	while (--step > 0)
		it++;
    
    return (it);
}

void PmergeMe::fordJonhsonList(std::list<int> &l, int groupSize)
{
	int step = groupSize/2;
	if (l.size() / groupSize < 1) //=> vector is sortVectored
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
	
	// std::vector<int> alone; //elem that have no friend
	


	// insertExcludeVector(v, alone, step);
}

void PmergeMe::excludeElemList(std::list<int> &l, std::list<int> &alone, int range)
{
	if (l.size() % range) //-> some elem won t have a match
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
			// int j = *(alone.begin() + i- (step - 1));
			l.insert(next(l.begin(), place), next( alone.begin(), i - (step - 1)),next( alone.begin(),i + 1));
			
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
		
		// i - pair + (already_put * pair) - (count_bigger * pair)
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
    // swap_range_list(list, i - pair + 1, i, i + 1, i + pair);
    std::list<int>::iterator itFirst = lst.begin();
	std::advance(itFirst, first);

    std::list<int>::iterator itSecond = lst.begin(); // getListIterator(lst, start2);
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

//find where to insert a group
size_t PmergeMe::dichotomyInsetrionVector(std::vector<int> &v, int key, int start, int end, int step)
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

void PmergeMe::insertExcludeVector(std::vector<int> &v, std::vector<int> &alone, int step)
{
	if (alone.size())
	{
		for (size_t i = step - 1; i < alone.size(); i += step)
		{
			size_t place = dichotomyInsetrionVector(v, alone[i], 0, v.size() - 1, step);
			// int j = *(alone.begin() + i- (step - 1));
			v.insert(v.begin() + place, alone.begin() + i - (step - 1), alone.begin() + i + 1);
			
		}
	}
}


void PmergeMe::insertSmallerVector(std::vector<int> &v, std::vector<int> &smaller, int step)
{
	size_t place;
	size_t i;
	size_t keyIndice;
	std::vector<int> insertionOrder;
	int bigger = 0;
	int alreadyInserted = 0;
	getJacobsthalOrder(insertionOrder, smaller.size()/ step);
	// insertionOrder.clear();
	// for (int i = 0; i < smaller.size()/step; i++)
	// 	insertionOrder.push_back(i);


	for (std::vector<int>::iterator toInsert = insertionOrder.begin(); toInsert != insertionOrder.end(); toInsert++)
	{
		i = (*toInsert) * step;
		keyIndice = i + step - 1;
		if (keyIndice >= smaller.size())
			continue;
		
		// i - pair + (already_put * pair) - (count_bigger * pair)
		place = dichotomyInsetrionVector(v, smaller[keyIndice], 0, keyIndice + alreadyInserted * step - bigger * step, step);
		v.insert(v.begin() + place, smaller.begin() + i, smaller.begin() + keyIndice + 1);	
		if (smaller[keyIndice] >= v[keyIndice + alreadyInserted * step])
			bigger++;
		alreadyInserted++;
		if (toInsert != insertionOrder.begin() && *toInsert > *(toInsert-1))
			bigger = 0;
	}
		
	
}


//exectue fordJonhsonVectorAlgorithme
void PmergeMe::fordJonhsonVector(std::vector<int> &v, int groupSize)
{
	
	//represent step between significatif elem in paires
	int step = groupSize/2;
	if (v.size() / groupSize < 1) //=> vector is sortVectored
		return;
		
	std::vector<int> alone; //elem that have no friend
	excludeElemVector(v, alone, groupSize);
	sortGroupVector(v, step);
	
	fordJonhsonVector(v, groupSize * 2);

	groupSize/= 2;
	step = groupSize/2;
	if (!step)
		return;

	std::vector<int> smaller;
	excludeSmallerVector(v, smaller, step);
	insertSmallerVector(v, smaller, step);
	insertExcludeVector(v, alone, step);
}


PmergeMe::~PmergeMe()
{
}
