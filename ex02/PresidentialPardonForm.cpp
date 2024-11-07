/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:53 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/07 15:18:19 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) _target("Random lucky prisoner") {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5) _target(target) {
	std::cout << this->getTargetName() << " has been pardoned, gracefully by Zaphod Beeblebrox." std::endl;
}
