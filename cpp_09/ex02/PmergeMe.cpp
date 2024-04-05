/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:39 by srapin            #+#    #+#             */
/*   Updated: 2024/04/05 18:18:15 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
	_startTime = clock();
	std::cout << "Before : ";
	for (int i = 0; i < ac; i++)
	{
		_vec.push_back(atoi(av[i]));
		std::cout << _vec[i] << " ";
	}
	sort();
	std::cout << "After : \n";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] <<  " ";
		if ((i && _vec[i] < _vec[i - 1]))// || _vec.size() != static_cast<long unsigned int>(ac))
			return;
	}
	// if (_vec.size() != (size_t) ac)
	std::cout  << std::endl;
	std::cout << "Time to process a range of "<< ac <<" elements with std::vector : " << clock() - _startTime << " us\n";
		std::cout << _vec.size() << "  " << ac;
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
	fordJonhson(_vec, 2);
}

/// @brief move elem that can not be paired
void PmergeMe::excludeElem(std::vector<int> &v, std::vector<int> & alone, int groupSize)
{
	if (v.size() % groupSize) //-> some elem won t have a match
	{
		alone.insert(alone.begin(), v.end() - v.size() % groupSize, v.end());
		v.erase(v.end() - v.size() % groupSize, v.end());
	}
}

void PmergeMe::excludeSmaller(std::vector<int> &v, std::vector<int> &smaller, int step)
{
	for (size_t i = 0; i < v.size() && step > 0; i += step)
    {
        smaller.insert(smaller.end(), v.begin() + i, v.begin() + i + step);
        v.erase(v.begin() + i, v.begin() + i + step);
    }
}


//sort pair
void PmergeMe::sortGroup(std::vector<int> &v, int dist)
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

//exchange two groupe of size groupSize
void PmergeMe::exchangeGroup(int f, int s, int groupSize)
{
	if (_vec[f] > _vec[s])
	{
		for (int i = 0; i < groupSize; i++)
			std::swap(_vec[f - i], _vec[s - i]);
	}
}


//find where to insert a group
size_t dichotomyInsetrion(std::vector<int> &v, int key, int start, int end, int step)
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
		return dichotomyInsetrion(v, key, start, i - step, step);
	else
		return dichotomyInsetrion(v, key, i + 1, end, step);
}


void PmergeMe::insertExclude(std::vector<int> &v, std::vector<int> &alone, int step)
{
	if (alone.size())
	{
		for (size_t i = step - 1; i < alone.size(); i += step)
		{
			size_t place = dichotomyInsetrion(v, alone[i], 0, v.size() - 1, step);
			// int j = *(alone.begin() + i- (step - 1));
			v.insert(v.begin() + place, alone.begin() + i - (step - 1), alone.begin() + i + 1);
			
		}
	}
}




void PmergeMe::insertSmaller(std::vector<int> &v, std::vector<int> &smaller, int step)
{
	size_t place;
	size_t i;
	size_t keyIndice;
	std::vector<int> insertionOrder;
	// smaller.size()/ step;
	// getJacobsthalOrder(insertionOrder, 80);
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
		
		place = dichotomyInsetrion(v, smaller[keyIndice], 0, v.size() - 1, step);
		v.insert(v.begin() + place, smaller.begin() + i, smaller.begin() + keyIndice + 1);	
		// if (smaller[i * step + step - 1] >= v[i + alreadyInsert * step])
		// 	bigger++;
		// alreadyInsert++;
		
	}
		
	
}


//exectue fordJonhsonAlgorithme
void PmergeMe::fordJonhson(std::vector<int> &v, int groupSize)
{
	
	//represent step between significatif elem in paires
	int step = groupSize/2;
	if (v.size() / groupSize < 1) //=> vector is sorted
		return;
		
	std::vector<int> alone; //elem that have no friend
	excludeElem(v, alone, groupSize);
	sortGroup(v, step);
	
	fordJonhson(v, groupSize * 2);

	groupSize/= 2;
	step = groupSize/2;
	if (!step)
		return;
	std::vector<int> smaller;
	excludeSmaller(v, smaller, step);
	insertSmaller(v, smaller, step);
	
	insertExclude(v, alone, step);
	
	std::cout << "    //   ";
}


PmergeMe::~PmergeMe()
{
}
