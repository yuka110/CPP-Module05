#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"


#define BOLD_TEXT "\033[1m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat &a);
    Bureaucrat& operator=(const Bureaucrat& a);

    void check_assignGrade(int grade);
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;
    int getGrade() const;
    
    void signForm(AForm& form);
    void executeForm(AForm const& form);

    class GradeTooHighException : public std::exception{
        private:
            std::string _b_name;

        public:
            GradeTooHighException(std::string name) : _b_name(name) {};
            virtual const char* what() const throw(){
                std::cout << _b_name << "'s ";
                return ("grade is too high. The grade needs to be between 1-150");
            };
    };
    
    class GradeTooLowException : public std::exception{
        private:
            std::string _b_name;

        public:
            GradeTooLowException(std::string name) : _b_name(name) {};
            virtual const char* what() const throw(){
                std::cout << _b_name << "'s ";
                return ("grade is too low. The grade needs to be between 1-150");
            };
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& a);



#endif