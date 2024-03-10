/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:39:26 by srapin            #+#    #+#             */
/*   Updated: 2024/03/10 14:48:41 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", "Default", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm: Args constructor" << std::endl;
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
	checkExecutionCond(executor);
	std::string fileName = getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file)
		std::cerr << "could not open " << getTarget() + "_shrubbery" << std::endl;

	file <<"				,@@@@@@@,"  << std::endl;
	file <<"		,,,.   ,@@@@@@/@@,  .oo8888o."  << std::endl;
	file <<"	,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file <<"	,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file <<"	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file <<"	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file <<"	`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file <<"		|o|        | |         | |" << std::endl;
	file <<"		|.|        | |         | |" << std::endl;
	file.close();
}