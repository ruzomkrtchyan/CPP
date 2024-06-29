#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), target("def")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other), target(other.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	target = other.target;
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream myfile((target + "_shrubbery").c_str());

	if (!get_issigned() || executor.getGrade() > getexgrade())
		throw GradeTooLowException();
	if (!myfile.is_open())
		throw "Can't open the file";   
	myfile << "                 ,@@@@@@," << std::endl;
	myfile <<"        ,,,.   ,@@@@@@@@@,  .oo8888o." << std::endl;
	myfile <<"     ,&%&&%&&%,@@@@@@@@@@@@,8888o8888o" << std::endl;
	myfile << "   ,%&%&&&%&&%,@@@@@@@@@@@88o88888o888'" << std::endl;
	myfile << "   %&&%&%&/%&&%@@@@@ / /@@@88888888888'" << std::endl;
	myfile << "   %&%&% /%&&%&@@@  V /@@' `8888 /88'" << std::endl;
	myfile <<"    `&%& v &%&'    | |         |v|" << std::endl;
	myfile <<"        | |        | |         | |" << std::endl;
	myfile <<"        | |        | |         | |" << std::endl;
	myfile <<"        | |//_/__/ | |//__/.//_| |" << std::endl;
	myfile.close();
	
}