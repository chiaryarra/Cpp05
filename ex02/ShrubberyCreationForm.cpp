#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open() == false) {
        std::cout << "Error: the file could not be opened." << std::endl;
        return;
    }

    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";

    file.close();
}