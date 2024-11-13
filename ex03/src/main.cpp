/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/13 12:29:26 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PlanetaryRelocationForm.hpp"
#include "Intern.hpp"
#include <cstdlib> 
#include <ctime>

int main(void)
{
	std::string user;
	std::cout << BLUE << "Somwhere in the headoffices of Vogsphere, the President of the Galaxy, Zaphood Beeblebrox is welcoming the new head of the intergalactical Construction department. "<< std::endl << RESET << "Zaphood Beeblebrox: " << GREEN << "My apologies, but, what was your name again? " << std::endl << RESET; 
	if (!std::getline(std::cin, user)) {
		std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Dont screw with me...! You want the job or not?" << std::endl;
		return 0;
	}
	Bureaucrat *headBureaucrat = new Bureaucrat(user, 1);

	sleep(1);
	std::srand(std::time(0)); 
	Intern intern;            
	int missionType = std::rand() % 2;
	std::cout << RED_BACKGROUND << "The fate of Earth is in the hands of " << headBureaucrat->getName() << " and some random intern..." << RESET << std::endl << std::endl;
	sleep(2);
	std::cout << YELLOW << "But before anything,.. office routine requires the creation of some forms to start off the day .." << RESET << std::endl;
	sleep(2);
	AForm* forms[4];
	forms[0] = intern.makeForm("presidential pardon request", "Zaphod Beeblebrox");
	sleep(2);
	forms[1] = intern.makeForm("robotomy request", "Marvin the Paranoid Android");
	sleep(2);
	forms[2] = intern.makeForm("shrubbery request", "VogonPoetryDepartment");
	sleep(2);

	try {
		forms[3] = intern.makeForm("impossible form", "Uncharted Territory");
	} catch (const std::exception& e) {
		std::cerr << "Intern error: " << e.what() << std::endl;
		forms[3] = NULL;
	}

	try {
		if (missionType == 0) {
			std::cout << headBureaucrat->getName() << ": " << RED_BACKGROUND << "What is this,.. in this pile of Paperwork I just found a relocation requirement for Earth! .. quick, intern, make the relocation request ASAP!" << RESET << std::endl;
			sleep(2);
			AForm* relocationForm = intern.makeForm("relocation request", "Earth");

			if (relocationForm) {
				std::cout << "Relocation form created. Submitting to " << headBureaucrat->getName() << " for final signature..." << std::endl;
				sleep(1);
				headBureaucrat->signForm(*relocationForm);
				sleep(1);
				headBureaucrat->executeForm(*relocationForm);
				delete relocationForm;
			}
		} else {
			std::cout << RED_BACKGROUND << "since the Earth relocation Form got lost in the pile of paperwork, Earth's doom is set; destruction is imminent, and our Bureaucrats are continuing utterly ignorant of the importance of the lost document..." << RESET << std::endl << std::endl;
		}

		std::cout << std::endl <<  YELLOW << "The usual forms processing continues..." << RESET << std::endl;
		for (int i = 0; i < 3; ++i) {
			if (forms[i]) {
				try {
					std::cout << std::endl <<"Processing " << forms[i]->getName() << " form:" << std::endl;
					sleep(2);
					headBureaucrat->signForm(*forms[i]);
					sleep(2);
					headBureaucrat->executeForm(*forms[i]);
				} catch (const std::exception& e) {
					std::cout << "Form handling error: " << e.what() << std::endl;
				}
				delete forms[i];
			}
		}
		if (forms[3]) delete forms[3]; 
	} catch (const std::exception& e) {
		std::cerr << "Mission error: " << e.what() << std::endl;
	}
		#ifdef __APPLE__
        system("open ../ex03/VogonPoetryDepartment_shrubbery");
    #elif __linux__
        system("xdg-open ../ex03/VogonPoetryDepartment_shrubbery");
    #elif _WIN32
        system("start ..\ex03\\VogonPoetryDepartment_shrubbery");
    #endif
	
	if (missionType == 0) {
		std::cout << std::endl << "The intern reflects, wondering if future assignments might be less... apocalyptic." << std::endl;
	} else {
		std::cout << headBureaucrat->getName() << ": " << YELLOW << " Well done everybody..., it is already 15:30, time to pack up and leave before some other form comes in.. " << RESET << std::endl; 
	}

	delete headBureaucrat;
	return 0;
}
