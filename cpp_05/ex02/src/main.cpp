/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:10 by srapin            #+#    #+#             */
/*   Updated: 2023/10/05 19:05:38 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("B1", 150);
         f1("F1", 90, 160);
        std::cout << b1 << std::endl;
        std::cout << "Before f1 being signed "<< f1 << std::endl;
        b1.signAform(f1);
        std::cout << "After f1 being signed "<< f1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Grade out of range " << std::endl;
    }
    
    try
    {
        Bureaucrat b2("B2", 150);
        Aform f2("F2", 150, 150);

        std::cout << b2 << std::endl;
        std::cout << f2 << std::endl;
        b2.signAform(f2);
		f2.beSigned(b2);
        std::cout << f2 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Grade out of range " << std::endl;
    }

    return (0);
}