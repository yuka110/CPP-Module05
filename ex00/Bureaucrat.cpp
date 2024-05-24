/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:02:51 by yitoh         #+#    #+#                 */
/*   Updated: 2024/05/24 12:11:28 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "Constructor is called" << std::endl;
    check_assignGrade(grade);
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(Bureaucrat &a) : _name(a.getName()), _grade(a.getGrade())
{
}

void Bureaucrat::check_assignGrade(int grade)
{
    try{
        if (grade < 1){
            throw std::runtime_error("Grade is too high");
        }
        else if (grade > 150){
            throw std::runtime_error("Grade is too low");
        }
        else
            _grade = grade;   
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
        _grade = 150;
    }
}

void Bureaucrat::incrementGrade()
{
    check_assignGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
    check_assignGrade(_grade + 1);
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return(_grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a)
{
    out << a.getName() << ", bureaucrat grade " << a.getGrade() << std:: endl;
    return (out);
}
