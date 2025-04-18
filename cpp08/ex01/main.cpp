#include "Span.hpp"



int main()
{
    std::cout <<LIGHT_BLUE<< "\n==================== Test 1 - addnumber, return shortest and longest ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(5);
            alpha.addNumber(1);
            alpha.addNumber(5);
            alpha.addNumber(12);
            alpha.addNumber(100);
            alpha.addNumber(15);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    std::cout <<LIGHT_BLUE<< "\n==================== Test 2 - addnumber, return exception ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(5);
            alpha.addNumber(1);
            alpha.addNumber(5);
            alpha.addNumber(12);
            alpha.addNumber(100);
            alpha.addNumber(15);
            alpha.addNumber(20);
            alpha.addNumber(25);
            alpha.addNumber(30);
            alpha.addNumber(35);
            alpha.addNumber(40);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    std::cout <<LIGHT_BLUE<< "\n==================== Test 3 - addnumber + fillContainer(override), return shortest and longuest ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(50);
            alpha.addNumber(1);
            alpha.addNumber(2);
            alpha.addNumber(3);
            alpha.addNumber(4);
            alpha.addNumber(5);
            alpha.fillContainer(alpha.getContainerBegin(), alpha.getContainerEnd(), true);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    std::cout <<LIGHT_BLUE<< "\n==================== Test 3.2 - addnumber+ fillContainer, return exception ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(50);
            alpha.addNumber(1);
            alpha.addNumber(5);
            alpha.addNumber(12);
            alpha.addNumber(100);
            alpha.addNumber(15);
            alpha.fillContainer(alpha.getContainerBegin(), alpha.getContainerEnd(), false);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    std::cout <<LIGHT_BLUE<< "\n==================== Test 4 - fillContainer + addnumber, return exception ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(5);
            alpha.fillContainer(alpha.getContainerBegin(), alpha.getContainerEnd(), true);
            alpha.addNumber(1);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    std::cout <<LIGHT_BLUE<< "\n==================== Test 5 - container size to small ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(1);
            alpha.addNumber(1);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    std::cout <<LIGHT_BLUE<< "\n==================== Test 6 - addnumber with negativ entries ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(7);
            alpha.addNumber(-1);
            alpha.addNumber(-5);
            alpha.addNumber(-12);
            alpha.addNumber(-100);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    

    std::cout <<LIGHT_BLUE<< "\n==================== Test 7 - Big Span + fillcontainer, return shortest and longest ====================" <<RESET_COLOR<< std::endl;
        try
        {
            Span alpha(100);
            alpha.fillContainer(alpha.getContainerBegin(), alpha.getContainerEnd(), true);
            std::cout << "Container alpha: ";
            alpha.printContainer();
            std::cout <<LIGHT_CYAN<< "Shortest Span: \t "<<RESET_COLOR;
            alpha.shortestSpan();
            std::cout <<LIGHT_CYAN<< "Longest Span:  \t "<< RESET_COLOR;
            alpha.longestSpan();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
   
}
