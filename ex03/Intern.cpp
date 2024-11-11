/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/11 13:54:34 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()  {
	std::cout << "A new intern has been employd." << std::endl;
}

Intern::Intern(const Intern &cpy) {
	*this = cpy;
}

Intern &Intern::operator=(const Intern &cpy) {
	(void)cpy;
	return *this;
}

Intern::~Intern() {
	std::cout << YELLOW << "A random intern has just lost its job as it has been deconstructed, rationalized & outsourced. " << RESET << std::endl;
}

AForm *Intern::makeForm(std::string form, std::string target) const {
	if (form.empty() || target.empty())
		throw Intern::InsufficientDataException();
	Options input = stringEnum(form);
	switch(input) {
		case PARDON:
			std::cout << "Random intern creates: "; 
			return new PresidentialPardonForm(target);
		case ROBOTOMY:
			std::cout << "Random intern creates: ";
			return new RobotomyRequestForm(target);
		case SHRUBBERY:
			std::cout << "Random intern creates: ";
			return new ShrubberyCreationForm(target);
		case RELOCATE:
			std::cout << "Random intern creates: ";
			return new PlanetaryRelocationForm(target);
		default:
			throw Intern::WrongRequestException(); 
	}
}

const char *Intern::InsufficientDataException::what() const throw() {
	return "There is either Form, or Target missing to be able to create an adequate form!";
}

const char *Intern::WrongRequestException::what() const throw() {
	return "Random intern: \033[1;33mI cannot find this formtype.. \033[0m \n";
}

Options stringEnum(const std::string &input) {
	if (input == "presidential pardon request") return PARDON;
	else if (input == "robotomy request") return ROBOTOMY;
	else if (input == "shrubbery request") return SHRUBBERY;
	else if (input == "relocation request") return RELOCATE;
	else return WRONG_REQUEST;
}

/*std::ostream &operator<<(std::ostream &o, Intern &cpy) {
	o << "New Intern.";
	(void)cpy;
    return o;
}*/
