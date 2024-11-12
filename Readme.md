# C++ - Module 05: Repetition and Exceptions

### A Dive into Bureaucracy, Forms, and Planetary Relocation
<!-- ![prostetnic](https://github.com/user-attachments/assets/acda80b3-2b18-41e7-a510-c7d2c7ca472b)-->
Welcome to the world of **C++ Module 05**! This project explores the dizzying landscape of forms, bureaucrats, and interns, all thriving in a world where exceptions are inevitable, much like the paperwork in a bureaucratic universe. As part of this project, I implemented the essential exercises from Module 05, adding in my own creation— the **PlanetaryRelocationForm**—which provides a touch of interstellar drama and dark humor inspired by *The Hitchhiker's Guide to the Galaxy*.


---

### Project Breakdown

#### Exercise 00: "Mommy, when I grow up, I want to be a bureaucrat!"
<img src="https://github.com/user-attachments/assets/acda80b3-2b18-41e7-a510-c7d2c7ca472b" alt="Vogon Prostetnic Jeltz" align="left">

The journey begins with the **Bureaucrat** class, encapsulating the essence of rigid hierarchy. Bureaucrats have names that don't change and grades that strictly dictate their rank. They wield the power to raise or lower their grade—but only within the acceptable bounds, lest they provoke a *GradeTooHighException* or *GradeTooLowException*. In this artificial nightmare of offices and hierarchy, it’s crucial to have strict error handling, ensuring that any attempt to step out of bounds is met with a predictable response. 

#### Exercise 01: "Form up, maggots!"
Enter the **Form** class, crafted to keep bureaucrats in perpetual motion. Each form demands a minimum grade to sign and execute, effectively delegating control to only those bureaucrats capable of fulfilling their paper-pushing destiny. Forms can be signed by bureaucrats whose grades are sufficiently high, and a failed attempt raises a clear, specific exception. From managing signatures to providing the bureaucrats a reason to exist, this exercise refines exception handling and solidifies our bureaucratic world.

#### Exercise 02: "No, you need form 28B, not 28C..."
Now equipped with specific **AForm** subclasses, we shift to tasks that actually *do* something:
- **ShrubberyCreationForm**: Plants ASCII trees in a file, bringing a digital forest to life.
- **RobotomyRequestForm**: Attempts a 50% successful robotic transformation of a target, bringing random chaos into the equation.
- **PresidentialPardonForm**: Exudes a touch of irony, as it bestows forgiveness upon its target in the name of Zaphod Beeblebrox.
Each form has unique requirements for signing and executing, and everything is bound by the relentless checks and balances of bureaucratic control. 

#### Exercise 03: "At least this beats coffee-making"
The **Intern** is introduced—an unnamed, characterless drone whose primary function is to bring forms into existence. The `makeForm()` function was a rewarding challenge, as it required creating forms without `if/else` mazes, proving once again that even interns are essential in bureaucratic machines. Though nameless, these interns are efficient creators of both chaos and order, handing forms to the bureaucrats with efficient anonymity.

#### PlanetaryRelocationForm: "The Earth’s Destruction is Imminent"
As a whimsical addition, the **PlanetaryRelocationForm** embodies both humor and urgency. With Earth’s impending destruction, only the right bureaucrats can approve an intern-led, last-ditch planetary relocation. This form brings new stakes and a cosmic scale to our bureaucratic landscape. Featuring rigorous grade checks and a requirement for proper authorization, it solidifies the project’s emphasis on controlled processes. Using this form as a tool, bureaucrats in this dystopian administration can authorize the relocation of Earth’s most desperate citizens (or interns) to a new celestial body before disaster strikes. 

---

### Key Highlights
- **Exception Handling**: From grades to form execution, exceptions make sure that operations only succeed under strict conditions.
- **Hierarchical Control**: Whether managing bureaucrats or forms, everything follows rigid rules, reinforcing the importance of order and structure.
- **Dark Humor**: With forms like PlanetaryRelocationForm, the project takes a humorous look at the mundanity of paperwork, even in cosmic events.

This project combines structured classes, inheritance, and custom exceptions, offering a unique blend of storytelling and object-oriented principles within the realm of C++98. In a world obsessed with formality and control, this module sheds light on the tedious, the necessary, and the downright ridiculous, one form at a time.
