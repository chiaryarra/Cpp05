#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150) {
    // Default constructor
}

Form::Form(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
    // Constructor with parameters
}

Form::Form(const Form &copy) : _name(copy._name), _is_signed(false), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec) {
    // Copy constructor
}

Form& Form::operator=(const Form &copy) {
    // Copy Assignment operator
    if (this != &copy)
        this->_is_signed = copy._is_signed;
    return (*this);
}

Form::~Form() {
    // Destructor
}

// Getters

std::string Form::getName(void) const {
    return (this->_name);
}

bool    Form::getIsSigned(void) const {
    return (this->_is_signed);
}

unsigned int    Form::getGradeToSign(void) const {
    return (this->_grade_to_sign);
}

unsigned int    Form::getGradeToExec(void) const {
    return (this->_grade_to_exec);
}

// Operator overload

std::ostream& operator<<(std::ostream &out, const Form& form) {
    out << "Form " << form.getName() << " is signed?" << form.getIsSigned() << ". Grade to sign: " << form.getGradeToSign() << ". Grade to exec: " << form.getGradeToExec();
    return (out);
}

// Exceptions

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

// Member function

void    Form::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_grade_to_sign >= bureaucrat.getGrade())
        this->_is_signed = true;
    else
        throw Form::GradeTooLowException();
}