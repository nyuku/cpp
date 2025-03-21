// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		CommandeS 
// 		 ✩ Grade: 1(highest)- 150
//       ✩ Exception pour grade ]1-150[
//       ✩ Vconstante name and grande (private?)
//       ✩ You will implement an overload of the insertion («) 
//       ✩ try et catch.thrown exceptions must be catchable using try and catch blocks
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include"Bureaucrat.hpp"
#include "AForm.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................

    Bureaucrat::Bureaucrat(): _grade(42), _name("Bertrand")
    {
        std::cout	<< _name << " \t[" << _grade << "]"
                    << " Welcome to the corporate life."
                    << std::endl;
    }

    Bureaucrat::~Bureaucrat()
    {
        std::cout	<< _name << " \t[" << _grade << "]"
                    << " Closing hour!"
                    << std::endl;
    }

    Bureaucrat::Bureaucrat(int grade, const std::string name) : _grade(grade), _name(name)
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        else
        {
        std::cout	<< _name << " \t[" << _grade << "]"
                    << " Welcome to the corporate life."
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
            // _name = rhs._name; nope car const uniquement lors de la creation
            _grade = rhs._grade;
            std::cout	<< " a bureaucrat has been cloned from "
                    << this->_name
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
        if (this->_grade < 1)
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
        if (this->_grade > 150)
            throw (GradeTooLowException());
        else
        {
            std::cout	<<LIGHT_RED<< "What a shame, " << _name << " lost some pride, current grade: "
                        << _grade << RESET_COLOR<< std::endl;
        }
    }

    void Bureaucrat::signForm(AForm& form)
    {
        if (this->getGrade() <= form.getSignGrade())
        {
            form.beSigned(*this);
            std::cout << this->getName() << " signed " << form.getName() << std::endl;
        }
        else
        {
            std::cout <<LIGHT_RED<<"The Bureaucrat "<< this->getName() << " couldn't sign: " << form.getName() <<RESET_COLOR<< "\n";
            throw AForm::GradeTooLowException();
        }
    }

    void Bureaucrat::executeForm(AForm const & form)//->execute de AForm->execute les autres classe enfants
    {   
        form.execute(*this);
        // std::cout <<LIGHT_GREEN<<"The Bureaucrat "<< this->getName() << " executed " << form.getName() << RESET_COLOR<< std::endl;
    }

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================

    // std::string	Bureaucrat::getName() const
    // {
    //     return (this->_name);
    // }

    std::string		Bureaucrat::getName() const
    {
        return (_name);
    }

    int				Bureaucrat::getGrade() const
    {
        return (_grade);
    }

//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================

    std::ostream & operator<<(std::ostream & output, Bureaucrat const & rhs)
    {
        output	<< LIGHT_TURCOI
                << "• Name: "<< rhs.getName()
                << " / "
                << "Bureaucrat grade: "<< rhs.getGrade()
                << RESET_COLOR;
        return (output);
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
