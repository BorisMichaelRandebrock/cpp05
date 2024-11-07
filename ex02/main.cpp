/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/07 18:44:26 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main(void)
{
	
		std::string user;
		Bureaucrat *s = new Bureaucrat();
		Bureaucrat *m = new Bureaucrat("Princess Peach", 50);
		std::cout << "Zaphod Beeblebrox: " << GREEN << "Hello again my friend,... my memory is short and I have a lot of things on my mind.., " << std::endl <<
			"my apologies.., could you remind me your name again? " << RESET; 
		if (!std::getline(std::cin, user)) {
			std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Dont screw with me...! You want to loose your job?" << std::endl;
			return 0;
		}
		Bureaucrat *u = new Bureaucrat(user, 1);
		
		(void)s;
		(void)m;
		(void)u;
		std::cout << "Zaphood: " << GREEN << "For starters. lets create a simple, basic form." << RESET << std::endl; 
		sleep(2);
		PresidentialPardonForm *lucky = new PresidentialPardonForm();
		
		(void)lucky;
		std::cout << "Zaphood: " << GREEN << s->getName() << " Could you go ahead and sign the form?" << RESET << std::endl; 
		sleep(2);
		
		try {
			lucky->beSigned(*s);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(2);

		try {
		//	s->executeForm(*lucky);
			lucky->execute(*s);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
		try {
			lucky->beSigned(*m);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(2);

		try {
			lucky->beSigned(*u);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(2);
		
		try {
			std::cout << "What?" << std::endl;
		//	s->executeForm(*lucky);
			lucky->execute(*s);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(2);
		try {
		//	u->executeForm(*lucky);
			lucky->execute(*u);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		sleep(2);
		/*
		std::cout << "Zaphood: " << GREEN << "Let's see whether I can introduce you to your first task, lets create a AForm together..." << RESET << std::endl; 
		sleep(2);
		sleep(2);
		std::cout << "Zaphood: " << GREEN << u->getName() << ", I have here a request for the destrucion of that shabby little house in Country Lane, with that, I will show you how we handle this kinda things." << RESET << std::endl;
		AForm *destroyArthurDentsHome = new AForm("Destroy 155 Country Lane, Cottington, Cottingshire", 50, 50);
		sleep(2);

		std::cout << "Zaphood: " << YELLOW << s->getName() << ", just show the new head of Construction how we sign forms here!" << RESET << std::endl;
		sleep(2);
		try 
		{
			destroyArthurDentsHome->beSigned(*s);
		}
		catch(std::exception &e) 
		{
			std::cout << e.what() << std::endl;
		}

		sleep(2);
		std::cout << "Zaphood: " << BLUE << "Well, my bad..., my apologies " << s->getName() << ", I should have known, I will ask a higher ranking officer. " << std::endl << YELLOW << m->getName() << " could you do the job? "<< RESET << std::endl;
		sleep(2);
		try {
			m->signAForm(*destroyArthurDentsHome);
		} 
		catch(std::exception &e)
		{
			std::cout << RED << "This should work " << m->getName() <<
				" failed: " << e.what() << BLUE << std::endl;
		}
		std::cout << "Zaphood: " << GREEN << " Just for showing you what happens if a form is already signed, " << u->getName() << ", please try to sign the form which has been just signed by " << m->getName() << "." << std::endl; 
		sleep(2);
		try { 
			u->signAForm(*destroyArthurDentsHome);
		}
		catch (std::exception &e) 
		{
			std:: cout << e.what() << std::endl; 
		}
		sleep(4);
		std::cout << "Ford: " << RED_BACKGROUND << "THE VOGONS ARE HERE.. EVERYBODY LEAVE THE PLANET BEFORE IT IS TOOO LATE !!!" << RESET << std::endl;
		sleep(3);
		std::cout << "Prostetnic Vogon Jeltz: " << BOLD << RED << "This is Prostetnic Vogon Jeltz of the Galactic Hyperspace Planning Council. " << std::endl; 
		sleep(3);
		std::cout << "As you will no doubt be aware, the plans for development of the outlying regions of the Galaxy require the building of a hyperspatial express route through your star system, and regrettably your planet is one of those scheduled for demolition." << std::endl;
		sleep(4);
		std::cout << "The process will take slightly less than two of your Earth minutes. Thank you." << RESET << std::endl;
		sleep(5);
		std::cout << "🐬: So Long, and Thanks for All the Fish" << std::endl;
	
		delete basic;
		delete destroyArthurDentsHome;
		delete u;
		delete s;
		delete m;
		*/
	return 0;
}
