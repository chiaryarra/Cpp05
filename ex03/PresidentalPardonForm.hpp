#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentalPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentalPardonForm();
    PresidentalPardonForm(std::string target);
    PresidentalPardonForm(const PresidentalPardonForm &copy);
    PresidentalPardonForm& operator=(const PresidentalPardonForm &copy);
    ~PresidentalPardonForm();
    void execute(const Bureaucrat &executor) const;
};


#endif
