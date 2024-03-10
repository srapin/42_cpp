/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:21 by srapin            #+#    #+#             */
/*   Updated: 2024/03/05 17:32:11 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM
#define AFORM

#include "Bureaucrat.hpp"
#include<string>
class Bureaucrat;

class AForm
{
	public:
		//Canonique
        AForm(const AForm& other);
        virtual ~AForm();
        AForm &operator=(const AForm& other);
		

		//Getter
		std::string getName() const;
		std::string getTarget() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		//Use
		void beSigned(const Bureaucrat bob);
		void checkExecutionCond(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual AForm *clone(std::string target) = 0;

		//Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	protected :
		AForm(std::string name, std::string target, int toSign, int toExe);
		std::string const _name;
		std::string _target;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecut;
	private:
		AForm();
};

std::ostream & operator << (std::ostream &out, const AForm &b);

#endif