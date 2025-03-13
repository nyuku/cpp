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

        //faut un chiffre treeeeees grand +17 chiffre
    //        double result = strtod(argv[1], nullptr);

    // // Vérification de la limite de double
    // if (result == std::numeric_limits<double>::infinity()) {
    //     std::cout << "double test: +inf" << std::endl;
    // } else if (result == -std::numeric_limits<double>::infinity()) {
    //     std::cout << "double test: -inf" << std::endl;
    // } else if (result > std::numeric_limits<double>::max()) {
    //     std::cout << "double test: +inf (overflow)" << std::endl;
    // } else if (result < -std::numeric_limits<double>::max()) {
    //     std::cout << "double test: -inf (overflow)" << std::endl;
    // } else {
    //     std::cout << "double test: " << result << std::endl;
    // }

        ScalarConverter::convert(argv[1]);
        //std::cout << "float test: " << static_cast<float>(strtod(argv[1], NULL));
    }
}