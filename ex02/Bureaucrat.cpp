/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/13 12:06:16 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Smith"), _grade(LOWEST) {
	std::cout << "A new office clerk has been employed at the lowest grade with default clerk constructor and with grade " << this->_grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "The Bureaucrat "<< BOLD << this->_name << " has been employed with level: " << this->_grade << "!" << RESET << std::endl;  
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy) {
	this->_grade = cpy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->_name << YELLOW << " has just lost its job as it has been deconstructed, rationalized & outsourced. " << RESET << std::endl;
}

const std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
	if (this->getGrade() <= HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->getGrade() >= LOWEST)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm &name) {
	name.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form) const {
	form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "This Bureaucrat is already at the top level..";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "This Bureaucrats grade is too low for the action required..";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &cpy) {
	o << cpy.getName() << ", bureaucrat grade " << cpy.getGrade() << ".";
    return o;
}
