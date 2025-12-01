#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    std::cout << "RobotomyRequestForm copy assisgnment operator called" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm () {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getIsSigned() == false)
        throw RobotomyRequestForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw RobotomyRequestForm::GradeTooLowException();
    std::cout << "* Drilling noises... BZZZZZZZZZT!! *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized succesfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->_target << "..." << std::endl;
}

