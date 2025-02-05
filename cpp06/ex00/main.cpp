#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // ScalarConverter cast(argv[1]); // cree la classe si instanciable
    if (argc != 2 )
    {
        std::cout<<LIGHT_RED<<"ERROR: need just one argument\n"<< RESET_COLOR<<std::endl;
        return(1);
    }
    else
    {
        ScalarConverter::convert(argv[1]);
    }
}