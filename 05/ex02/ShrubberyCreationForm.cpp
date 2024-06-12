#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():target("def"), grade(145), ex_grade(137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):target(target), grade(145), ex_grade(137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):target(other.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other)
{
    target = other.target;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ifstream myfile(target + "_shrubbery");

    if (get_issigned() && executor.getGrade() <= ex_grade)
    {
        if (!myfile.is_open())
            throw "Can't open the file";
       
            myfile << "              ,@@@@@@@,"
            myfile <<"        ,,,.   ,@@@@@@/@@,  .oo8888o."
            myfile <<"     ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o"
            myfile << "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'"
            myfile << "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'"
            myfile << "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'"
            myfile <<"    `&%\ ` /%&'    |.|        \ '|8'"
            myfile <<"        |o|        | |         | |"
            myfile <<"        |.|        | |         | |"
            myfile <<"     \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_"

    }
    myfile.close();
    
}