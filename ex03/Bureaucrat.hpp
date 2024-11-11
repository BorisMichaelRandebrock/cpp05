/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:51 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/07 17:29:05 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "colors.hpp"

#define LOWEST 150
#define HIGHEST 1


class AForm;

class Bureaucrat {
	private:
		std::string	_name;
		int 		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();

		const std::string	getName() const;
		int	getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &);
		void executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, const Bureaucrat &cpy);
