/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 16:42:39 by yitoh         #+#    #+#                 */
/*   Updated: 2024/08/12 16:58:18 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <cstring>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _sign;
    const int _signGrade;
    const int _execGrade;
    
public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    ~AForm();
    AForm(AForm& a);
    AForm& operator=(const AForm& a);
    
    const std::string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    virtual void beSigned(Bureaucrat b) = 0;
    
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

std::ostream& operator<<(std::ostream& out, const AForm& a);

#endif