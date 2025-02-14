// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		CommandeS 
// 		 ✩ ! execute vs exceuteForm
//       ✩ ! signForm vs beSigned
//       ✩ 3 lv de classes: Bureaucrate qui fait les actions
//                          AForm qui subit les actions
//                          3 classes enfants de AForm qui ont les memes actions
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 1 ShrubberyCreationForm[sign:✅ exec:✅] --------" << RESET_COLOR<< std::endl;
        try
        {
                    Bureaucrat Link(50,"Link");
					Bureaucrat Zelda(120,"Zelda");

					ShrubberyCreationForm swordform("sword"); 
                    std::cout << swordform << std::endl;

                    Link.signForm(swordform);
					std::cout << swordform << std::endl;

					Zelda.executeForm(swordform);
                    std::cout<<"\n";
        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
            std::cout<<"\n";
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
            std::cout<<"\n";
        }
        catch (std::exception& excep)
        {
            std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 2 ShrubberyCreationForm[sign:✅ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Link(50,"Link");
            Bureaucrat Zelda(150,"Zelda");

			ShrubberyCreationForm swordform("sword"); 
			std::cout << swordform << std::endl;

			Link.signForm(swordform);
			std::cout << swordform << std::endl;

			Zelda.executeForm(swordform);
        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 3 ShrubberyCreationForm[sign:❌ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Link(150,"Link");
            Bureaucrat Zelda(15,"Zelda");

			ShrubberyCreationForm swordform("sword"); 
			std::cout << swordform << std::endl;

			Link.signForm(swordform);
			std::cout << swordform << std::endl;

			Zelda.executeForm(swordform);

        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//

    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test 1 RobotomyRequestForm[sign:✅ exec:✅+?] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke(15,"Luke");
			Bureaucrat R2d2(1,"R2d2");

			RobotomyRequestForm deathStar("deathStar"); 
			std::cout << deathStar << std::endl;

			Luke.signForm(deathStar);
			std::cout << deathStar << std::endl;

			R2d2.executeForm(deathStar);
		
        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test  2 RobotomyRequestForm[sign:✅ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke(70,"Luke");
			Bureaucrat R2d2(50,"R2d2");

			RobotomyRequestForm deathStar("deathStar"); 
			std::cout << deathStar << std::endl;

			Luke.signForm(deathStar);
			std::cout << deathStar << std::endl;

			R2d2.executeForm(deathStar);
	
        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test 3 RobotomyRequestForm[sign:❌ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke(150,"Luke");
			Bureaucrat R2d2(150,"R2d2");

			RobotomyRequestForm deathStar("deathStar"); 
			std::cout << deathStar << std::endl;

			Luke.signForm(deathStar);
			std::cout << deathStar << std::endl;

			R2d2.executeForm(deathStar);

        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHT_TURCOI<< "-------- Test 1 PresidentialPardonForm [sign:✅ exec:✅] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Hokage(1,"Hashirama");
			Bureaucrat Sarutobi(2,"Sarutobi");

			PresidentialPardonForm Alliance("Alliance"); 
			std::cout << Alliance << std::endl;

			Hokage.signForm(Alliance);
			std::cout << Alliance << std::endl;

			Sarutobi.executeForm(Alliance);

        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout	<<ENDL<<LIGHT_TURCOI<< "-------- Test  2 PresidentialPardonForm [sign:❌ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Hokage(150,"Tsunade");
			Bureaucrat Orochimaru(150,"Orochimaru");

			PresidentialPardonForm Alliance("Alliance"); 
			std::cout << Alliance << std::endl;

			Hokage.signForm(Alliance);
			std::cout << Alliance << std::endl;

			Orochimaru.executeForm(Alliance);
		
        }
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    }



}
