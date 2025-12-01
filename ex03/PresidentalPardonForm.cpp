#include "PresidentalPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentalPardonForm::PresidentalPardonForm() : AForm("PresidentalPardonForm", 25, 5), _target("Default") {
    std::cout << "PresidentalPardonForm default constructor called" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm(std::string target) : AForm("PresidentalPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentalPardonForm constructor called" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm &copy) : AForm(copy), _target(copy._target) {
    std::cout << "PresidentalPardonForm copy constructor called" << std::endl;
}

PresidentalPardonForm& PresidentalPardonForm::operator=(const PresidentalPardonForm &copy) {
    std::cout << "PresidentalPardonForm copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return (*this);
}

PresidentalPardonForm::~PresidentalPardonForm() {
    std::cout << "PresidentalPardonForm destructor called" << std::endl;
}

void    PresidentalPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getIsSigned() == false)
        throw PresidentalPardonForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw PresidentalPardonForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!!" << std::endl;
}