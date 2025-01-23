#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test ShrubberyCreationForm[sign:✅ exec:✅] --------" << RESET_COLOR<< std::endl;
        try
        {
                    Bureaucrat Link("Link",50);
					Bureaucrat Zelda("Zelda",120);

					ShrubberyCreationForm swordform("sword"); 
                    std::cout << swordform << std::endl;

                    Link.signForm(sword);
					std::cout << swordform << std::endl;

					Zelda.execute(sowrd);
                    std::cout << swordform << std::endl;
        }
        catch (Form::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Form::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
            std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test ShrubberyCreationForm[sign:✅ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Link("Link",50);
			Bureaucrat Zelda("Zelda",150);

			ShrubberyCreationForm swordform("sword"); 
			std::cout << swordform << std::endl;

			Link.signForm(sword);
			std::cout << swordform << std::endl;

			Zelda.execute(sowrd);
			std::cout << swordform << std::endl;
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
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test ShrubberyCreationForm[sign:❌ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Link("Link",150);
			Bureaucrat Zelda("Zelda",150);

			ShrubberyCreationForm swordform("sword"); 
			std::cout << swordform << std::endl;

			Link.signForm(sword);
			std::cout << swordform << std::endl;

			Zelda.execute(sowrd);
			std::cout << swordform << std::endl;
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

    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test 1 RobotomyRequestForm[sign:✅ exec:?] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke("Luke",15);
			Bureaucrat Vader("Vader",1);

			ShrubberyCreationForm deathStar("deathStar"); 
			std::cout << deathStar << std::endl;

			Link.signForm(deathStar);
			std::cout << deathStar << std::endl;

			Zelda.execute(deathStar);
			std::cout << deathStar << std::endl;
        }
        catch (Form::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Form::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test 2 RobotomyRequestForm[sign:❌ exec:?] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke("Luke",150);
			Bureaucrat Vader("Vader",150);

			ShrubberyCreationForm deathStar("deathStar"); 
			std::cout << deathStar << std::endl;

			Link.signForm(deathStar);
			std::cout << deathStar << std::endl;

			Zelda.execute(deathStar);
			std::cout << deathStar << std::endl;
        }
        catch (Form::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Form::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test 1 RobotomyRequestForm[sign:❌ exec:?] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke("Luke", 80);
			Bureaucrat Vader("Vader",1);

			ShrubberyCreationForm deathStar("deathStar"); 
			std::cout << deathStar << std::endl;

			Link.signForm(deathStar);
			std::cout << deathStar << std::endl;

			Zelda.execute(deathStar);
			std::cout << deathStar << std::endl;
        }
        catch (Form::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Form::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {   std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrate 70- Form to sign 150 --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Stagiaire(149, "Stagiaire");
            Form	    form("Devil_contract", 150, 20);
            Stagiaire.signForm(form);
            std::cout << form << std::endl;

        }
        catch (Form::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (Form::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
            std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
}
