#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    Bureaucrat b1("Chiara", 20);
    ShrubberyCreationForm s1("teste");

    b1.signForm(s1);
    s1.execute(b1);
}