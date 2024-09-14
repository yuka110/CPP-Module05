#ifndef INTERN_HPP
# define INTERN_HPP

#include <cstring>
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class PresidentialPardonForm;
class RobtomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
private:

public:
    Intern();
    ~Intern();
    Intern(Intern &a);
    Intern& operator=(const Intern& a);

    AForm* makeForm(std::string form, std::string target);
    class NonExistingForm : public std::exception{
        public:
            virtual const char* what() const throw(){
                return ("The form does not exist. \n");
            };
    };
};

#endif