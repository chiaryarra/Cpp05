#include "Bureaucrat.hpp"

int main(void) {
    try {    
        Bureaucrat b1("Chiara", 0);
        Bureaucrat b2("Henrique", 10);
        Bureaucrat b3("Alessandro", 180);
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Chiara", 149);
        b4.decrement();
        b4.decrement();
    }
    catch (std::exception &e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}