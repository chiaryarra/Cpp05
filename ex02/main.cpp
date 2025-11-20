#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    Bureaucrat b1("Chiara", 20);
    Form f1("Arquivo teste", 10, 5);

    b1.signForm(f1);
}