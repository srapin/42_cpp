/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:35 by srapin            #+#    #+#             */
/*   Updated: 2024/04/20 23:00:04 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stack>

#ifndef RRP_HPP
#define RRP_HPP

#include <stdlib.h>
#define NBRS "0123456789"
#define OPS "+-*/"

class RPN
{
    private:
        std::stack<int> _s;
	protected:

	public:
		RPN();
		RPN(std::string str);
        RPN(const RPN& other);
        ~RPN();
        RPN &operator=(const RPN& other);
        void doOps(char );
	
};

#endif