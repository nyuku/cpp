#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define GRADETOSIGN 25
#define GRADETOEXEC 5

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
    //.......................................................................................................
    //							Constructor - Destructor- Constructor with arg- Copy Constructor		
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & src);

    //.......................................................................................................
    //										    Opérator 
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

    //=======================================================================================================
    //										   Fonctions membres
        void execute(Bureaucrat const & executor) const;  // recuperer de la classe parents AForm

    //=======================================================================================================
    //										   Getters-Setters
        std::string getTarget() const;        
};

#endif