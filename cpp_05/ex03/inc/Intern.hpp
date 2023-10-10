/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:07:13 by srapin            #+#    #+#             */
/*   Updated: 2023/10/09 22:09:26 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN
#define INTERN

#include "AForm.hpp"

class Intern
{
	protected:

	public:
		Intern();
        Intern(const Intern& other);
        virtual ~Intern();
        Intern &operator=(const Intern& other);
        AForm *makeForm(std::string formType, std::string formTarget);
		
};

#endif