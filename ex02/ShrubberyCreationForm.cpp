#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& a) : AForm(a.getName(), 145, 137)
{
    operator=(a);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& a)
{
    if (this == &a)
        return *this;
    setSign(a.getSign());
    return *this;
}

void ShrubberyCreationForm::actualExec() const
{
    std::ofstream file;
    std::string s = getName() + "_shrubbery";
    file.open(s);
    if (!file.is_open())
        throw std::runtime_error("file couldn't be opened");
    file << ASCII_TREE;    
}