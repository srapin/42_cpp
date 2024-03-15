/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:46:42 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 22:53:30 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "stdint.h"
#include "Data.hpp"

class Serialize
{

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
        ~Serialize();
	
	private:
		Serialize();
        Serialize(const Serialize& other);
        Serialize &operator=(const Serialize& other);
		
};