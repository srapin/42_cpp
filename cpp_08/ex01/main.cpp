/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:08:23 by srapin            #+#    #+#             */
/*   Updated: 2024/03/25 01:32:24 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

void bigSpanTest()
{
    {
        // std::vector<int>    v(10000);
        // std::generate( v.begin(), v.end(), std::rand );
        
        // Span span( v.size() );
        // std::cout << span.getN() << std::endl;;
        // span.addNumbers( v.begin(), v.end() );
        // std::cout << "Longest span: " << span.longestSpan() << std::endl;
        // std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    }
    {
        std::vector<int>    v;
        for (int i = 0; i < 10000; i++)
        {
            v.push_back(i * 3);
        }
        
        Span span( v.size() );
        
        span.addNumbers( v.begin(), v.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    }
}

int main()
{
    Span sp = Span(5);
    
    try
    {
        sp.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try
    {
        sp.addNumber(-4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    bigSpanTest();
    return 0;
}