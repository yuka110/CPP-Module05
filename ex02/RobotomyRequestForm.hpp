#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM__HPP

#include <cstring>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm& a);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& a);
    virtual void actualExec() const;

};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& a);

#endif