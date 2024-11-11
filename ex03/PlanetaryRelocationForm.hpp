/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlanetaryRelocationForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:54:24 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/11 13:31:25 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>


class PlanetaryRelocationForm : public AForm {
	private:
		std::string _target;

	public:
		PlanetaryRelocationForm();
		PlanetaryRelocationForm(const PlanetaryRelocationForm &);
		PlanetaryRelocationForm &operator=(const PlanetaryRelocationForm &);
		PlanetaryRelocationForm(const std::string target);
		~PlanetaryRelocationForm();
		
		const std::string getTargetName() const;
		void execute(Bureaucrat const & exector) const;
};
