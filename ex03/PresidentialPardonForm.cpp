#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25,5)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& a) : AForm(a.getName(), 25,5)
{
    operator=(a);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& a)
{
    if (this == &a)
        return *this;
    setSign(a.getSign());
    return *this;
}

void PresidentialPardonForm::actualExec() const
{
    std::cout << MAGENTA << getName() << " has been pardoned by Zaphod Beeblebrox!" << RESET << std::endl << std::endl;
}