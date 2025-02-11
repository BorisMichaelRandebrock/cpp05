/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:51 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/12 15:39:57 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "colors.hpp"

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool 		_isSigned;
		const int	_gradeSign;
		const int	_gradeExecute;

	public:
		AForm();
		AForm(const std::string name,const int gradeSign, const int gradeExecute);
		AForm(const AForm &);
		AForm &operator=(const AForm &);
		virtual ~AForm();

		const std::string	getName() const;
		bool 				getIsSigned() const;
		int 				getGradeSign() const;
		int					getGradeExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

		void beSigned(Bureaucrat const &);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream & o, const AForm &cpy);
