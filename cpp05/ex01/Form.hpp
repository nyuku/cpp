// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Grade: 1(highest)- 150
//       ✩ Exception pour grade <1 >150
//       ✩ You will implement an overload of the insertion («) 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef FORM_HPP
#define FORM_HPP

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


class Bureaucrat;


class Form
{
    private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;

	public:
        //	✩  ---------   Constructor- destructor      --------- 
		Form();
        ~Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(Form const & src);

         //	✩  ---------   Operator      ---------
		Form	&operator=(Form const & rhs);

         //	✩  ---------   Fonctions membres      ---------
		void	beSigned(Bureaucrat &Bureaucrat);

		//	✩  ---------   Getters-setters ---------
		std::string		getName() const;
		int				getFormSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

        //	✩  ---------   Exception hériter de classe c++ : std::exception    ---------
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

};
//...................................................................................................
//										           Opérator <<				
//                                 affiche : <name>, bureaucrat grade <grade>.						  |
//...................................................................................................

std::ostream	&operator<<(std::ostream & output, Form const & rhs);

#endif