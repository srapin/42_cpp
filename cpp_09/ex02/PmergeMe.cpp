/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:19:39 by srapin            #+#    #+#             */
/*   Updated: 2024/03/30 18:10:09 by srapin           ###   ########.fr       */
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

void PmergeMe::exchangeGroup(int f, int s, int groupSize)
{
	if (_vec[f] > _vec[s])
	{
		for (int i = 0; i < groupSize; i++)
			std::swap(_vec[f - i], _vec[s - i]);
	}
}

void PmergeMe::fordJonhson(std::vector<int> &v, int groupSize)
{
	std::vector<int> alone; //elem that have no friend
	if (v.size() / groupSize < 1) //=> vector is sorted
		return;
	excludeElem(v, alone, groupSize);
	sortGroup(v, groupSize / 2);
	fordJonhson(v, groupSize * 2);
	
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << "    " <<  groupSize << std::endl;
}

//( 1 2) (3 4 ) (5 6 ) (7 8 )9

// void PmergeMe::fordJonhson(int start, int end, int groupSize)
// {
	
// 	if (start >= end)
// 		return ;
// 	for (int i = start; i < end; i += groupSize)
// 		sort2elem(i, i + 1);
// 	fordJonhson(start, end, groupSize *2);
	
// 	sortPaires(0, _vec.size() - 2);
// }



void PmergeMe::sort2elem(int f, int s)
{
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

// b1 a1 a2
//b2?