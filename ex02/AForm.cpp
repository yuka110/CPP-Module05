/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 18:03:54 by yitoh         #+#    #+#                 */
/*   Updated: 2024/09/14 12:49:13 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _sign(false), _signGrade(150), _execGrade(100){
    std::cout << "AForm " << _name << " is constructed" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _sign(false), _signGrade(signGrade), _execGrade(execGrade){
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException(_name, 1);
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException(_name,150);
    std::cout <<  _name << " is constructed" << std::endl;
}

AForm::~AForm(){
    std::cout << _name << " is destructed" << std::endl;
}

AForm::AForm(AForm& a) : _name(""), _signGrade(150), _execGrade(100)
{
    operator=(a);
}

AForm& AForm::operator=(const AForm& a)
{
    if (this == &a)
        return *this;
    _sign = a.getSign();
    return *this;
}

const std::string AForm::getName() const{
    return _name;
}

bool AForm::getSign()const {
    return _sign;
}

int AForm::getSignGrade()const{
    return _signGrade;
}

int AForm::getExecGrade()const{
    return _execGrade;
}

void AForm::setSign(bool sign){
    _sign = sign;
}

void AForm::beSigned(Bureaucrat b){
    if (b.getGrade() < _signGrade)
        _sign = true;
    else
        throw GradeTooLowException(b.getName(), _signGrade);
}

void    AForm::execute(Bureaucrat const& executor) const
{
    try {
        if (_sign == false)
            throw NotSignedError();
        if (_execGrade < executor.getGrade())
            throw GradeTooLowException(executor.getName(), _execGrade);
        actualExec();
    }
    catch (std::exception& e){
        std::cout << RED << executor.getName() << " couldn't execute " << getName(); 
        std::cout << " because " << e.what() << RESET;
        return ;
    }
}

std::ostream& operator<<(std::ostream& out, const AForm& a)
{
    out << "AForm " << a.getName();
    if (a.getSign() == true)
        out << " is signed!!" << std::endl;
    else
        out << " is not signed yet." << std::endl;
    out << "grade required for sign is " << a.getSignGrade() << ", grade required for execution is " << a.getExecGrade() << std:: endl << std:: endl;
    return (out);
}