#include "Bureaucrat.hpp"

int	main()
{
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test constructor, operator, standard, demote, promote --------" << RESET_COLOR<< std::endl;
        try
        {
                //Constructeur avec parametre
                    Bureaucrat	Belle(150, "Belle"); 
                    std::cout	<< Belle << ENDL<<std::endl;

                    Bureaucrat Professeur(1, "Professeur");
                    std::cout	<< Professeur << ENDL<< std::endl;
                //Constructeur standard, standard name = Bertrand
                    Bureaucrat	Bulle; 
                    std::cout	<< Bulle << ENDL<< std::endl;
                    std::cout <<"Promote:" <<ENDL;
                    Bulle.promoteBureaucrat();
                    std::cout	<< Bulle<< ENDL << std::endl;
                //Constructeur par copie
                    std::cout <<"Copie:" << ENDL;
                    Bureaucrat	Rebelle = Bulle; 
                    std::cout	<< Rebelle << ENDL<< std::endl;
                    std::cout <<"Demomote:" << ENDL;
                    Rebelle.demoteBureaucrat();
                    std::cout	<< Rebelle << ENDL<< std::endl;
                //test operateur d'affectation
                    std::cout <<"Operator = basic:" << ENDL;
                    Bureaucrat  Mojojo;
                    Mojojo = Bulle;
                    std::cout	<< Mojojo << ENDL<< std::endl;
        }
        catch (Bureaucrat::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Bureaucrat::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
            std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrat grade:1 - promote to 0 --------" <<RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Princess(1, "bob");
            Princess.promoteBureaucrat();
        }
        catch (Bureaucrat::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Bureaucrat::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrat grade:150 - demomote to 151 --------" <<RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Sedusa(150, "Sadusa");
            Sedusa.demoteBureaucrat();
        }
        catch (Bureaucrat::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Bureaucrat::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrate grade:151 --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Barbara(151, "Barbara");
            std::cout	<< Barbara << std::endl;
        }
        catch (Bureaucrat::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Bureaucrat::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
            std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {   std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrate grade:0 --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Lui(0, "lui");
            std::cout	<< Lui << std::endl;// excep! grade too high
        }
        catch (Bureaucrat::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Bureaucrat::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
            std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
}
