/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/11/06 10:27:12 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat Lara("Lara", 10);
        Bureaucrat John("John", 2);
        Bureaucrat Bob("Bob", 150);
        Bureaucrat Shelly(Lara);

        std::cout << Lara;
        std::cout << John;
        std::cout << Bob;
        std::cout << Shelly;
        std::cout << "=============================" << std::endl;
        std::cout << "===INCREMENT===" << std::endl;
        Lara.incrementGrade();
        std::cout << Lara;
        John.incrementGrade();
        std::cout << John;
        std::cout << "===DECREMENT===" << std::endl;
        Lara.decrementGrade();
        std::cout << Lara;
        Bob.decrementGrade();
        std::cout << Bob;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}