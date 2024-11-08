/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:53 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/08 17:25:04 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 37), _target("Random lucky prisoner") {
	std::cout << " ShrubberyCreationForm created by default ShrubberyCreationForm defaultconstructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 37), _target(target) {
	std::cout <<  target << " created!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << this->getName() << " ShrubberyCreationForm has been shredded & burned" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) {
	*this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy) {
	this->_target = cpy._target;
	return *this;
}

const std::string ShrubberyCreationForm::getTargetName() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeExecute()){
		throw Bureaucrat::GradeTooLowException();
	} 
	else if (!this->getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	
		 std::cout << GREEN << "Executing ShrubberyCreationForm for " << this->_target << RESET << std::endl;

		 std::ofstream	file;
		 std::string name = this->getTargetName() + "_shrubbery";
		 const char	*fileName = name.c_str();
		
		 file.open(fileName);

		if (!file) {
			std::cerr << "Error opening file " << fileName << std::endl;
			return;
		}
		for (int i = 0; i <= 5; i++) {
			file     
<< "     c42cee88oo\n"
<< "  C8O8O8*Q*8Po42b8o\n"
<< " dO42*QO8PdU42ugoO*9bD\n"
<< "CgggbU8OU qOp qOdoUOdcb\n"
<< "    6OuU  /p u gcoUodpP\n"
<< "     \\\\//  /douUP\n"
<< "       \\\\////\n"
<< "       |||/\\\n"
<< "       |||\\/\n"
<< "       |||||\\\n"
<< " .....//||||\\....\n"
<< std::endl;

		}
		file.close();
		std::cout << this->_target << " has been executed by Bureaucrat: " << executor.getName() << "!" << std::endl;
}

