/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:05:16 by srapin            #+#    #+#             */
/*   Updated: 2024/03/05 17:31:53 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		Bureaucrat();
    public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat& other);
		virtual ~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string getName() const;
		int getGrade() const;
		Bureaucrat& operator++();
		Bureaucrat& operator--();
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

};

std::ostream & operator << (std::ostream &out, const Bureaucrat &b);
 


#endif