#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
private:
    const std::string	_name;
    unsigned int		_grade;
public:
	// Form Orthodox canonical
    Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat& operator=(const Bureaucrat &copy);
    ~Bureaucrat();
	
	// Getters
	std::string		getName() const;
	unsigned int	getGrade() const;
	
	// Class methods
	void			increment();
	void			decrement();
	void			signForm(AForm &aform);

	// Exception Classes
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif