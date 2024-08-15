#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM__HPP

#include <cstring>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidntialPardonForm : public AForm
{
private:
    
public:
    PresidntialPardonForm();
    PresidntialPardonForm(std::string name, int signGrade, int execGrade);
    ~PresidntialPardonForm();
    PresidntialPardonForm(PresidntialPardonForm& a);
    PresidntialPardonForm& operator=(const PresidntialPardonForm& a);
    
    void beSigned(Bureaucrat b);

};

std::ostream& operator<<(std::ostream& out, const PresidntialPardonForm& a);

#endif