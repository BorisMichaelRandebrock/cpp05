/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/13 12:03:18 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Basic Form"), _isSigned(false), _gradeSign(LOWEST), _gradeExecute(LOWEST) {
	std::cout << "Default constuctor has created a new form with minimum requirements for signature & execution." << std::endl;
}


Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	this->_isSigned = false;
	if (gradeSign < HIGHEST || gradeSign > LOWEST)
		throw Form::GradeTooHighException();
	else if (gradeExecute < HIGHEST || gradeExecute > LOWEST)
		throw Form::GradeTooLowException();
	std::cout << "The Form "<< BOLD << this->_name << RESET << " has been created with required signature level of: " << this->_gradeSign << " and required execution level of: " << this->_gradeExecute << std::endl;  
}
/*
Form::Form(const Form &cpy) {
	*this = cpy; this can not be here as _nam, _gradeSign and _gradeExecute are const
}*/
Form::Form(const Form &cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeSign(cpy._gradeSign), _gradeExecute(cpy._gradeExecute) {
    // Correction: initialize _name, _gradeSign, and _gradeExecute in initializer list
}

Form &Form::operator=(const Form &cpy) {
	this->_isSigned = cpy._isSigned;
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
		std::cout << RED << name.getName() << " could not sign " << this->getName() << " because : " << RESET;
		throw GradeTooLowException();
	}
	else {
		this->_isSigned = true;
		std::cout << "The Bureaucrat " << name.getName() << " signed " << this->_name << "." <<std::endl; 
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
