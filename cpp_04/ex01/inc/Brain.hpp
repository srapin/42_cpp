/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:46:59 by srapin            #+#    #+#             */
/*   Updated: 2023/10/02 01:25:26 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

class Brain
{
    public:
		Brain();
		Brain(const Brain& other);
		virtual ~Brain();
		Brain& operator=(const Brain& other);
        void copyIdeas(const Brain& other);
        
	// protected:
		std::string ideas[100];
    private:

};

#endif