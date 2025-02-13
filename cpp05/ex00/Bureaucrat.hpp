// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		CommandeS 
// 		 ✩ Grade: 1(highest)- 150
//       ✩ Exception pour grade <1 >150
//       ✩ Vconstante name and grande (private?)
//       ✩ You will implement an overload of the insertion («) 
//       ✩ try et catch.thrown exceptions must be catchable using try and catch blocks
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#define RESET_COLOR		"\033[0m"
#define GREEN			    "\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_BLUE    "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m"
#define MAGENTA		  	"\033[0;35m"
#define LILAC		    	"\033[0;94m"
#define BLUE		    	"\033[0;34m"
#define LIGHT_TURCOI  "\033[0;36m"
#define LIGHT_RED	  	"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE		  "\033[0;94m"
#define PEACH		    	"\033[0;93m"
#define LIGHT_CYAN    "\033[0;36m"
#define BOLD		     	"\033[1m"
#define ENDL          std::endl

#define GRADELOW      150
#define GRADEHIGH      1


#include <string>
#include <iostream>

class Bureaucrat
{
	private:
    //	✩  ---------   Variables      ------------------------------------------------------------ 
		int			            _grade;
    std::string	const   _name;
		
  public:
    //	✩  ---------   Constructor - destructor - Constructor arg - Constructor copy     --------- 
		Bureaucrat();
    ~Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(Bureaucrat const & src);

    //	✩  ---------   Operator      -------------------------------------------------------------
		Bureaucrat & operator=(Bureaucrat const & rhs);

    //	✩  ---------   Fonctions membres      ----------------------------------------------------
		void	              promoteBureaucrat();// diminue le grade-> --
		void	              demoteBureaucrat();//diminue le grade -> ++

    //	✩  ---------   Getters-setters ------------------------------------------------------------
    std::string		      getName() const;
    int				          getGrade() const;
  //...............................................................................................
  //										                  Exception hériter de classe c++ :  			
  //                                            std::exception						                         |
  //...............................................................................................

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};

//...................................................................................................
//										                            Opérator 	<<				
//                                 affiche : <name>, bureaucrat grade <grade>.						           |
//...................................................................................................

  std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
