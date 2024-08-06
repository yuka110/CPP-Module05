/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 18:03:54 by yitoh         #+#    #+#                 */
/*   Updated: 2024/08/06 16:23:08 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _sign(false), _signGrade(150), _execGrade(100){
    std::cout << "Form " << _name << " is constructed" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _sign(false), _signGrade(signGrade), _execGrade(execGrade){
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException(_name, 1);
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException(_name,150);
    std::cout << "Form " << _name << " is constructed" << std::endl;
}

Form::~Form(){
    std::cout << "Form " << _name << " is destructed" << std::endl;
}

Form::Form(Form& a) : _name(""), _signGrade(150), _execGrade(100)
{
    operator=(a);
}

Form& Form::operator=(const Form& a)
{
    if (this == &a)
        return *this;
    _sign = a.getSign();
    return *this;
}

const std::string Form::getName() const{
    return _name;
}

bool Form::getSign()const {
    return _sign;
}

int Form::getSignGrade()const{
    return _signGrade;
}

int Form::getExecGrade()const{
    return _execGrade;
}

void Form::beSigned(Bureaucrat b){
    if (b.getGrade() < _signGrade)
        _sign = true;
    else
        throw GradeTooLowException(b.getName(), _signGrade);
}

std::ostream& operator<<(std::ostream& out, const Form& a)
{
    out << "Form " << a.getName();
    if (a.getSign() == true)
        out << " is signed!!" << std::endl;
    else
        out << " is not signed yet." << std::endl;
    out << "grade required for sign is " << a.getSignGrade() << ", grade required for execution is " << a.getExecGrade() << std:: endl;
    return (out);
}