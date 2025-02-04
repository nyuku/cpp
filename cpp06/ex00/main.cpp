#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 )
    {
        std::cout<<LIGHT_RED<<"ERROR: need just one argument\n"<< RESET_COLOR<<std::endl;
        return(1);
    }
    else
    {
        ScalarConverter cast(argv[1]); // cree la classe 
        cast.detectType(argv[1]);
        cast.selectType(argv[1]);
        cast.printAll();



    }
}