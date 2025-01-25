#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <fstream>
#include <cstdlib> // rand

#define GRADETOSIGN_R 72
#define GRADETOEXEC_R 45

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
    //.......................................................................................................
    //							Constructor - Destructor- Constructor with arg- Copy Constructor		
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);

    //.......................................................................................................
    //										    Opérator 
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

    //=======================================================================================================
    //										   Fonctions membres
        void execute(Bureaucrat const & executor) const;  // recuperer de la classe parents AForm

    //=======================================================================================================
    //										   Getters-Setters
        std::string getTarget() const;        
};
#endif