/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:46 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 14:08:32 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	protected:
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
		void execute(Bureaucrat const & executor) const;	
};

#endif