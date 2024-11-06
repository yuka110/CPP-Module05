/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/11/06 11:02:36 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try {
        Bureaucrat Lara("Lara", 150);
        Bureaucrat Bob("Bob", 118);
        Bureaucrat John("John", 4);

        std::cout << Lara;
        std::cout << Bob;
        std::cout << John << std::endl;
        
        PresidentialPardonForm Pform("Presidential");
        RobotomyRequestForm Rform("Robotomy");
        ShrubberyCreationForm Sform("Shrubbery");
        ShrubberyCreationForm Sform2("plants");
        std::cout << std::endl;
        std::cout << Pform;
        std::cout << Rform;
        std::cout << Sform;
        
        std::cout << std::endl;
        std::cout << Lara;
        Lara.signForm(Pform);
        Pform.execute(Lara);
        Lara.signForm(Rform);
        Rform.execute(Lara);
        Lara.signForm(Sform);
        Sform.execute(Lara);

        std::cout << "--------------------------------------------" << std::endl;
        std::cout << Bob;
        Bob.signForm(Pform);
        Pform.execute(Bob);
        Bob.signForm(Rform);
        Rform.execute(Bob);
        Bob.signForm(Sform);
        Sform.execute(Bob);

        std::cout << "--------------------------------------------" << std::endl;
        std::cout << John;
        John.signForm(Pform);
        Pform.execute(John);
        John.signForm(Rform);
        Rform.execute(John);
        John.signForm(Sform);
        Sform2.execute(John); // Error: Sform2 is not signed yet
        John.signForm(Sform2);
        Sform2.execute(John);   
        std::cout << std::endl;            
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}