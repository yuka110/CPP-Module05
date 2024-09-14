/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 11:02:51 by yitoh         #+#    #+#                 */
/*   Updated: 2024/09/14 12:44:58 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(150)
{
    // std::cout << "Bureaucrat constructor is called" << std::endl;
    check_assignGrade(grade);
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(Bureaucrat &a) : _name(a.getName())
{
    operator=(a);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& a)
{
    if (this == &a)
        return (*this);
    _grade = a.getGrade();
    return (*this);
}

void Bureaucrat::check_assignGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException(_name);
    else if (grade > 150)
        throw GradeTooLowException(_name);
    else
        _grade = grade;
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

void    Bureaucrat::signForm(AForm& form)
{
    try {
        form.beSigned(*this);
    }
    catch (std::exception& e){
        std::cout << RED << _name << " couldn't sign " << form.getName(); 
        std::cout << " because " << e.what() << RESET;
        return ;
    }
    std::cout << BLUE << _name << " signed " << form.getName() << RESET << std::endl;
}

void    Bureaucrat::executeForm(AForm const& form)
{
    try{
        form.execute(*this);
    }
    catch (std::exception& e){
        std::cout << RED << _name << " couldn't execute " << form.getName(); 
        std::cout << " because " << e.what() << RESET;
        return ;
    }
    std::cout << BLUE << _name << " executed " << form.getName() << RESET << std::endl;
}



std::ostream& operator<<(std::ostream& out, const Bureaucrat& a)
{
    out << a.getName() << ", bureaucrat grade " << a.getGrade() << std:: endl;
    return (out);
}
