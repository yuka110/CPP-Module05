/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/09/14 14:16:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Bureaucrat Lara("Lara", 150);
        Bureaucrat Bob("Bob", 118);
        Bureaucrat John("John", 4);

        std::cout << Lara;
        std::cout << Bob;
        std::cout << John << std::endl;

        Intern newbie;
        AForm* Pform = newbie.makeForm("presidential pardon", "Chocolate");
        AForm* Rform = newbie.makeForm("robotomy request", "Strawberry");
        AForm* Sform = newbie.makeForm("shrubbery creation", "home");
        // AForm* Sform2 = newbie.makeForm("SSShrubbery creation", "plants");

        std::cout << std::endl;
        std::cout << *Pform;
        std::cout << *Rform;
        std::cout << *Sform;
        // std::cout << *Sform2;
        
        std::cout << std::endl;
        std::cout << Lara;
        Lara.signForm(*Pform);
        (*Pform).execute(Lara);
        Lara.signForm(*Rform);
        (*Rform).execute(Lara);
        Lara.signForm(*Sform);
        (*Sform).execute(Lara);

        std::cout << "--------------------------------------------" << std::endl;
        std::cout << Bob;
        Bob.signForm(*Pform);
        (*Pform).execute(Bob);
        Bob.signForm(*Rform);
        (*Rform).execute(Bob);
        Bob.signForm(*Sform);
        (*Sform).execute(Bob);

        std::cout << "--------------------------------------------" << std::endl;
        std::cout << John;
        John.signForm(*Pform);
        (*Pform).execute(John);
        John.signForm(*Rform);
        (*Rform).execute(John);
        John.signForm(*Sform);
        (*Sform).execute(John);             
        
        delete Pform;
        delete Rform;
        delete Sform;
        
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}