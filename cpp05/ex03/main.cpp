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
#include "Intern.hpp"

int	main()
{
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 1 ShrubberyCreationForm[sign:✅ exec:✅] --------" << RESET_COLOR<< std::endl;
        try
        {
                    Bureaucrat  Link(50,"Link");
					Bureaucrat  Zelda(120,"Zelda");
                    Intern	    someRandomIntern;

					AForm* rrf;
                    rrf = someRandomIntern.makeForm("shrubbery creation", "Fist_Task");
                    std::cout << *rrf << std::endl;

                    Link.signForm(*rrf);
					std::cout << *rrf << std::endl;

					Zelda.executeForm(*rrf);
                     if (rrf) 
                         delete rrf;
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
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 2 ShrubberyCreationForm[sign:✅ exec:❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Link(50,"Link");
            Bureaucrat Zelda(150,"Zelda");
            Intern	    someRandomIntern;

            AForm* rrf;
            rrf = someRandomIntern.makeForm("shrubbery creation", "Fist_Task");
            std::cout << *rrf << std::endl;

			Link.signForm(*rrf);
			std::cout << *rrf<< std::endl;

			Zelda.executeForm(*rrf);
            if (rrf) 
                delete rrf;
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

    {std::cout	<<ENDL<<LIGHT_BLUE<< "-------- Test 3 RobotomyRequestForm[sign:✅ exec:✅+?] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Luke(15,"Luke");
			Bureaucrat R2d2(1,"R2d2");

			Intern	    someRandomIntern;

            AForm* deathStar;
            deathStar = someRandomIntern.makeForm("robotomy request", "DeathStar");
			std::cout << *deathStar << std::endl;

			Luke.signForm(*deathStar);
			std::cout << *deathStar << std::endl;

			R2d2.executeForm(*deathStar);
            if (deathStar) 
                delete deathStar;
           
		
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
    {std::cout	<<ENDL<<LIGHT_TURCOI<< "-------- Test 4 PresidentialPardonForm [sign:✅ exec:✅] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Hokage(1,"Hashirama");
			Bureaucrat Sarutobi(2,"Sarutobi");
            Intern	    someRandomIntern;

            AForm* Alliance;
            Alliance = someRandomIntern.makeForm("presidential pardon", "Alliance");
			std::cout << *Alliance << std::endl;

			Hokage.signForm(*Alliance);
       
			std::cout << *Alliance << std::endl;

			Sarutobi.executeForm(*Alliance);
            if (Alliance)
                delete Alliance;

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
    {std::cout	<<ENDL<<LIGHT_TURCOI<< "-------- Test 5 Random Form no protocol[❌] --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Hokage(1,"Hashirama");
			Bureaucrat Sarutobi(2,"Sarutobi");
            Intern	    someRandomIntern;

            AForm* Exam = NULL;
            Exam = someRandomIntern.makeForm("Chunnin_exam", "Exam");
			std::cout << *Exam << std::endl;

			Hokage.signForm(*Exam);
       
			std::cout << *Exam << std::endl;

			Sarutobi.executeForm(*Exam);

            if (Exam)
             delete Exam;

        }
        
        catch (AForm::GradeTooHighException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (AForm::GradeTooLowException &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch(AForm::InvalidNameForm &excep)
        {
            std::cout	<< excep.what() << std::endl;
        }
        catch (std::exception& excep)
        {
                std::cerr << "An exception occurred: "<< excep.what() << std::endl;
        }
    
    }

return(0);
}
