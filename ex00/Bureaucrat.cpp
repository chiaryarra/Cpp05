#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    // Default constructor
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade) {
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {
    // Copy constructor
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    // Copy Assignment operator
    if (this != &copy)
        _grade = copy._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    // Destructor
}

// Getters

std::string    Bureaucrat::getName() const {
    return (this->_name);
}

unsigned int    Bureaucrat::getGrade() const {
    return (this->_grade);
}

// Member functions 

void    Bureaucrat::increment() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decrement() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}

