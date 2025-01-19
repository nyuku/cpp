// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		Commandes
// 		 ✩ librairie <fstream> pour creer fichiers
//       ✩ Create a file "Target"
//       ✩ 
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#ifndef SCRUBERRYCREATIONFORM_HPP
#def    SCRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

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
        void beExecute(Bureaucrat const & executor) const;  // recuperer de la classe parents AForm
};

#endif