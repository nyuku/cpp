#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // ScalarConverter cast(argv[1]); // cree la classe si instanciable
    if (argc != 2 )
    {
        std::cout<<LIGHT_RED<<"ERROR: need just one argument: Char, int, Float or Double\n"<< RESET_COLOR<<std::endl;
        return(1);
    }
    else
    {
        ScalarConverter::convert(argv[1]);
        //std::cout << "float test: " << static_cast<float>(strtod(argv[1], NULL));
    }
}