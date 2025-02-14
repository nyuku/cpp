
// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Grade: 1(highest)- GRADELOW
//       ✩ std::string _name : constant, représente le nom du formulaire.
//       ✩ bool _signed : indique si le formulaire est signé (initialisé à false)
//       ✩ const int _gradeToSign : grade minimal requis pour signer
//       ✩ const int _gradeToExecute : grade minimal requis pour exécuter le formulaire.
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "Form.hpp"
#include "Bureaucrat.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................
    Form::Form():
                _name("Hbdcard"),
                _signed(false),
                _gradeToSign(3),
                _gradeToExec(5)
    {
        std::cout	<<"New Form Created: "<< _name << std::endl;
    }

    Form::~Form()
    {
        std::cout	<< _name << " srrrrcchhhh... the form has been destroyed." << std::endl;
    }
    
    Form::Form(std::string name, int gradeToSign, int gradeToExec):
        _name(name),
        _signed(false),
        _gradeToSign(gradeToSign),
        _gradeToExec(gradeToExec)
        {
            if ((_gradeToSign < GRADEHIGH) || (_gradeToExec < GRADEHIGH))
                throw (Form::GradeTooHighException());
            else if ((_gradeToSign > GRADELOW) || (_gradeToExec > GRADELOW))
                throw (Form::GradeTooLowException());

            std::cout	<< "New Form created:  " <<_name  << std::endl;
        }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    Form &Form::operator=(Form const & rhs)
    {
        if (this != &rhs)
        {
            _signed = rhs._signed;
        }
        std::cout	<< "A form has been change and copy from "
                << rhs._name
                << std::endl;
        return (*this);
    }

 //.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................
    Form::Form(Form const & src):
        _name(src._name),
        _signed(false),
        _gradeToSign(src._gradeToSign),
        _gradeToExec(src._gradeToExec)
    {
         std::cout	<< "A new form has been cloned from "
                    << this->_name
                    << std::endl;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
    void	Form::beSigned(Bureaucrat &Bureaucrat)
    {
        if (Bureaucrat.getGrade() > this->getSignGrade())
            throw (Form::GradeTooLowException());
        else
            this->_signed = true;
    }

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
    std::string		Form::getName() const
    {
        return (_name);
    }

    int				Form::getFormSigned() const
    {
        return (_signed);
    }

    int				Form::getSignGrade() const
    {
        return (_gradeToSign);
    }

    int				Form::getExecGrade() const
    {
        return (_gradeToExec);
    }

//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================

    std::ostream& operator<<(std::ostream & output, Form const & rhs)
    {
        
        output << "Current status: ";
        if (rhs.getFormSigned() == 0)
            output << LIGHT_RED 
                   <<"not signed.\n"
                   << RESET_COLOR;
        else
            output << GREEN
                   << "signed.\n"
                   << RESET_COLOR;   
        output << LIGHT_BLUE
               << "The form: "
               << rhs.getName() 
               << " need burocrate's grade of : \t\t" << rhs.getSignGrade() << " to be signed.\n" << "\t\t\t\t\t\t\t" << rhs.getExecGrade() << " to be execute.\n"
               << RESET_COLOR;
        
        return output;
    }
//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================

    const char* Form::GradeTooHighException::what() const throw()
    {
        return (LIGHT_RED "ERROR: Grade is too high." RESET_COLOR);
    }

    const char* Form::GradeTooLowException::what() const throw()
    {
        return (LIGHT_RED "ERROR: Grade is too low." RESET_COLOR);
    }
