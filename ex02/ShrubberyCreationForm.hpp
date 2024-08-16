#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM__HPP

#include <cstring>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm& a);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& a);
    virtual void actualExec() const;

};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& a);

#endif