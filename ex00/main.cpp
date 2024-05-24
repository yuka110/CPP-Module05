/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:01:46 by yitoh         #+#    #+#                 */
/*   Updated: 2024/05/24 12:10:57 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Lara("Lara", 10);
    Bureaucrat John("John", 0);
    Bureaucrat Bob("Bob", 151);

    std::cout << Lara;
    std::cout << John;
    std::cout << Bob;
    Lara.incrementGrade();
    std::cout << Lara;
    Lara.decrementGrade();
    std::cout << Lara;

    return 0;
}