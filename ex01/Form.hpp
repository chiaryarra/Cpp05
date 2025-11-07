#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" 

class Form
{
private:
    const std::string	_name;
    bool				_is_signed;
	const unsigned int	_grade_to_sign;
	const unsigned int	_grade_to_exec;
public:
	// Constructor with parameters
	Form(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec);
	
	// Orthodox Canonical Form
	Form();
	Form(const Form &copy);
	Form& operator=(const Form &copy);
    ~Form();

	// Exception Classes
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};

	// Getters
	std::string 	getName(void) const;
	bool			getIsSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExec(void) const;
	// Member Functions
	void	beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif