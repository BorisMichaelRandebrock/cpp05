/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/12 18:13:07 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
		std::string user;
		Bureaucrat *s = new Bureaucrat();
		Bureaucrat *m = new Bureaucrat("Princess Peach", 50);
		std::cout << "Zaphood Beeblebrox: " << GREEN << "Hello again my friend,... my memory is short and I have a lot of things on my mind.., " << std::endl <<
			"my apologies.., could you remind me your name again? " << RESET; 
		if (!std::getline(std::cin, user)) {
			std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Dont screw with me...! You want to loose your job?" << std::endl;
			return 0;
		}
		Bureaucrat *u = new Bureaucrat(user, 1);
		
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

		RobotomyRequestForm *dent = new RobotomyRequestForm("arthurs");
		try {
			u->signForm(*dent);
		}
		catch (std::exception &e) {
			std::cout <<e.what() << std::endl;
		}
		try {
			u->executeForm(*dent);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(2);
		std::cout << "Zaphood: " << YELLOW  << "STOP, STOP... I JUST REALIZED, THIS IS ARTHUR DENT, BELOVED FRIEND OF FORD!!! " << RESET << std::endl; 
		std::cout << YELLOW  << "I will write a PresidentialPardon and create some green area around his property inmediately! Please do everything you can to get this done ASAP!!! " << RESET << std::endl; 
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
		#ifdef __APPLE__
        system("open ../ex02/forrest_shrubbery");
    #elif __linux__
        system("xdg-open ../ex02/forrest_shrubbery");
    #elif _WIN32
        system("start ..\ex02\\forrest_shrubbery");
    #endif
	
		delete forrest;
		delete arthur;
		delete dent;
		delete lucky;
		delete u;
		delete s;
		delete m;
	
	return 0;
}
