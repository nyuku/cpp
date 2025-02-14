#include "Bureaucrat.hpp"


int	main()
{
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 1 simple form : constructor, operator, standard --------" << RESET_COLOR<< std::endl;
        try
        {
                //Constructeur standard
                    std::cout << "Standard constructor:" << std::endl;
                    Form page0; 
                    std::cout << page0 << std::endl;

                    std::cout << "Constructor with param:" << std::endl;
                    Form page1 ("page1", 10, 5);
                    std::cout << page1 << std::endl;
                //Constructeur par copie
                    std::cout << "Copy constructor:" << std::endl;
                    Form page2 (page1);
                    std::cout << page2 << std::endl;

                //test operateur d'affectation 
                    std::cout << "Operator = basic:" << std::endl;
                    page1 = page0;
                    std::cout	<< page2 << std::endl;
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

    { std::cout <<ENDL<<LIGHTPURPLE<< "-------- Test 2 Form, grade to sign to high --------" << RESET_COLOR<< std::endl;
        try
        {            
            Form page_high ("page_high", 0, 5);
            std::cout << page_high << std::endl;
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
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test 3 Form, grade to sign too low --------" <<RESET_COLOR<< std::endl;
        try
        {
            Form page_low ("page_low", 200, 5);
            std::cout << page_low << std::endl;
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
                std::cerr << "An exception occurreddd: "<< excep.what() << std::endl;
        }
    }
//-------------------------------------------------------------------------------------------------------------------------------------//
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test 4 Form, grade to exec too low --------" <<RESET_COLOR<< std::endl;
        try
        {
            Form page_low ("page_low", 5, 200);
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
    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test 5 Form, grade to exec too high --------" <<RESET_COLOR<< std::endl;
        try
        {
            Form page_high ("page_low", 5, 0);
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

    {std::cout  <<ENDL<<LIGHTPURPLE<< "-------- Test 6 Bureaucrat 11 - Form to sign 10, could'nt sign --------" <<RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat  Sedusa(11, "Sedusa");
            Form	    form("contract", 10, 20);
            std::cout	<< form << std::endl;
            Sedusa.signForm(form);

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
    {std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 7 Bureaucrat 5 - Form to sign 5, signed --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat  Archangel(5, "Archangel");
            Form	    form("contract", 5, 20);
            Archangel.signForm(form);
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
//-------------------------------------------------------------------------------------------------------------------------------------//
    {   std::cout	<<ENDL<<LIGHTPURPLE<< "-------- Test 8 Bureaucrate 70- Form to sign 150, signed --------" << RESET_COLOR<< std::endl;
        try
        {
            Bureaucrat Stagiaire(149, "Stagiaire");
            Form	    form("contract", 150, 20);
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
