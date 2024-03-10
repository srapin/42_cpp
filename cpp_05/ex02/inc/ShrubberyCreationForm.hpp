/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:46 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 14:10:32 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	protected:
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
		void execute(Bureaucrat const & executor) const;	
};

#endif