#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <cstring>
#include <iostream>
#include <fstream>
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

// std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& a);

#define ASCII_TREE "\n\
                                  /#### ####\"\n\
                                ### \"/#|### |/####\n\
                               ##\"/#/ \"||/##/_/##/_#\n\
                             ###  \"/###|/ \"/ # ###\n\
                           ##_\"_#\"_\"## | #/###_/_####\n\
                          ## #### # \" #| /  #### ##/##\n\
                           __#_--###`  |{,###---###-~\n\
                                     \" }{\n\
                                      }}{\n\
                                      }}{\n\
                                 ejm  {{}\n\
                                , -=-~{ .-^- _\n\
                                      `}\n\
                                       {\n"

#endif