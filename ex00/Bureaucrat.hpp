/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:51 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/05 13:52:30 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat {
	private:
		std::string	_name;
		int 		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();

		const std::string	getName() const;
		int	getGrade();


		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		/*		class GradeTooLowException : public std::exception {
				public:
				const char *what() const throw();
						};*/
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw(); // Forward declaration only
		};
};

std::ostream &operator<<(std::ostream & o, const Bureaucrat &cpy);
