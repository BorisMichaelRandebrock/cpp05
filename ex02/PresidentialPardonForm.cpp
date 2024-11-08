/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:53 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/08 17:18:52 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Random lucky prisoner") {
	std::cout << " Pardonform created by default Pardonconstructor B.O.: Zaphood Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << " Pardonform created for: " << target << " created B.O.: Zaphood Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << this->getName() << " PresidentialPardonForm has been shredded & burned" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) {
	*this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy) {
	this->_target = cpy._target;
	return *this;
}

const std::string PresidentialPardonForm::getTargetName() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeExecute()){
		throw Bureaucrat::GradeTooLowException();
	} 
	else if (!this->getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	std::cout << this->_target << " has been pardoned by Zaphood Beeblebrox." << std::endl;
}

