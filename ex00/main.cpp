/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/08/05 17:58:37 by yitoh         ########   odam.nl         */
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
        std::cout << "===DECREMENT===" << std::endl;
        Bob.decrementGrade();
        std::cout << Lara;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}