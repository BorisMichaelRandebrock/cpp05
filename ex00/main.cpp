/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:17 by brandebr          #+#    #+#             */
/*   Updated: 2024/11/13 11:56:17 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <unistd.h>

int main(void)
{
	{
		std::string user;
		std::cout << GREEN << "Welcome to the Galaxy my friend, my Name is Zaphood Beeblebrox, President of the same.." << std::endl <<
			"I understand you are looking for a job in my administration.. just tell me: What is your name? " << RESET; 
		if (!std::getline(std::cin, user)) {
			std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Don't screw with me...! You want the job, or not?" << std::endl;
			return 0;
		}
		std::cout << YELLOW << "My apologies, I have to attend another, new Bureaucrat... will come back to you shortly " << user << "!" << RESET << std::endl; 
		sleep(1);
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

		std::cout << "The new Bureaucrat " << a->getName() << " has been hired with grade: " << a->getGrade() << std::endl;
		std::cout << "Zaphood: " << YELLOW << "..hmmm grade 150 was maybe a bit shabby..." << RESET << std::endl; 
		sleep(2);
		try 
		{
			a->incrementGrade();
		}
		catch(std::exception &e) 
		{
			std::cout << "Incrementing grade of " << a->getName() <<
				" failed: " << e.what() << std::endl;
		}

		std::cout << "Bureaucrat " << a->getName() << " has now grade: " << a->getGrade() << std::endl;
		sleep(2);
		std::cout << a->getName() << ", the new Bureaucrat is very, very useless, even for Vogsphere's standards.. and gets demoted. " << std::endl;
		try {
			a->decrementGrade();
		} 
		catch(std::exception &e)
		{
			std::cout << RED << "Decrementing grade of " << a->getName() <<
				" failed: " << e.what() << BLUE << std::endl;
		}
		sleep(2);
		std::cout << "Bureaucrat " << a->getName() << " has now grade: " << a->getGrade() << std::endl;
		std::cout << "Zaphood looses his temper... and demotes " << a->getName() << " further..." << std::endl;
		try {
			a->decrementGrade();
		}
		catch(std::exception &e)
		{
			std::cout << YELLOW "Further demotion of " << a->getName() <<
				" failed: " << e.what() << RESET << std::endl;
		}
		std::cout << "Bureaucrat " << a->getName() << " has now grade: " << a->getGrade() << std::endl;
		std::cout << "Zaphood Beeblebrox: " << RED_BACKGROUND << "JUST GET OUT OF HERE " << a->getName() << ", you are useless and you are FIRED!!!" << RESET << std::endl;
		sleep(3);
		delete a;
		std::cout << std::endl << "Zaphood: " << GREEN << "I am sorry about that " << user << ", now let´s talk about your position.. " << std::endl;
		std::cout << std::endl;
		std::cout << "What about if I make you head of the galactical Construction department? " << RESET << std::endl;
		sleep(2);
		try
		{
			Bureaucrat *u = new Bureaucrat(user, -1);
			(void)u;
			sleep(1);
		}
		catch(const std::exception& e)
		{
			std::cout << "Zaphood: " << YELLOW << "my apologies.. the highest level is 1 " << std::endl;				
		}
		
		Bureaucrat *u = new Bureaucrat(user, 1);
		std::cout << u->getName() << " is now employed with grade: " << u->getGrade() << std::endl;
		sleep(2);
		std::cout << "Zaphood: " << GREEN << "..hmmmm, maybe I can promote you one more level.. " << RESET << std::endl;
		try {
			u->incrementGrade();
		}
		catch(std::exception &e) {
			std::cout << "\033[33mIncrementing grade of " << u->getName() <<
				" failed: " << e.what() << "\033[0m" << std::endl;
		}
		sleep(5);
		std::cout << GREEN << "Well, as you know, once you are working in the administration, you can always help us employing people you trust,.. " <<
			std::endl << "...is your spouse currently employed? How do you call your life-partner? " << RESET << std::endl;
		std::string couple;
		if (!std::getline(std::cin, couple)) {
			std::cout << std::endl << "Zaphood Beeblebrox: " << RED << "Don't screw with me...! You want the job, or not?" << std::endl;
			return 0;
		}
		std::cout << GREEN << "As it is usual..., the couples are always having more executive powers then yourselve.., so lets employ your life-partner one level above you.. " << RESET << std::endl;

		Bureaucrat *s = NULL;
		try { 
			s = new Bureaucrat(couple, 0);
		} catch(std::exception &e) {
			sleep(5);
			std::cout << YELLOW << "...my apologies,... you are at the top level.. there is no higher position available... " << RESET << std::endl;
		}
		std::cout << GREEN << "...as currently there is no other position available,.. let's try at a lower level.. let's say on level 151." << RESET << std::endl;
		sleep(5);
		try {
			s = new Bureaucrat(couple, 151);
		}
		catch(std::exception &e) {
			std::cout << YELLOW << "ups,.. lowest level is 150.. lets try it again at level 100.. " << RESET <<std::endl;
		}
		sleep(5);
		try {
			s = new Bureaucrat(couple, 100);
		} 
		catch(std::exception &e) {
			std::cout << "If this does not work, I rersign, .. my word! as I am called Zaphoed Beeblebrox!!" << std::endl;
		}
		sleep(2);
		std::cout << s->getName() << " is now employd with grade: " << s->getGrade() << std::endl;

		delete u;
		delete s;

	}
	return 0;
}
