// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Execute fonction to be define (virtuel) in the child class
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include "PresidentialPardonForm.hpp"

//.......................................................................................................
//										Constructor - Destructor
//.......................................................................................................
    PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("PresidentialPardonForm", GRADETOSIGN_P, GRADETOEXEC_P), _target("default_target")
    {
        std::cout	<< "Create a default form to pardon. "
                    << std::endl;
    }

    PresidentialPardonForm::~PresidentialPardonForm()
    {
        std::cout	<< "The file has been destroyed." << std::endl;
    }

    PresidentialPardonForm::PresidentialPardonForm(std::string target): 
    AForm("PresidentialPardonForm", GRADETOSIGN_P, GRADETOEXEC_P), _target(target)
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
                << rhs.getName()
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
                << src.getName()
                << std::endl;
        *this = src;
    }
//.......................................................................................................
//										   Fonctions membres
//.......................................................................................................
    void   PresidentialPardonForm::execute(Bureaucrat const & executor) const
    {
        checkGradesSignExec(executor);
          std::cout <<LIGHT_GREEN<<"The Bureaucrat "<< executor.getName() << " executed " << this->_target << RESET_COLOR<< std::endl;
        std::cout <<LIGHT_GREEN<< "The president , Zaphod Beeblebrox, was pleased to pardon " << _target <<RESET_COLOR<< std::endl;
    }