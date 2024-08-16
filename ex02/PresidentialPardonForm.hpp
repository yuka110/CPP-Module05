#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <cstring>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm& a);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& a);
    virtual void actualExec() const;

};

// std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& a);

#endif