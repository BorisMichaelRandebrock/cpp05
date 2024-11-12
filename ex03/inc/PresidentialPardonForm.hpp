/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:54:24 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/07 15:17:54 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();
		
		const std::string getTargetName() const;
		void execute(Bureaucrat const & exector) const;
};
