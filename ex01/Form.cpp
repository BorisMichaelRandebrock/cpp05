/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/07 18:33:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Basic Form"), _isSigned(false), _gradeSign(LOWEST), _gradeExecute(LOWEST) {
	std::cout << "Default constuctor has created a new form with minimum requiremenst for signature & execution." << std::endl;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	this->_isSigned = false;
	if (gradeSign < HIGHEST || gradeSign > LOWEST)
		throw Form::GradeTooHighException();
	else if (gradeExecute < HIGHEST || gradeExecute > LOWEST)
		throw Form::GradeTooLowException();
	std::cout << "The Form "<< BOLD << this->_name << RESET << " has been created with required signature level of: " << this->_gradeSign << " and required execution level of: " << this->_gradeExecute << std::endl;  
}

Form::Form(const Form &cpy) {
	*this = cpy;
}

Form &Form::operator=(const Form &cpy) {
	this->_name = cpy._name;
	this->_isSigned = cpy._isSigned;
	this->_gradeSign = cpy._gradeSign;
	this->_gradeExecute = cpy._gradeExecute;
	return *this;
}

Form::~Form() {
	std::cout << this->_name << YELLOW << " has been shredded and burned!" << RESET << std::endl;
}

const std::string Form::getName() const { return this->_name; }

bool Form::getIsSigned() { return this->_isSigned; }
int Form::getGradeSign() const { return this->_gradeSign; }
int Form::getGradeExecute() const { return this->_gradeExecute; }

void Form::beSigned(Bureaucrat const &name) {
	if (this->_isSigned == true)
		std::cout << YELLOW << "You are too slow..., this form has already been signed." << RESET << std::endl;
	else if (this->_gradeSign < name.getGrade()) {
		std::cout << RED << name.getName() << " couldn’t sign " << this->getName() << " because : " << RESET;
		throw GradeTooLowException();
	}
	else {
		this->_isSigned = true;
		std::cout << "The Bureaucrat " << name.getName() << " signed " << this->_name << " Formular." <<std::endl; 
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "\033[1;33mThere is no higher level in ranking than level 1.\n \033[31mPlease enter a valid rank between 1 and 150!\033[0m \n";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "\033[1;33mGrade to low.\n \033[31mPlease call your supervisor to find a Bureaucrat with appropiate signature powers! \033[0m \n";
}

std::ostream &operator<<(std::ostream &o, Form &cpy) {
	o << cpy.getName() << std::endl;
	o << " Form," << " is signed " << cpy.getIsSigned() << std::endl;
	o << "Required signature grade: " << cpy.getGradeSign() << std::endl;
	o << "Required execution grade: " << cpy.getGradeExecute() << std::endl;
    return o;
}
