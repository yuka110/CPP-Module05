#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern &a){
    operator=(a);
}

Intern& Intern::operator=(const Intern& a){
    if (this != &a)
        *this = a;
    return (*this);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    AForm* ptr = nullptr;
    try{
        std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
        int i = 0;
        for (i = 0; i < 3; i++){
            if (form == forms[i])
                break ;
        }
        switch(i){
            case 0:
                ptr = new PresidentialPardonForm(target);
                break ;
            case 1:
                ptr = new RobotomyRequestForm(target);
                break ;
            case 2:
                ptr = new ShrubberyCreationForm(target);
                break ;
            case 3:
                throw NonExistingForm();
                break ;
        }
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
        return (ptr);
    }
    std::cout << "Intern creates " << form << std::endl;
    return (ptr);
}