/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:51 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/06 17:31:45 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define LOWEST 150
#define HIGHEST 1

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string	_name;
		bool 		_isSigned;
		int 		_gradeSign;
		int			_gradeExecute;

	public:
		Form();
		Form(const std::string name,const int gradeSign, const int gradeExecute);
		Form(const Form &);
		Form &operator=(const Form &);
		~Form();

		const std::string	getName() const;
		bool 				getIsSigned();
		int 			getGradeSign() const;
		int			getGradeExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		void beSigned(Bureaucrat const &);
};

std::ostream &operator<<(std::ostream & o, const Form &cpy);
