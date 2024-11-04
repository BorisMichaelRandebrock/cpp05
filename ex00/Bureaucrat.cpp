/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/04 17:45:58 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST) {
	std::cout << "default constructor called with " << this->_grade << " level." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade &grade) : _name(name)/*, _grade(grade) */{
	try {
		this->_grade = grade
	//	this->_grade = setGrade(grade);
	}
	catch (std::exception &GradeTooHighException){
		throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception  &GradeTooLowException) {
		throw  Bureaucrat::GradeTooLowException();
	}
	std::cout << this->_name << " bureaucrat has been constructed with level: " << this->_grade << "!" << std::endl;  
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
	*this = cpy;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy) {
	this->_name = cpy._name;
	this->_grade = cpy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->_name << " has just lost his job as it has been deeconstructed and rationalized.. " << std::endl;
}

const std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() { return this->_grade; }

void Bureaucrat::incrementGrade() {
	try {
		this->_grade--;
	}
	catch (std::exception &GradeTooHighException) {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade() {
	try {
		this->_grade++;
	}
	catch (std::exception &GradeTooLowException) {
		throw Bureaucrat::GradeTooLowException();
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	if (this->_grade < LOWEST)
		return "This Bureaucrat is already at the top level..";
}

const char **Bureaucrat::GradeTooLowException::what() const throw() {
	if (this->_grade > HIGHEST)
		return "This Bureaucrat can not be demoted any further..";
}
//std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);
/*std::ostream &operator<<(std::ostream &o, Bureaucrat *cpy) {
	o << cpy.getName() << ", bureaucrat grade " << cpy.getGrade() << ".";
    return o;
}*/
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}
