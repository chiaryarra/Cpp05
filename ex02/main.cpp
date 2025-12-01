#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentalPardonForm.hpp"

int main(void) {

    try {
        Bureaucrat burocrata("Chiara", 5);
        ShrubberyCreationForm tree("arvores");
        RobotomyRequestForm rob("Robô");
        PresidentalPardonForm pardon("Chiara");
        burocrata.signForm(tree);
        burocrata.signForm(rob);
        burocrata.signForm(pardon);
        tree.execute(burocrata);
        rob.execute(burocrata);
        pardon.execute(burocrata);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}