/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:46 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 14:09:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <stdlib.h> 

class RobotomyRequestForm : public AForm
{
	protected:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
		void execute(Bureaucrat const & executor) const;	
};

#endif