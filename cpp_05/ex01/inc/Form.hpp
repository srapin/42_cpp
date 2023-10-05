/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:21 by srapin            #+#    #+#             */
/*   Updated: 2023/10/04 22:31:35 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
#define FORM

#include "Bureaucrat.hpp"
#include<string>
class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int toSign, int toExe);
        Form(const Form& other);
        virtual ~Form();
        Form &operator=(const Form& other);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat bob);
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
	private:
		std::string const _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecut;
};

std::ostream & operator << (std::ostream &out, const Form &b);

#endif