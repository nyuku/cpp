// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Abstract class: non-instanciable
//          ✩ a au moins 1 méthode virtuelle pure "=0" -> reusitliser dans les autres classes
//          ✩ Destructor en virtual
//       ✩ 3 classes héritant de AForm: PresidentialPardonForm, RobotomyRequestForm, ShrubberyCreationForm
//       ✩ Ajouter une fonction "execute" à AForm et Bureaucrat
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef AFORM_HPP
#define AFORM_HPP

#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_BLUE      "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m"
#define MAGENTA		  	"\033[0;35m"
#define LILAC		   	"\033[0;94m"
#define BLUE		   	"\033[0;34m"
#define LIGHT_TURCOI    "\033[0;36m"
#define LIGHT_RED	  	"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE	    "\033[0;94m"
#define PEACH		    "\033[0;93m"
#define LIGHT_CYAN      "\033[0;36m"
#define BOLD		    "\033[1m"
#define ENDL            std::endl

# include <iostream>
# include <stdexcept>
# include <string>
// # include "Bureaucrat.hpp"

class Bureaucrat;


class AForm
{
   
    private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

    protected:
        void    checkGradesSignExec(int requiredExecGrade, const Bureaucrat &executor) const;
	
    public:
        //	✩  ---------   Constructor- destructor      --------- 
		AForm();
        virtual ~AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(AForm const & src);

         //	✩  ---------   Operator      ---------
		AForm	&operator=(AForm const & rhs);

         //	✩  ---------   Fonctions membres      ---------
		void	        beSigned(Bureaucrat &Bureaucrat);

         //	✩  ---------   Fonctions virtuel      ---------
        virtual void	Execute(Bureaucrat const & executor) const = 0;

		//	✩  ---------   Getters-setters ---------
		std::string		getName() const;
		int				getFormSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

        //  ---------   Exception hériter de classe c++ : std::exception    ---------
        class GradeTooHighException:
            public std::exception
            {
                public:
                    virtual const char* what() const throw();
            };

        class GradeTooLowException:
            public std::exception
            {
            public:
                virtual const char* what() const throw();
            };

        class NotSignedException:
            public std::exception
            {
            public:
                virtual const char* what() const throw();
            };

};

std::ostream	&operator<<(std::ostream & output, AForm const & rhs);

#endif