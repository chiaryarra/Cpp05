#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string	_name;
    bool				_is_signed;
	const unsigned int	_grade_to_sign;
	const unsigned int	_grade_to_exec;
public:
	// Constructor with parameters
	AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec);
	
	// Orthodox Canonical AForm
	AForm();
	AForm(const AForm &copy);
	AForm& operator=(const AForm &copy);
    ~AForm();

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

std::ostream& operator<<(std::ostream& out, const AForm& aform);

#endif