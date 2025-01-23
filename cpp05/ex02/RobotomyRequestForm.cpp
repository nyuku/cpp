// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |	 ✩ Execute fonction to be define (virtuel) in the child class
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include"robotomyRequestForm.hpp"

//.......................................................................................................
//										Constructor - Destructor
//.......................................................................................................
    RobotomyRequestForm::RobotomyRequestForm(): 
    AForm("RobotomyRequestForm", GRADETOSIGN_R, GRADETOEXEC_R), _target("default_target")
    {
        std::cout	<< "Create a default to robotomized. "
                    << std::endl;
    }

    RobotomyRequestForm::~RobotomyRequestForm()
    {
        std::cout	<< "The file has been destroyed." << std::endl;
    }

    RobotomyRequestForm::RobotomyRequestForm(std::string target): 
    AForm("RobotomyRequestForm", GRADETOSIGN_R, GRADETOEXEC_R), _target(target)
    {
        std::cout	<< "Create a new file robotomized. Name: " << target
                    << std::endl;
    }
//.......................................................................................................
//										    Opérator        
//.......................................................................................................
    RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
    {
        if (this != &rhs)
        {
            _target = rhs._target;
        }
        std::cout	<< "A robotomized form has been change and copy from "
                << this->_name
                << std::endl;
        return (*this);
    }

 //.......................................................................................................
//										 Copy constructor
//.......................................................................................................
    RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
        AForm(src)
    {
        std::cout	<< " A new robotomized form has been cloned from "
                << this->_name
                << std::endl;
        *this = src;
    }

//.......................................................................................................
//										   Fonctions membres
//.......................................................................................................
 void   RobotomyRequestForm::execute(Bureaucrat const & executor) const
 {
     checkGradesSignExec(GRADETOEXEC, executor);
     std::cout << "* LOUD DRILL NOISES *" << std::endl;
        if (rand() % 2)
            std::cout << _target << " has been robotomized successfully." << std::endl;
        else
            std::cout << _target << " robotomization failed." << std::endl;
 }


     