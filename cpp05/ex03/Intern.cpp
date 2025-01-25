// ╔──────────────────────────────────────────────────────────────────────────────────────¤◎¤──────────────────────────────────────────────────────────────────╗
// 		 ✩ Makeform
//          ✩ appelle d'autres fonctions qui créent des formulaires connus: ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
//          ✩ retourne un pointeur sur un objet de type AForm
//          ✩ if/else if: Comparaison entre 2 tableau.
//          ✩ !  "throw AForm::InvalidNameForm();" pour gérer les erreurs de nom de formulaire

//       ✩ tableau de noms de formulaires:    AForm* (Intern::*ptr_form[3])(std::string), tableau de pointeurs sur fonctions qui prenne (string) en arg
//                                            AForm* Intern::president(std::string target)
// ╚──────────────────────────────────────────────────────────────────────────────────────¤◎¤──────────────────────────────────────────────────────────────────╝

#include "Intern.hpp"

//.......................................................................................................  
//										Constructor - Destructor- Copy constructor
//.......................................................................................................
    Intern::Intern()
    {
        std::cout	<< "Intern is here. Time to make some coffee.\n" << std::endl;
    }

    Intern::~Intern()
    {
        std::cout	<< "Intern is gone." << std::endl;
    }
    
    Intern::Intern(Intern const & src)
    {
        std::cout	<< "Intern is cloned." << std::endl;
        *this = src;
    }
//.......................................................................................................
//										    Opérator
//.......................................................................................................
    Intern &Intern::operator=(Intern const & rhs)
    {
        std::cout	<< "Intern has been copy"
                    << std::endl;
        (void)rhs;
        return (*this);
    }

 //.......................................................................................................
//                                         Fonctions membres
//.......................................................................................................
    AForm *Intern::makeForm(std::string nameForm, std::string target)
    {
        // tableau de noms de formulaires
        const std::string FormExisting[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
        
        //tableau qui contient les ptr sur les fonctions pour creer les formulaires
        AForm* (Intern::*ptr_form[3])(std::string) = {&Intern::newPresident, &Intern::newRobot, &Intern::newShrubb};

        //boucle pour comparer les noms
        for (int i = 0; i < 3; i++)
        {
            if (FormExisting[i] == nameForm)
            {
                std::cout << CYAN<< "Intern creates " << nameForm << RESET_COLOR<< std::endl;
                return ((this->*ptr_form[i])(target));
            }
        }
        std::cout   <<LIGHT_RED<< "Error: The form " 
                    << nameForm << " doesn't exist ! Please take this coffee and try with "
                    <<LIGHT_TURCOI
                    <<"presidential pardon, robotomy request, shrubbery creation" 
                    <<RESET_COLOR<< std::endl;
        throw AForm::InvalidNameForm();
    }
//.......................................................................................................
//										    Fonctions internes
//.......................................................................................................
    AForm* Intern::newPresident(std::string target)
    {
        return (new PresidentialPardonForm(target));
    }

    AForm* Intern::newRobot(std::string target)
    {
        return (new RobotomyRequestForm(target));
    }

    AForm* Intern::newShrubb(std::string target)
    {
        return (new ShrubberyCreationForm(target));
    }