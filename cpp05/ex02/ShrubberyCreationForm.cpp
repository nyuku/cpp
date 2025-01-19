

     ccee88oo
  C8O8O8Q8PoOb o8oo
 dOB69QO8PdUOpugoO9bD
CgggbU8OU qOp qOdoUOdcb
    6OuU  /p u gcoUodpP
      \\\//  /douUP
        \\\////
         |||/\
         |||\/
         |||||
   .....//||||\....



// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Grade: 1(highest)- 150
//       ✩ Exception pour grade ]1-150[
//       ✩ Vconstante name and grande (private?)
//       ✩ You will implement an overload of the insertion («) 
//       ✩ try et catch.thrown exceptions must be catchable using try and catch blocks
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include ShrubberyCreationForm.hpp

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................
    ShrubberyCreationForm::ShrubberyCreationForm(): 
    {
        _target("Target")
        std::cout	<< "Create a new file with a tree in it. "
                    << std::endl;
    }

    ShrubberyCreationForm::~ShrubberyCreationForm()
    {
        std::cout	<< "The file has been destroyed." << std::endl;
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
        std::cout	<< "A t ree form has been change and copy from "
                << this->_name
                << std::endl;
        return (*this);
    }

 //.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................
    ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
        _target(src._target)
    {
        std::cout	<< " A tree form has been cloned from "
                << this->_name
                << std::endl;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================



//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================


//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================


//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================