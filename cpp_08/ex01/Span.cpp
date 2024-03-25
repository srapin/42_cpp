/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:42:53 by srapin            #+#    #+#             */
/*   Updated: 2024/03/25 01:29:35 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _occupied(0), _vec()
{}

Span::Span(unsigned int n) : _n(n), _occupied(0), _vec() {}

Span::Span(const Span& other) : _n(other.getN()), _occupied(other.getOccupied()), _vec(other.getVec()) {}

Span& Span::operator=(const Span& other) { //todo->check deep copy
	_n = other.getN();
	_occupied = other.getOccupied();
	_vec = other.getVec();
	return *this;
}

void Span::addNumber(int i)
{
	updateOccupied();
	_vec.push_back(i);
	std::sort(_vec.begin(), _vec.end());
}

// void Span::addNumbers(  std::vector<int>::const_iterator& begin,  std::vector<int>::const_iterator& end)
void Span::addNumbers( const std::vector<int>::iterator& begin, const  std::vector<int>::iterator& end)
{
	for (std::vector<int>::iterator i = begin; i != end; i++)
	{
		addNumber(*i);
	}
	std::cout << "end of insertion" << std::endl;
}

void Span::updateOccupied()
{
	if (_occupied + 1 > _n)
		throw SpanIsFull();
	_occupied++;
}

const char *Span::SpanIsFull::what() const throw()
{
	return "Span is full";
}

const char *Span::SpanTooShort::what() const throw()
{
	return "Span is too short, distance is not defined";
}
unsigned int Span::getN() const
{
	return (_n);
}
unsigned int Span::getOccupied() const 
{
	return (_occupied);
}
std::vector<int> Span::getVec() const 
{
	return (_vec);
}

void Span::checkDist() const
{
	if (_occupied < 2)
		throw SpanTooShort();
}


unsigned int Span::shortestSpan() const
{
	unsigned int min_dist = INT_MAX;
	std::vector<int>::const_iterator prev_it = _vec.begin();
	
	checkDist();
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end();  it++)
	{
		if (prev_it != it && std::abs(*it - *prev_it) < (min_dist))
			min_dist = std::abs(*it - *prev_it);
		prev_it = it;
	}
	return (min_dist);
}

unsigned int Span::longestSpan() const
{
	checkDist();
	int max = *std::max_element(this->_vec.begin(), this->_vec.end());
	int min = *std::min_element(this->_vec.begin(), this->_vec.end());
	return std::abs(max - min);
}

Span::~Span()
{
}