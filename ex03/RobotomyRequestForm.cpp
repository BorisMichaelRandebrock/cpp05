/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:53 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/11 11:19:41 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Random lucky prisoner") {
	std::cout << " RobotomyRequestForm created by default RobotomyRequestForm defaultconstructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout <<  target << "_robotomy form created!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
//	std::cout << this->getName() << " RobotomyRequestForm has been shredded & burned" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) {
	*this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy) {
	this->_target = cpy._target;
	return *this;
}

const std::string RobotomyRequestForm::getTargetName() const {
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeExecute()){
		throw Bureaucrat::GradeTooLowException();
	} 
	else if (!this->getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	
	std::srand(std::time(NULL));
	
	if (std::rand() % 2 == 0)
	{
		std::cout << GREEN << "Executing RobotomyRequestForm for " << this->_target << RESET << std::endl;
		sleep(1);
		std::cout << GREEN << "BRRRRRRRRRRRRRRRRRRRRRR" << RESET << " – the drill roars to life, echoing through the air, audible from afar." << std::endl;
		sleep(1);
		std::cout << GREEN <<"RRRRR-RRR-RRR-RRRR-KRRRRRR-KRRRRRRRRRRRRRRR" << RESET << " – it clatters and screeches as it bites into the surface, making everything vibrate." << std::endl;
		sleep(1);
		std::cout << GREEN <<"KRRRRRRRRRRRRR-CHRRRRRRRRRRRRRRRRRR" << RESET << " – the grinding gets louder and louder, with a high-pitched whine as it digs deeper." << std::endl;
		sleep(1);
		std::cout << GREEN << "RRRRRRRRRRRRRRRR-KRRRRRRRR" << RESET << " – the drill slows, then revs up again, making the walls shake." << std::endl;
		sleep(1);
		std::cout << this->_target << GREEN << " has been robotomized!" << RESET << std::endl;
	}
	else  
	{
		std::cout << YELLOW << "SPRRZZZZZZZTTTT!!!" << RESET << " Sparks fly wildly as the machine malfunctions!" << std::endl;
		sleep(1);
std::cout << YELLOW << "KZZZT-KRZZZZZ-KZZZZT!!" << RESET << " – strange popping and sizzling sounds as circuits fry." << std::endl;
		sleep(1);
std::cout << YELLOW << "SZZZZZTTT! POP! POP!" << RESET << " – small bursts of smoke erupt, filling the air with a sharp, burnt smell." << std::endl;
		sleep(1);
std::cout << YELLOW << "FRRRZZZZT-KZZZT-SPRRRZZZZ!!" RESET << " – the machine sputters, whines, and finally powers down in a last sad fizzle." << std::endl;
		sleep(1);
		std::cout << RED << "The robotomy of " <<  this->_target << " has failed!" << RESET << std::endl;
	}
	std::cout << GREEN << this->_target << "_roobotomy request form has been executed by Bureaucrat: " << executor.getName() << "!" << RESET << std::endl;
}

