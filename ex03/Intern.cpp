#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) {
    (void)copy;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &copy) {
    std::cout << "Intern copy assignment operator" << std::endl;
    if (this != &copy)
        *this = copy;
    return (*this);
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm*    Intern::makeForm(std::string form_name, std::string form_target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidental pardon"
    };
    int i = 0;
    while (i < 3)
    {
        if (form_name == names[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            switch (i)
            {
            case 0: return new ShrubberyCreationForm(form_target);
            case 1: return new RobotomyRequestForm(form_target);
            case 2: return new PresidentalPardonForm(form_target);
            }
        }
        i++;
    }
    std::cout << "Intern couldn't find form: " << form_name << std::endl;
    return (NULL);
}