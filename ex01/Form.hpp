/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 16:42:39 by yitoh         #+#    #+#                 */
/*   Updated: 2024/08/06 17:49:46 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <cstring>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _sign;
    const int _signGrade;
    int _execGrade;
    
public:
    Form();
    Form(std::string name, int signGrade, int execGrade);
    ~Form();
    Form(Form& a);
    Form& operator=(const Form& a);
    
    const std::string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    void beSigned(Bureaucrat b);
    
    class GradeTooHighException : public std::exception{
        private:
            std::string _b_name;
            int         _grade;

        public:
            GradeTooHighException(std::string name, int sdGrade) : _b_name(name), _grade(sdGrade) {};
            virtual const char* what() const throw(){
                std::cout << _b_name << "'s grade is too high. The grade needs to be below " << _grade;
                return ("\n");
            };
    };
    
    class GradeTooLowException : public std::exception{
        private:
            std::string _b_name;
            int         _grade;

        public:
            GradeTooLowException(std::string name, int sdGrade) : _b_name(name), _grade(sdGrade) {};
            virtual const char* what() const throw(){
                std::cout << _b_name << "'s grade is too low. The grade needs to be above " << _grade;
                return ("\n");
            };
    };
};

std::ostream& operator<<(std::ostream& out, const Form& a);

#endif