/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/08/06 17:56:22 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat Lara("Lara", 150);
        Bureaucrat Bob("Bob", 118);
        Bureaucrat John("John", 4);

        std::cout << Lara;
        std::cout << Bob << std::endl;

        std::cout << "=============================" << std::endl;
        std::cout << "===INCREMENT===" << std::endl;
        Lara.incrementGrade();
        std::cout << Lara;
        std::cout << "===DECREMENT===" << std::endl;
        Bob.decrementGrade();
        std::cout << Bob <<std::endl;
        std::cout << "=============================" << std::endl;
        Form form("A", 120, 100);
        std::cout << form;
        // form.beSigned(Lara);
        std::cout << Bob;
        Bob.signForm(form);
        std::cout << Lara;
        Lara.signForm(form);
        // form.beSigned(Bob);
        // form.beSigned(John);
        std::cout << John;
        John.signForm(form);
        
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}