// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		CommandeS 
// 		 ✩ canoninal orthodox form
// 		 ✩ Grade: 1(highest)- 150
//       ✩ Exception pour grade ]1-150[
//       ✩ Vconstante name and grande (private?)
//       ✩ You will implement an overload of the insertion («) 
//       ✩ try et catch.thrown exceptions must be catchable using try and catch blocks
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include"Bureaucrat.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................

    Bureaucrat::Bureaucrat(): _grade(42), _name("Bertrand")
    {
        std::cout	<< _name << " [" << _grade << "]"
                    << "\tWelcome to the corporate life."
                    << std::endl;
    }

    Bureaucrat::~Bureaucrat()
    {
         std::cout	<< _name ;
        if (_grade >= GRADEHIGH && _grade <= GRADELOW)
            std::cout	<< " [" << _grade << "] \t";
        else
            std::cout	<< " [Dismiss] \t";
        std::cout	<< " Closing hour!"
                    << std::endl;
    }

    Bureaucrat::Bureaucrat(int grade, const std::string name) : _grade(grade), _name(name)
    {
        if (grade < GRADEHIGH)
            throw GradeTooHighException();
        else if (grade > GRADELOW)
            throw GradeTooLowException();
        else
        {
            std::cout	<< _name << " [" << _grade << "]"
                    << "\tWelcome to the corporate life."
                    << std::endl;
        }
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    
    Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
    {
        if (this != &rhs)
        {
            // _name ? nope car const uniquement lors de la creation
            _grade = rhs._grade;
            std::cout	<< " a bureaucrat has been cloned from "
                    << rhs._name
                    << std::endl;
        }
        return (*this);
    }

//.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................

    Bureaucrat::Bureaucrat(Bureaucrat const & src) : _grade(src._grade), _name(src._name)
    {
        std::cout	<< " a bureaucrat has been cloned from "
                    << this->_name
                    << std::endl;
    }

    // V2 avec operateur d'assignation:
    // Bureaucrat::Bureaucrat(Bureaucrat const & src):
    // 	_name(src.getName())
    // {
    //  	*this = src;
    // }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================

    void	Bureaucrat::promoteBureaucrat()
    {
        this->_grade--;
        if (this->_grade < GRADEHIGH)
            throw (GradeTooHighException());
        else
        {
            std::cout	<<LIGHT_GREEN<< "Congrats! " << _name << " has been promoted, current grade: "
                        << _grade <<RESET_COLOR<< std::endl;
        }
    }

    void	Bureaucrat::demoteBureaucrat()
    {
        this->_grade++;
        if (this->_grade > GRADELOW)
            throw (GradeTooLowException());
        else
        {
            std::cout	<<LIGHT_RED<< "What a shame, " << _name << " lost some pride, current grade: "
                        << _grade << RESET_COLOR<< std::endl;
        }
    }


//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================

    std::string		Bureaucrat::getName() const
    {
        return (_name);
    }

    int				Bureaucrat::getGrade() const
    {
        return (_grade);
    }

//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================

    const char* Bureaucrat::GradeTooHighException::what() const throw()
    {
        return ("ERROR: Grade is too high.");
    }

    const char* Bureaucrat::GradeTooLowException::what() const throw()
    {
        return ("ERROR: Grade is too low.");
    }

//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================

    std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
    {
        o	<< LIGHT_TURCOI
            << "• Name: "<< rhs.getName()
            << " / "
            << "Bureaucrat grade: "<< rhs.getGrade()
            << RESET_COLOR;
        return (o);
    }
