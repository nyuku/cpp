// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Execute fonction to be define (virtuel) in the child class
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "ShrubberyCreationForm.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................
    ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("ShrubberyCreationForm", GRADETOSIGN_S, GRADETOEXEC_S), _target("default_target")
    {
        std::cout	<< "Shrubbery: Create a default new file with a tree in it. "
                    << std::endl;
    }

    ShrubberyCreationForm::~ShrubberyCreationForm()
    {
        std::cout	<< "Shrubbery: The file has been destroyed." << std::endl;
    }

    ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
    AForm("ShrubberyCreationForm", GRADETOSIGN_S, GRADETOEXEC_S), _target(target)
    {
        std::cout	<< "Shrubbery: Create a new file with a tree in it. Name: " << target
                    << std::endl;
    }
//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
    {
        if (this != &rhs)
        {
            _target = rhs._target;
        }
        std::cout	<< "A tree form has been change and copy from "
                << rhs.getName()
                << std::endl;
        return (*this);
    }

 //.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................
    ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
        AForm(src)
    {
        std::cout	<< " A new tree form has been cloned from "
                << src.getName()
                << std::endl;
        *this = src;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
 void   ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkGradesSignExec(executor);
    {
        std::string nameFile = (this->getTarget() + "_shruberry");
        std::ofstream file(nameFile.c_str()); // Création et ouverture auto du fichier
         if (!file.is_open())
            std::cerr << "Error: opening file." << std::endl;
         else
         {
                std::cout   <<"The Bureaucrat "
                            <<BOLD
                            << executor.getName()
                            << RESET_COLOR
                            << " has executed the form: "
                            << BOLD
                            << this->getName()
                            << "\n"
                            <<RESET_COLOR
                            << std::endl;
                file << 
                    "       _-_\n"
                    "    /~~   ~~\\\n"
                    " /~~         ~~\\\n"
                    "{               }\n"
                    " \\  _-     -_  /\n"
                    "   ~  \\\\ //  ~\n"
                    "_- -   | | _- _\n"
                    "  _ -  | |   -_\n"
                    "      // \\\\" 
                    <<"\nexec by: " << executor.getName()
                    << std::endl;
                file.close();
            }
    }
}

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
   std::string  ShrubberyCreationForm::getTarget() const
    {
        return (_target);
    }
