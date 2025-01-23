// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		Commandes
// 		 ✩ librairie <fstream> pour creer fichiers
//          ✩ Create a file "Target"
//       ✩ Héritage public de AForm
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#ifndef SCRUBERRYCREATIONFORM_HPP
#define    SCRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define GRADETOSIGN 145
#define GRADETOEXEC 137
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
    //.......................................................................................................
   //							Constructor - Destructor- Constructor with arg- Copy Constructor		
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);

    //.......................................................................................................
   //										    Opérator 
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

    //=======================================================================================================
   //										   Fonctions membres
        void execute(Bureaucrat const & executor) const;  // recuperer de la classe parents AForm

    //=======================================================================================================
    //										   Getters-Setters
        std::string getTarget() const;        
};

#endif