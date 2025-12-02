#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "Intern.hpp"

int main(void) {

    std::srand(time(NULL));
    try {
        Intern randomIntern;
        Bureaucrat burocrata("Chiara", 5);
        AForm* arvore = randomIntern.makeForm("shrubbery creation", "arvore");
        burocrata.signForm(*arvore);
        burocrata.executeForm(*arvore);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}