/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:31 by srapin            #+#    #+#             */
/*   Updated: 2024/04/20 23:04:26 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string str) : _s()
{
	for (size_t i = 0; i < str.size(); i += 2)
	{
		if (isdigit(str[i]))
			_s.push(atoi(&str[i]));
		else
			doOps(str[i]);
	}
	std::cout << "res = " << _s.top() << std::endl;
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

void RPN::doOps(const char c)
{
	if (_s.size() < 2)
	{
		std::cerr << "Error\n";
		exit(1);
	}
	int f = _s.top();
	_s.pop();
	int s = _s.top();
	_s.pop();
	switch (c)
	{
		case ('*'):
		{	
			_s.push(s * f);
			break;
		}
		case ('+'):
		{	
			_s.push(s + f);
			break;
		}
		case ('-'):
		{	
			_s.push(s - f);
			break;
		}
		case ('/'):
		{	
			if (f == 0)
			{
				std::cerr << "Division by zero\n";
				exit(1);
			}
			_s.push(s / f);
			break;
		}
		default:
		{
			std::cerr << "Error\n";
			exit(1);
		}
	}
}

RPN::~RPN()
{
}