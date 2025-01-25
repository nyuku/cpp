// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Pas d'attribut
//       ✩ créer que des formulaires connus: ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
//       ✩ retourne un pointeur sur un objet de type AForm
//       ✩ Affiche le message : Intern creates <form>
//       ✩ Si le nom du formulaire est invalide, la fonction doit afficher une erreur explicite.
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝


#ifndef INTERN_HPP 
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

class Intern
{
    private:
        //	✩  ---------   Fonctions internes     ---------
        AForm* newPresident(std::string target);
        AForm* newRobot(std::string target);
        AForm* newShrubb(std::string target);
    public:
        //	✩  ---------   Constructor-destructor-construcor copy      --------- 
        Intern();
        ~Intern();
        Intern(Intern const & src);

        //	✩  ---------   Operator      ---------
        Intern & operator=(Intern const & rhs);

        //	✩  ---------   Fonctions membres      ---------
        AForm *makeForm(std::string nameForm, std::string target);
};
#endif