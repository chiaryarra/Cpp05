#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int main(void) {

    std::srand(time(NULL));
    try {
        Bureaucrat burocrata("Chiara", 5);
        ShrubberyCreationForm tree("arvores");
        RobotomyRequestForm rob("Robô");
        PresidentalPardonForm pardon("Chiara");
        burocrata.signForm(tree);
        burocrata.signForm(rob);
        burocrata.signForm(pardon);
        burocrata.executeForm(tree);
        burocrata.executeForm(rob);
        burocrata.executeForm(pardon);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}