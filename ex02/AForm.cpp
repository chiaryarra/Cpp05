#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150) {
    // Default constructor
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
    // Constructor with parameters
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _is_signed(false), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec) {
    // Copy constructor
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &copy) {
    // Copy Assignment operator
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_is_signed = copy._is_signed;
    return (*this);
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
    // Destructor
}

// Getters

std::string AForm::getName(void) const {
    return (this->_name);
}

bool    AForm::getIsSigned(void) const {
    return (this->_is_signed);
}

unsigned int    AForm::getGradeToSign(void) const {
    return (this->_grade_to_sign);
}

unsigned int    AForm::getGradeToExec(void) const {
    return (this->_grade_to_exec);
}

// Operator overload

std::ostream& operator<<(std::ostream &out, const AForm& form) {
    out << "AForm " << form.getName() << " is signed?" << form.getIsSigned() << ". Grade to sign: " << form.getGradeToSign() << ". Grade to exec: " << form.getGradeToExec();
    return (out);
}

// Exceptions

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed!");
}

// Member function

void    AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_grade_to_sign >= bureaucrat.getGrade())
        this->_is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

