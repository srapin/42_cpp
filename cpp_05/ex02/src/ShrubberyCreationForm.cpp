/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:39:26 by srapin            #+#    #+#             */
/*   Updated: 2023/10/05 19:19:14 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Default", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm: Copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	_target = other.getTarget();
	std::cout << "ShrubberyCreationForm: Assignment operator" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	file;
	
	checkExecutionCond(executor);

	file <<"				,@@@@@@@,"  << std::endl;
	file <<"		,,,.   ,@@@@@@/@@,  .oo8888o."  << std::endl;
	file <<"	,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file <<"	,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file <<"	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file <<"	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file <<"	`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file <<"		|o|        | |         | |" << std::endl;
	file <<"		|.|        | |         | |" << std::endl;
	file <<"	jgs \\ ._/_/__/  ,\\_//__/.  \\_//__/_" << std::endl;
	file.close();
}