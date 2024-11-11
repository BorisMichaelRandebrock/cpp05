/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:51 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/11 13:48:37 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PlanetaryRelocationForm.hpp"
#include "colors.hpp"

#define LOWEST 150
#define HIGHEST 1

enum	Options {
	PARDON,
	ROBOTOMY,
	SHRUBBERY,
	RELOCATE,
	WRONG_REQUEST
};
/*
   Options stringEnum(const std::string &input) {
   if (input == "presidential pardon request") return PARDON;
   else if (input == "robotomy request") return ROBOTOMY;
   else if (input == "shrubbery request") return SHRUBBERY;
   else if (input == "relocation request") return RELOCATE;
   else return WRONG_REQUEST;
   }
   */
class AForm;
Options stringEnum(const std::string &input);


class Intern {
	private:

	public:
		Intern();
		Intern(const Intern &);
		Intern &operator=(const Intern &);
		~Intern();
		AForm *makeForm(std::string form, std::string target) const;

		class InsufficientDataException : public std::exception {
			public:
				const char* what() const throw();
		};
		class WrongRequestException : public std::exception {
			public:
				const char* what() const throw();
		};
};

//std::ostream &operator<<(std::ostream & o, const Intern &cpy);
