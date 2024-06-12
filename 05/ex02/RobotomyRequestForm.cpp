#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():target("def"), grade(72), ex_grade(45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):target(target)
{
    grade = 72;
    ex_grade = 45;
}



RobotomyRequestForm::~RobotomyRequestForm()
{
}
