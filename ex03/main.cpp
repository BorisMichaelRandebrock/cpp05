/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/11 14:44:13 by brandebr         ###   ########.fr       */
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

/*int main() {
  std::srand(std::time(0)); // Seed random generator
  Intern intern;            // Nameless intern
  Bureaucrat headBureaucrat("Ford Prefect", 1); // Chief Bureaucrat in charge

// Random start scenario
int missionType = std::rand() % 2; // Random 0 or 1

try {
if (missionType == 0) {
std::cout << "The intern receives a special task from Ford Prefect. "
<< "A last-ditch plan has emerged to relocate Earth—"
<< "a form awaits processing.\n";

AForm* relocationForm = intern.makeForm("relocation request", "Earth");
if (relocationForm) {
std::cout << "Intern cautiously submits the "
<< relocationForm->getName()
<< " to Ford for the final signature.\n";
headBureaucrat.signForm(*relocationForm);
headBureaucrat.executeForm(*relocationForm);
}
delete relocationForm;
} else {
std::cout << "The intern, after dodging some debris in the office, "
<< "is assigned to handle routine forms for Ford Prefect.\n";

AForm* forms[3];
forms[0] = intern.makeForm("presidential pardon request", "Zaphod Beeblebrox");
forms[1] = intern.makeForm("robotomy request", "Marvin the Paranoid Android");
forms[2] = intern.makeForm("shrubbery request", "Vogon Poetry Department");

for (int i = 0; i < 3; ++i) {
if (forms[i]) {
try {
std::cout << "\nProcessing " << forms[i]->getName() << " form:\n";
headBureaucrat.signForm(*forms[i]);
headBureaucrat.executeForm(*forms[i]);
} catch (const std::exception& e) {
std::cerr << "Form handling error: " << e.what() << "\n";
}
delete forms[i];
}
}
}
} catch (const std::exception& e) {
std::cerr << "Mission assignment error: " << e.what() << "\n";
}

std::cout << "\nAs the dust settles in the office, the intern hopes their next assignment is less... cosmic.\n";
return 0;
}*/
int main(void)
{
	std::string user;
	std::cout << BLUE << "Somwhere in the headoffices of Vogsphere, the President of the Galaxy, Zaphood Beeblebrox is welcoming a new head of the intergaalactical Construction department. "<< std::endl << RESET << "Zaphood Beeblebrox: " << GREEN << "My apologies, but, wwhat was your name again?. " << std::endl << RESET; 
	if (!std::getline(std::cin, user)) {
		std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Dont screw with me...! You want to loose your job?" << std::endl;
		return 0;
	}
	Bureaucrat *headBureaucrat = new Bureaucrat(user, 1);

	sleep(1);
	std::srand(std::time(0)); 
	Intern intern;            
	int missionType = std::rand() % 2;
	std::cout << "The fate of Earth is in the hands of " << headBureaucrat->getName() << " and a random intern..." << std::endl;

	sleep(2);
	AForm* forms[4];
	forms[0] = intern.makeForm("presidential pardon request", "Zaphod Beeblebrox");
	sleep(1);
	forms[1] = intern.makeForm("robotomy request", "Marvin the Paranoid Android");
	sleep(1);
	forms[2] = intern.makeForm("shrubbery request", "Vogon Poetry Department");
	sleep(1);

	try {
		forms[3] = intern.makeForm("impossible form", "Uncharted Territory");
	} catch (const std::exception& e) {
		std::cout << "Intern error: " << e.what() << std::endl;
		forms[3] = NULL;
	}

	try {
		if (missionType == 0) {
			std::cout << headBureaucrat->getName() << YELLOW << ": Earth has a chance to be relocated! .. quick, intern, make the relocation request ASAP!" << RESET << std::endl;
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
			std::cout << "Earth's doom is set; destruction is imminent. Forms are now critical!" << std::endl;
		}

		std::cout << std::endl <<"Additional forms processing begins..." << std::endl;
		for (int i = 0; i < 3; ++i) {
			if (forms[i]) {
				try {
					std::cout << std::endl <<"Processing " << forms[i]->getName() << " form:" << std::endl;
					sleep(1);
					headBureaucrat->signForm(*forms[i]);
					sleep(1);
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
	delete headBureaucrat;
	//	delete intern;


	std::cout << std::endl << "The intern reflects, wondering if future assignments might be less... apocalyptic." << std::endl;
	return 0;
	/*
	   std::cout << "Zaphood: " << GREEN << "Uhhh, I am impatient to try my new  executive powers... lets see... I could give a Presidential Pardon to some random mischief." << RESET << std::endl; 
	   sleep(2);
	   PresidentialPardonForm *lucky = new PresidentialPardonForm();

	   std::cout << "Zaphood: " << GREEN << s->getName() << " Could you go ahead and sign the form?" << RESET << std::endl; 
	   sleep(2);

	   try {
	   lucky->beSigned(*s);
	   }
	   catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
	   }

	   std::cout << "Zaphood: " << GREEN << "Well, I should have figured that the Pardon needed some higher grade. " << m->getName() << " Could you go ahead and sign the form?" << RESET << std::endl; 
	   sleep(2);

	   try {
	   lucky->beSigned(*m);
	   }
	   catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
	   }
	   sleep(2);

	   std::cout << "Zaphood: " << YELLOW << "hmm... I am starting to be nervous.. lets see " << u->getName() << " if you, as the head of the department, can sign the deed, otherwise I might have to call for a Cabinet Emergency Meeting." << RESET << std::endl; 
	   try {
	   lucky->beSigned(*u);
	   }
	   catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
	   }
	   sleep(2);
	   std::cout << "Zaphood: " << GREEN << " Uff,.. I already got scared.." << std::endl << m->getName() << " could you try to execute the pardon?" << RESET << std::endl; 
	   try {
	   lucky->execute(*s);
	   }
	   catch (std::exception &e) {
	   std::cout << m->getName() << RED << " can not execute this Pardon as her grade is too low!" << RESET << std::endl;
	   std::cout << e.what() << std::endl;
	   }
	   sleep(2);

	   std::cout << "Zaphood: " << GREEN << " I thought that much. " << u->getName() <<" could you give it a go?" << RESET << std::endl; 
	   try {
	   u->executeForm(*lucky);
	   }
	   catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
	   }
	   sleep(2);

	   std::cout << "Zaphood: " << GREEN << "Ok Folks., we have our first order in.. please " << u->getName() << " sign and execute the request!" << RESET << std::endl; 

	   RobotomyRequestForm *house = new RobotomyRequestForm("arthurs");
	   try {
	   u->signForm(*house);
	   }
	   catch (std::exception &e) {
	   std::cout <<e.what() << std::endl;
	   }
	   try {
	   u->executeForm(*house);
	   }
	   catch (std::exception &e) {
	   std::cout << e.what() << std::endl;
	   }
	   sleep(2);
	   std::cout << "Zaphood: " << YELLOW  << "STOP, STOP... I JUST REALIZED, THIS IS THE HOUSE OF ARTHUR DENT, BELOVED FRIEND OF FORD!!! " << RESET << std::endl; 
	   std::cout << YELLOW  << "I will write a PresidentialPardon and create some green area around his property inmediately! Please do everything you can to get this done ASAP " << RESET << std::endl; 
	PresidentialPardonForm *arthur = new PresidentialPardonForm("Arthur Dent");
	sleep(2); 
	try {
		u->signForm(*arthur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		u->executeForm(*arthur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	ShrubberyCreationForm *forrest = new ShrubberyCreationForm("forrest");
	sleep(2);
	try {
		m->signForm(*forrest);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << u->getName() << " has signed the execution of the ShrubberyCreationForm!" << std::endl;
		//u->executeForm(*arthur);
		forrest->execute(*u);
	}
	catch (std::exception &e) {
		std::cout << "ShrubberyCreationForm could not be executed!" << std::endl;
		std::cout << e.what() << std::endl;
	}

	delete forrest;
	delete arthur;
	delete house;
	delete lucky;
	delete u;
	delete s;
	delete m;

	return 0;*/
}
