/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:21 by srapin            #+#    #+#             */
/*   Updated: 2023/10/05 17:07:53 by srapin           ###   ########.fr       */
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
		AForm(std::string name, std::string target, int toSign, int toExe);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm &operator=(const AForm& other);
		std::string getName() const;
		std::string getTarget() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat bob);
		void checkExecutionCond(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
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
	protected:
		std::string _target;
	private:
		std::string const _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecut;
};

std::ostream & operator << (std::ostream &out, const AForm &f);
// {
// 	out << "Form_name =" << f;
// 	return out;
// }

#endif