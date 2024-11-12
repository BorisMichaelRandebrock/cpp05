/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:30:01 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/12 15:57:52 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Basic AForm"), _isSigned(false), _gradeSign(LOWEST), _gradeExecute(LOWEST) {
	std::cout << "Default constuctor has created a new form with minimum requiremenst for signature & execution." << std::endl;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	this->_isSigned = false;
	if (gradeSign < HIGHEST || gradeSign > LOWEST)
		throw AForm::GradeTooHighException();
	else if (gradeExecute < HIGHEST || gradeExecute > LOWEST)
		throw AForm::GradeTooLowException();
	std::cout << "The Form "<< BOLD << this->_name << RESET << " has been created with required signature level of: " << this->_gradeSign << " and required execution level of: " << this->_gradeExecute << std::endl;  
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeSign(cpy._gradeSign), _gradeExecute(cpy._gradeExecute) {
	//*this = cpy;
}

AForm &AForm::operator=(const AForm &cpy) {
	this->_isSigned = cpy._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << this->_name << YELLOW << " has been shredded and burned!" << RESET << std::endl;
}

const std::string AForm::getName() const { return this->_name; }

bool AForm::getIsSigned() const { return this->_isSigned; }
int AForm::getGradeSign() const { return this->_gradeSign; }
int AForm::getGradeExecute() const { return this->_gradeExecute; }

void AForm::beSigned(Bureaucrat const &name) {
	if (this->_isSigned == true)
		std::cout << YELLOW << "You are too slow..., this form has already been signed." << RESET << std::endl;
	else if (this->_gradeSign < name.getGrade()) {
		std::cout << RED << name.getName() << " couldn’t sign " << this->getName() << " because : " << RESET;
		throw GradeTooLowException();
	}
	else {
		this->_isSigned = true;
		std::cout << "The Bureaucrat " << name.getName() << " signed the " << this->_name << " Form." <<std::endl; 
	}
}

void AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeExecute()) {
		throw AForm::GradeTooLowException();
	}
	if (!this->getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	executor.executeForm(*this);
}

const char *AForm::FormNotSignedException::what() const throw() {
		 return "\033[1;33mThis form could not be executed as it has not been signed.\033[0m \n";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "\033[1;33mThere is no higher level in ranking than level 1.\n \033[31mPlease enter a valid rank between 1 and 150!\033[0m \n";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "\033[1;33mGrade to low.\n \033[31mPlease call your supervisor to find a Bureaucrat with the appropiate ranking! \033[0m \n";
}

std::ostream &operator<<(std::ostream &o, AForm &cpy) {
	o << cpy.getName() << std::endl;
	o << " AForm," << " is signed " << cpy.getIsSigned() << std::endl;
	o << "Required signature grade: " << cpy.getGradeSign() << std::endl;
	o << "Required execution grade: " << cpy.getGradeExecute() << std::endl;
    return o;
}
