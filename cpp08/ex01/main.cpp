#include "Span.hpp"



int main()
{
    std::cout <<LIGHT_BLUE<< "\n==================== Test 1 - return shortest and longest ====================" <<RESET_COLOR<< std::endl;
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
    std::cout <<LIGHT_BLUE<< "\n==================== Test 2 - return exception ====================" <<RESET_COLOR<< std::endl;
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
    std::cout <<LIGHT_BLUE<< "\n==================== Test 3 - fillContainer with vector ====================" <<RESET_COLOR<< std::endl;
    try
    {
        Span alpha(50);
        alpha.addNumber(1);
        alpha.addNumber(5);
        alpha.addNumber(12);
        alpha.addNumber(100);
        alpha.addNumber(15);
        alpha.fillContainer(alpha.getContainerBegin(), alpha.getContainerEnd());
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
