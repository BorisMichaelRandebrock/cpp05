/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlanetaryRelocationForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:48:02 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/13 12:26:39 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlanetaryRelocationForm.hpp"

PlanetaryRelocationForm::PlanetaryRelocationForm() : AForm("PlanetaryRelocationForm", 10, 1), _target("Earth") {
    std::cout << " PlanetaryRelocationForm created by default constructor for planet " << _target << std::endl;
}

PlanetaryRelocationForm::PlanetaryRelocationForm(const std::string target) : AForm("PlanetaryRelocationForm", 10, 1), _target(target) {
    std::cout << " PlanetaryRelocationForm created for " << target << std::endl;
}

PlanetaryRelocationForm::~PlanetaryRelocationForm() {
}

PlanetaryRelocationForm::PlanetaryRelocationForm(const PlanetaryRelocationForm &cpy) {
    *this = cpy;
}

PlanetaryRelocationForm &PlanetaryRelocationForm::operator=(const PlanetaryRelocationForm &cpy) {
    this->_target = cpy._target;
    return *this;
}

const std::string PlanetaryRelocationForm::getTargetName() const {
    return this->_target;
}

void PlanetaryRelocationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeExecute()) {
        throw Bureaucrat::GradeTooLowException();
    } else if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }

    std::cout << GREEN << "Executing PlanetaryRelocationForm for " << this->_target << RESET << std::endl;
    sleep(1);
    
    std::cout << GREEN << "Planetary Relocation Request for " << _target << " is being processed..." << RESET << std::endl;
    sleep(1);
    
    std::srand(std::time(NULL));
    
    if (std::rand() % 2 == 0) {
        std::cout << GREEN << "Intergalactic Transport Beam activated!" << RESET << std::endl;
        sleep(1);
        std::cout << GREEN << "A bright green beam envelops " << _target << ", shifting it slightly left to make room for an intergalactic freeway!" << RESET << std::endl;
        sleep(1);
        std::cout << GREEN << _target << " has successfully been relocated!" << RESET << std::endl;
    } else {
        std::cout << RED << "ERROR: Beam misalignment! Planet " << _target << " relocation has failed." << RESET << std::endl;
        sleep(1);
        std::cout << RED << "Intergalactic Transport Services reports: 'Error 42 - Please resubmit request after recalibration.'" << RESET << std::endl;
        sleep(1);
        std::cout << RED_BACKGROUND << "Due too a lack of time, resubmit after recalibration is useless and Earth's destruction can not be prevented!" << RESET << std::endl;
    }
}

