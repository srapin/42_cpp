/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:44:42 by srapin            #+#    #+#             */
/*   Updated: 2024/03/22 18:10:28 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _n;
		unsigned int _occupied;
		std::vector<int> _vec;
		Span();
		void updateOccupied();
		void checkDist() const;
		
	protected:
		unsigned int getN(void) const;
		unsigned int getOccupied(void) const;
		std::vector<int> getVec(void) const;
	
	public:
		Span(unsigned int n);
        Span(const Span& other);
        virtual ~Span();
        Span &operator=(const Span& other);
		void addNumber(int n);
		void addNumbers(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		unsigned int shortestSpan() const ;
		unsigned int longestSpan() const ;
		
		class SpanIsFull : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class SpanTooShort : public std::exception
		{
			public:
				const char *what() const throw();
		};;
		
};