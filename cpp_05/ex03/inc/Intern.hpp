/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:55:50 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 19:26:22 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN
#define INTERN

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// typedef AForm *(*funcPtr)(std::string target);

class Intern
{
	protected:

	public:
		Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern &operator=(const Intern& other);
        AForm *makeForm(std::string formType, std::string formTarget);

        class FormNotFound : public std::exception
		{
			public:
				const char *what() const throw();
		};
    private :
        AForm *forms[3];
        static AForm *makePresidentialPardonForm(std::string target);
        static AForm *makeShrubberyCreationForm(std::string target);
        static AForm*makeRobotomyRequestForm(std::string target);
        
};

#endif