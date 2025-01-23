// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Execute fonction to be define (virtuel) in the child class
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include "PresidentialPardonForm.hpp"

//.......................................................................................................
//										Constructor - Destructor
//.......................................................................................................
    PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("PresidentialPardonForm", GRADETOSIGN, GRADETOEXEC), _target("default_target")
    {
        std::cout	<< "Create a default form to pardon. "
                    << std::endl;
    }

    PresidentialPardonForm::~PresidentialPardonForm()
    {
        std::cout	<< "The file has been destroyed." << std::endl;
    }

    PresidentialPardonForm::PresidentialPardonForm(std::string target): 
    AForm("PresidentialPardonForm", GRADETOSIGN, GRADETOEXEC), _target(target)
    {
        std::cout	<< "Create a new file to pardon. Name: " << target
                    << std::endl;
    }
//.......................................................................................................
//										    Opérator
//.......................................................................................................
    PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
    {
        if (this != &rhs)
        {
            _target = rhs._target;
        }
        std::cout	<< "A pardon form has been change and copy from "
                << this->_name
                << std::endl;
        return (*this);
    }

 //.......................................................................................................
//										 Copy constructor
//.......................................................................................................
    PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
        AForm(src)
    {
        std::cout	<< " A new pardon form has been cloned from "
                << this->_name
                << std::endl;
        *this = src;
    }
//.......................................................................................................
//										   Fonctions membres
//.......................................................................................................
    void   PresidentialPardonForm::execute(Bureaucrat const & executor) const
    {
        checkGradesSignExec(GRADETOEXEC, executor);
        std::cout << "The president , Zaphod Beeblebrox, was pleased to pardon " << _target << std::endl;
    }