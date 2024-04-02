/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:39 by srapin            #+#    #+#             */
/*   Updated: 2024/04/02 02:24:02 by srapin           ###   ########.fr       */
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
	sort();
	std::cout  << std::endl;
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
	// fordJonhson(0, _vec.size() - 1, 2);
}

// . Apairrer: [(7, 8), (5, 9), (11, 0), (2, 1), (10, 3), (4, 6)] ->taille = 2
// . Comparer*: [8, 9, 11, 2, 10, 6] et... Récursion (on va trier cette nouvelle liste de la même manière que la première, donc une bullet en plus, mais la récursion, c'est la phase 2 de l'algo: on reprendra pour la phase 3 quand l'appel récursif suivant me renverra cette liste triée):
// .. Apairrer: [(8, 9), (11, 2), (10, 6)]
// .. Comparer**: [9, 11, 10] et... Récursion:
// ... Apairrer: [(9 , 11)] je peux pas faire de paire avec le 10, je le garde pour plus tard.
// ... Comparer***: [11] et... Récursion:
// .... Critère d'arrêt atteint (liste de taille 1): je retourne la liste [11]... Et je commence à "remonter" ma chaîne d'appels (je repasse à 3 bullets).
// ... Insérer: l'élément appairé à 11, le 9**, j'ai la liste [9, 11]. J'insère le 10 que je m'étais gardé pour plus tard et je retourne la liste [9, 10, 11]
// .. Insérer: d'abord l'élément appairé au plus petit élément, 9, ici c'est 8*, j'ai la liste [8, 9]. Ensuite, j'insère l'élément apairré à 11, ici le 2 dans la liste [8, 9, 10] (en fait, dans la liste [8, 9, (10, 6)]...) , puis l'élément apairré à 10 (le 6) dans la liste [2, 8, 9]. Je retourne la liste [2, 6, 8, 9, 10, 11]
// . Insérer: d'abord l'élément appairé à 2, puis celui appairé à  8, suivi de celui appairé à 6, ensuite celui appairé à  10, suivi de celui à 9, puis à 11 (suivant Jacobsthal...) et j'ai la liste [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] à renvoyer. 

/// @brief move elem that can not be paired
void PmergeMe::excludeElem(std::vector<int> &v, std::vector<int> & alone, int groupSize)
{
	if (v.size() % groupSize) //-> some elem won t have a match
	{
		alone.insert(alone.begin(), v.end() - v.size() % groupSize, v.end());
		v.erase(v.end() - v.size() % groupSize, v.end());
	}
}
/// @brief 
/// @param v 
/// @param dist  rpz distance between significatif elem
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

int PmergeMe::jacobsthalNumber(int n)
{
	if (n <= 1)
		return (n);
	return (2 * jacobsthalNumber(n - 2) + jacobsthalNumber(n - 1));
}

void PmergeMe::exchangeGroup(int f, int s, int groupSize)
{
	if (_vec[f] > _vec[s])
	{
		for (int i = 0; i < groupSize; i++)
			std::swap(_vec[f - i], _vec[s - i]);
	}
}

size_t dichotomyInsetrion(std::vector<int> &v, int key, int start, int end, int gap)
{
	size_t i;
	int size = end - start + 1;
	int nbGroupes = size/gap;
	// std::cout << "nb group" << nbGroupes << " size " << size << " gap " << gap << std::endl;
	
	if (nbGroupes <= 1) //return
	{
		if (key > v[start + gap - 1] )
			return start + gap;
		return start;
	}
	i = start + (nbGroupes / 2) * gap - 1;
	if (key < v[i])
		return dichotomyInsetrion(v, key, start, i-gap, gap);
	else
		return dichotomyInsetrion(v, key, i + 1, end, gap);
}

void PmergeMe::fordJonhson(std::vector<int> &v, int groupSize)
{
	std::vector<int> alone; //elem that have no friend
	if (v.size() / groupSize < 1) //=> vector is sorted
		return;
	excludeElem(v, alone, groupSize);
	sortGroup(v, groupSize / 2);
	fordJonhson(v, groupSize * 2);
	groupSize/= 2;

	std::vector<int> smaller; //small nb of each pair
	for (size_t i = 0; i < v.size() && groupSize/ 2 > 0; i += groupSize/2)
    {
        smaller.insert(smaller.end(), v.begin() + i, v.begin() + i + groupSize/2);
        v.erase(v.begin() + i, v.begin() + i + groupSize / 2 );
    }
	
	
	size_t place;	
	int prevJac = -1;
	int currentJac = jacobsthalNumber(3);
	int i = currentJac;
	int jacCount = 4;
	
	
	do
	{
		if (!smaller.size())
			break;
		while((size_t) i * groupSize/2 + groupSize/2 > smaller.size())
			i--;
		for (; i > prevJac; i--)
		{
			place = dichotomyInsetrion(v, smaller[i * groupSize/2 + groupSize/2 - 1], 0, v.size() - 1, groupSize /2);
			v.insert(v.begin() + place, smaller.begin() + i * groupSize/2, smaller.begin() + i * groupSize/2 + groupSize/2);	
		}
		prevJac = currentJac;
		currentJac = jacobsthalNumber(jacCount);
		i = currentJac;
		jacCount++;
	} while((size_t) prevJac * groupSize/2 + groupSize/2 < smaller.size());
	
	if (alone.size())
	{
		place = dichotomyInsetrion(v, alone[alone.size() - 1], 0, v.size() - 1, groupSize /2);
		v.insert(v.begin() + place, alone.begin(), alone.end());
	}
	std::cout << "    //   ";
}




void PmergeMe::sort2elem(int f, int s)
{
	// int j = 0;
	// for (size_t i = groupSize/2 - 1; i < v.size(); i+= groupSize/2)
	// {
	// 	if (!(j % 2))
	// 		std::cout << "(";
	// 	std::cout << v[i];
	// 	if (j % 2)
	// 		std::cout << ")";
	// 	std::cout << " ";
	// 	j++;
	// }
	// std::cout << "    " <<  groupSize << std::endl;
	if (_vec[f] > _vec[s])
		std::swap(_vec[f], _vec[s]);
}



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
