#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72,45)
{}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& a) : AForm(a.getName(), 72,45)
{
    operator=(a);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& a)
{
    if (this == &a)
        return *this;
    setSign(a.getSign());
    return *this;
}

void RobotomyRequestForm::actualExec() const
{
    std::cout << YELLOW << "Bzzzzzzzzzzzz .. Bzzz.. Bzzzzz!!" << std::endl;
    if (rand()% 2)
        std::cout << getName() << "has been robotomized successfully" << RESET << std::endl;
    else 
        std::cout << getName() << "has failed robotomization" << RESET << std::endl;
}