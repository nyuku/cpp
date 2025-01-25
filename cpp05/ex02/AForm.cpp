
// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Grade: 1(highest)- 150
//       ✩ std::string _name : constant, représente le nom du formulaire.
//       ✩ bool _signed : indique si le formulaire est signé (initialisé à false)
//       ✩ const int _gradeToSign : grade minimal requis pour signer
//       ✩ const int _gradeToExecute : grade minimal requis pour exécuter le formulaire.
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "AForm.hpp"
#include "Bureaucrat.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................
    AForm::AForm():
                _name("Birthday card"),
                _signed(false),
                _gradeToSign(3),
                _gradeToExec(5)
    {
        std::cout	<<"New Form Created: "<< _name << " needs to be signed." << std::endl;
    }

    AForm::~AForm()
    {
        std::cout	<< _name << " srrrrcchhhh... the form has been destroyed." << std::endl;
    }
    
    AForm::AForm(std::string name, int gradeToSign, int gradeToExec):
        _name(name),
        _signed(false),
        _gradeToSign(gradeToSign),
        _gradeToExec(gradeToExec)
        {
            if ((_gradeToSign < 1) || (_gradeToExec < 1))
                throw (AForm::GradeTooHighException());
            else if ((_gradeToSign > 150) || (_gradeToExec > 150))
                throw (AForm::GradeTooLowException());

            std::cout	<< "New Form created:  " <<_name << " needs to be filled." << std::endl;
        }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    AForm &AForm::operator=(AForm const & rhs)
    {
        if (this != &rhs)
        {
            _signed = rhs._signed;
        }
        std::cout	<< "A form has been change and copy from "
                << this->_name
                << std::endl;
        return (*this);
    }

 //.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................
    AForm::AForm(AForm const & src):
        _name(src._name),
        _signed(false),
        _gradeToSign(src._gradeToSign),
        _gradeToExec(src._gradeToExec)
    {
         std::cout	<< "A new form has been cloned from "
                    << this->_name
                    << std::endl;
    }

// //=======================================================================================================
// //										   Fonctions membres											|
// //=======================================================================================================
//     void	AForm::beSigned(Bureaucrat &Bureaucrat)
//     {
//         if (Bureaucrat.getGrade() > this->getSignGrade())
//             throw (AForm::GradeTooLowException());
//         else
//             this->_signed = true;
//     }

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================
    std::string		AForm::getName() const
    {
        return (_name);
    }

    int				AForm::getFormSigned() const
    {
        return (_signed);
    }

    int				AForm::getSignGrade() const
    {
        return (_gradeToSign);
    }

    int				AForm::getExecGrade() const
    {
        return (_gradeToExec);
    }

//=======================================================================================================
//                                      Fonctions membres
//=======================================================================================================
    void    AForm::beSigned(Bureaucrat &Bureaucrat)
    {
        if (Bureaucrat.getGrade() <= this->_gradeToSign)
            this->_signed = true;
        else
            throw GradeTooLowException();
    }
//=======================================================================================================
//                                     Fonctions protected("privé a la classe et aux enfants")          
//=======================================================================================================
    void AForm::checkGradesSignExec(const Bureaucrat &executor) const
    {
        if (executor.getGrade() > this->_gradeToExec)
        {    
            std::cout<<LIGHT_RED<<"Form error: "<<executor.getName()<<" cannot execute the form: "<<this->_name<<RESET_COLOR<<std::endl;
            throw (AForm::GradeTooLowException());
        }
    }
    //le controle "signed" ne sera pas atteint car deja bloc par le l'exeption signForm
    //  void AForm::checkGradesSignExec(const Bureaucrat &executor) const
    // {
    //     if (!this->_signed)
    //         throw (AForm::NotSignedException());
    //     else if (executor.getGrade() > this->_gradeToExec)
    //         throw (AForm::GradeTooLowException());
    // }


//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================

    std::ostream& operator<<(std::ostream & output, AForm const & rhs)
    {
        output << LIGHT_BLUE
               << "\nThe form: "
               << rhs.getName() 
               << " need a burocrate's grade of " << rhs.getSignGrade() << " to be signed.\n" << "and a burocrate's grade of " << rhs.getExecGrade() << " to be execute.\n"
               << "Current status: "
               << RESET_COLOR;
        if (rhs.getFormSigned() == 0)
            output << LIGHT_RED 
                   <<"not signed.\n"
                   << RESET_COLOR;
        else
            output << GREEN
                   << "signed.\n"
                   << RESET_COLOR;   
        return output;
    }
//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================

    const char* AForm::GradeTooHighException::what() const throw()
    {
        return (LIGHT_RED"ERROR: Grade is too high."RESET_COLOR);
    }

    const char* AForm::GradeTooLowException::what() const throw()
    {
        return (LIGHT_RED"ERROR: Grade is too low."RESET_COLOR);
    }

    const char* AForm::NotSignedException::what() const throw()
    {
        return (LIGHT_RED"ERROR: Form is not signed."RESET_COLOR);
    }