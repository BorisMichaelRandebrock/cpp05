/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/12 14:02:28 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST) {
	std::cout << "A new office clerk has been employd at the lowest grade with default clerk constructor and with " << this->_grade << " grade." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "The Bureaucrat "<<BOLD << this->_name << RESET << " has been employed with level: " << this->_grade << "!" << std::endl;  
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy) {
	//this->_name = cpy._name; as this->_name is a const, it can not be copied
	this->_grade = cpy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->_name << YELLOW << " has just lost its job as it has been deconstructed, rationalized & outsourced. " << RESET << std::endl;
}

const std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() { return this->_grade; }

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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "This Bureaucrat is already at the top level..";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "This Bureaucrat can not be demoted any further..";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &cpy) {
	o << cpy.getName() << ", bureaucrat grade " << cpy.getGrade() << ".";
    return o;
}
