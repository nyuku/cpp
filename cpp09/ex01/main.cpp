#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        std::cerr <<LIGHT_RED<< "Error: please add calculus in RPN style between double quote  '2 2 +'" <<RESET_COLOR<< std::endl;
        return (1);
    }
    RPN rpn;
    int result = 0;
    if (rpn.reversePolishNotation(argv[1],result))
    {  
        int firstpadding = (std::strlen(argv[1]) / 2);
        std::cout <<LIGHT_CYAN <<std::string(firstpadding, '=');
        std::cout << "[RPN]";

        // int padding = std::strlen(argv[1]) ;
        std::cout << std::string(firstpadding, '=');
        std::cout << std::string(9, '=');
        std::cout<<"[RESULT]=============" <<RESET_COLOR<< std::endl;
        std::cout<<" \""<< argv[1]<<"\"";
        std::cout<< "\t\t"<<result << std::endl;
        return 0;
    }
    return 0;
}