/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/11/06 10:36:37 by yitoh         ########   odam.nl         */
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

        std::cout << Lara << Bob << John << std::endl;

        std::cout << "===INCREMENT===" << std::endl;
        Lara.incrementGrade();
        std::cout << Lara;
        std::cout << "===DECREMENT===" << std::endl;
        Bob.decrementGrade();
        std::cout << Bob <<std::endl;
        std::cout << "=============================" << std::endl;
        Form form("A", 120, 100);
        std::cout << form << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << Bob;
        Bob.signForm(form);
        std::cout << std::endl;
        std::cout << Lara;
        Lara.signForm(form);
        std::cout << std::endl;
        std::cout << John;
        John.signForm(form);
        std::cout << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}