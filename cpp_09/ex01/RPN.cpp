/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:31 by srapin            #+#    #+#             */
/*   Updated: 2024/03/28 10:34:18 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(/* args */)
{
	std::cout << "RPN: Default constructor" << std::endl;
}

RPN::RPN(std::string str) : _s()
{
	for (size_t i = 0; i < str.size(); i += 2)
	{
		if (isdigit(str[i]))
			_s.push(atoi(&str[i]));
		else
			doOps(str[i]);
		// std::cout << str[i] << ' ';
	}
	std::cout << "res = " << _s.top() << std::endl;
}

RPN::RPN(const RPN &other)
{
	(void)other;
	std::cout << "RPN: Copy constructor" << std::endl;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	std::cout << "RPN: Assignment operator" << std::endl;
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
			if (f)
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
	std::cout << "RPN: Destructor" << std::endl;
}