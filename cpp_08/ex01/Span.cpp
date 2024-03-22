/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:42:53 by srapin            #+#    #+#             */
/*   Updated: 2024/03/22 18:16:52 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _occupied(0), _vec()
{}

Span::Span(unsigned int n) : _n(n), _occupied(0), _vec() {}

Span::Span(const Span& other) : _n(other.getN()), _occupied(other.getOccupied()) {}

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

void Span::addNumbers(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	for (std::vector<int>::iterator i = begin; begin != end; i++)
		addNumber(*i);
}

void Span::updateOccupied()
{
	if (_occupied + 1 > _n)
		throw SpanIsFull();
	_occupied ++;
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
	unsigned int min_dist = INT32_MAX;
	int prev_i;
	bool first_elem = true;
	checkDist();
	for (int i : _vec)
	{
		if (!first_elem && abs(i - prev_i) < min_dist)
			min_dist = abs(i - prev_i);
		first_elem = false;
		prev_i = i;
	}
	return (min_dist);
}

unsigned int Span::longestSpan() const
{
	checkDist();
	return (abs(_vec[_vec.size() - 1] - _vec[0]));
}

Span::~Span()
{
    //std::cout << "Span: Destructor" << std::endl;
}