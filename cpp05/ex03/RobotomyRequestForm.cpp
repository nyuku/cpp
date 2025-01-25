// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |	 ✩ Execute fonction to be define (virtuel) in the child class
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include"RobotomyRequestForm.hpp"

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
                << rhs.getName()
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
                << src.getName()
                << std::endl;
        *this = src;
    }

//.......................................................................................................
//										   Fonctions membres
//.......................................................................................................
 void   RobotomyRequestForm::execute(Bureaucrat const & executor) const
 {
    std::srand(std::time(nullptr));
    checkGradesSignExec(executor);
    std::cout   <<"The Bureaucrat "
                << executor.getName() << " executed " 
                << this->_target  << "\n"<< RESET_COLOR<< std::endl;
    int randomValue = rand() % 2; // Stockez le résultat pour inspection
    std::cout << "Random value: " << randomValue << std::endl; // Ajoutez cette ligne pour le débogage

    if (randomValue) {
        std::cout << LIGHT_GREEN << _target << " has been robotomized successfully.\n" << RESET_COLOR << std::endl;
    } else {
        std::cout << LIGHT_RED << _target << " robotomization failed.\n" << RESET_COLOR << std::endl;
    }
    //  std::cout << "* LOUD DRILL NOISES *" << std::endl;
    //     if (rand() % 2)
    //         std::cout <<LIGHT_GREEN<< _target << " has been robotomized successfully." <<RESET_COLOR<< std::endl;
    //     else
    //         std::cout <<LIGHT_RED<< _target << " robotomization failed." << RESET_COLOR<<std::endl;
 }


     