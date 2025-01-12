#include "Bureaucrat.hpp"

int	main()
{
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test constructor, operator, standard, demote, promote --------" << RESET_COLOR<< std::endl;
        try
        {
                //Constructeur avec parametre
                    Bureaucrat	Belle(150, "Belle"); 
                    std::cout	<< Belle << std::endl;

                    Bureaucrat Professeur(1, "Professeur");
                    std::cout	<< Professeur << std::endl;
                //Constructeur standard, standard name = Bertrand
                    Bureaucrat	Bulle; 
                    std::cout	<< Bulle << std::endl;
                    Bulle.promoteBureaucrat();
                    std::cout	<< Bulle << std::endl;
                //Constructeur par copie
                    Bureaucrat	Rebelle = Bulle; 
                    std::cout	<< Rebelle << std::endl;
                    Rebelle.demoteBureaucrat();
                    std::cout	<< Rebelle << std::endl;
                //test operateur d'affectation 
                    Bureaucrat  Mojojo;
                    Mojojo = Bulle;
                    std::cout	<< Mojojo << std::endl;
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
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrat 1 - promote to 0 --------" <<RESET_COLOR<< std::endl;
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
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrat 150 - demomote to 151 --------" <<RESET_COLOR<< std::endl;
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
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrate 151 --------" << RESET_COLOR<< std::endl;
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
    {   std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrate 0 --------" << RESET_COLOR<< std::endl;
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
