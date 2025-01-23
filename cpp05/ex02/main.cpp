#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// int	main()
// {
//     {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test simple form : constructor, operator, standard --------" << RESET_COLOR<< std::endl;
//         try
//         {
//                 //Constructeur standard
//                     Form page0; 
//                     std::cout << page0 << std::endl;

//                     Form page1 ("page1", 10, 5);
//                     std::cout << page1 << std::endl;
//                 //Constructeur par copie
//                     Form page2 (page1);
//                     std::cout << page2 << std::endl;

//                 //test operateur d'affectation 
//                     page1 = page0;
//                     std::cout	<< page2 << std::endl;
//                 // grade trop grand
//                 std::cout <<ENDL<<LIGHTPURPLE<< "-------- Form, grade to sign to high --------" << RESET_COLOR<< std::endl;
//                     Form page_high ("page_high", 0, 5);
//         }
//         catch (Form::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Form::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//             std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// //-------------------------------------------------------------------------------------------------------------------------------------//
//     {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Form, grade to sign too low --------" <<RESET_COLOR<< std::endl;
//         try
//         {
//             Form page_low ("page_low", 200, 5);
//         }
//         catch (Bureaucrat::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Bureaucrat::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//                 std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// //-------------------------------------------------------------------------------------------------------------------------------------//
//     {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Form, grade to exec too low --------" <<RESET_COLOR<< std::endl;
//         try
//         {
//             Form page_low ("page_low", 5, 200);
//         }
//         catch (Bureaucrat::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Bureaucrat::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//                 std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// //-------------------------------------------------------------------------------------------------------------------------------------//
//     {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Form, grade to exec too high --------" <<RESET_COLOR<< std::endl;
//         try
//         {
//             Form page_high ("page_low", 5, 0);
//         }
//         catch (Bureaucrat::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Bureaucrat::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//                 std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// //-------------------------------------------------------------------------------------------------------------------------------------//

//     {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrat 11 - Form to sign 10 --------" <<RESET_COLOR<< std::endl;
//         try
//         {
//             Bureaucrat  Sedusa(11, "Sedusa");
//             Form	    form("Devil_contract", 10, 20);
//             std::cout	<< form << std::endl;
//             Sedusa.signForm(form);

//         }
//         catch (Form::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Form::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//                 std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// //-------------------------------------------------------------------------------------------------------------------------------------//
//     {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrat 5 - Form to sign 5 --------" << RESET_COLOR<< std::endl;
//         try
//         {
//             Bureaucrat  Archangel(5, "Archangel");
//             Form	    form("Devil_contract", 5, 20);
//             Archangel.signForm(form);
//             std::cout << form << std::endl;
//         }
//         catch (Form::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Form::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//             std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// //-------------------------------------------------------------------------------------------------------------------------------------//
//     {   std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test Bureaucrate 70- Form to sign 150 --------" << RESET_COLOR<< std::endl;
//         try
//         {
//             Bureaucrat Stagiaire(149, "Stagiaire");
//             Form	    form("Devil_contract", 150, 20);
//             Stagiaire.signForm(form);
//             std::cout << form << std::endl;

//         }
//         catch (Form::GradeTooHighException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (Form::GradeTooLowException &excep)
//         {
//             std::cout	<< excep.what() << std::endl;
//         }
//         catch (std::exception& excep)
//         {
//             std::cerr << "An exception occurred: "<< excep.what() << std::endl;
//         }
//     }
// }

int	main()
{
	{
		std::cout	<< "-------- This form can be signed but not executed, so shouldn\'t --------" << std::endl;

		Bureaucrat				dude("Julien", 145);
		std::cout	<< dude << std::endl;

		ShrubberyCreationForm	form("garden");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;

	{
		std::cout	<< "-------- This form cannot be signed, nor executed --------" << std::endl;

		Bureaucrat				dude("Julien", 150);
		std::cout	<< dude << std::endl;

		ShrubberyCreationForm	form("garden");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form can be signed and executed. It produces a file with a pine tree --------" << std::endl;

		Bureaucrat				dude("Julien", 1);
		std::cout	<< dude << std::endl;

		ShrubberyCreationForm	form("garden");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form can be signed and executed. Robotomy is successful (even number) --------" << std::endl;

		Bureaucrat				dude("Julien", 1);
		std::cout	<< dude << std::endl;

		RobotomyRequestForm		form("Cyberman");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form can be signed and executed. Robotomy is a failure (odd number) --------" << std::endl;

		Bureaucrat				dude("Julien", 1);
		std::cout	<< dude << std::endl;

		RobotomyRequestForm		form("Cyberno");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form cannot be signed, nor executed --------" << std::endl;

		Bureaucrat				dude("Julien", 100);
		std::cout	<< dude << std::endl;

		RobotomyRequestForm		form("Cyberno");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form can be signed but not executed, so shouldn\'t  --------" << std::endl;

		Bureaucrat				dude("Julien", 72);
		std::cout	<< dude << std::endl;

		RobotomyRequestForm		form("Cyberno");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form can be signed but not executed, so shouldn\'t --------" << std::endl;

		Bureaucrat				dude("Julien", 25);
		std::cout	<< dude << std::endl;

		PresidentialPardonForm	form("Arthur");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form cannot be signed, nor executed --------" << std::endl;

		Bureaucrat				dude("Julien", 150);
		std::cout	<< dude << std::endl;

		PresidentialPardonForm	form("Arthur");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
		std::cout << std::endl;
	{
		std::cout	<< "-------- This form can be signed and executed. Kudos. --------" << std::endl;

		Bureaucrat				dude("Julien", 1);
		std::cout	<< dude << std::endl;

		PresidentialPardonForm	form("Arthur");
		std::cout	<< form << std::endl;

		dude.signForm(form);
		dude.executeForm(form);
	}
