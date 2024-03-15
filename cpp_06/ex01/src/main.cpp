/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:51:29 by srapin            #+#    #+#             */
/*   Updated: 2024/03/15 23:03:11 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialize.hpp"

int main(void)
{
	struct Data data = {42};
	std::cout << "Value before cast: " << data.val << std::endl;
	uintptr_t data_ptr = Serialize::serialize(&data);
	std::cout << "uintptr_t pointer: " << data_ptr << std::endl;
	Data* data2 = Serialize::deserialize(data_ptr);
	std::cout << "Value after cast: " << data2->val << std::endl;
	if (Serialize::deserialize(data_ptr) != &data)
		std::cout << "Error\n";
	return 0;
}