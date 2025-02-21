#include "whatever.hpp"
#include <iostream>


int main() 
{
    
    std::cout <<MAGENTA<< "\n==================== Test with int ====================" <<RESET_COLOR<< std::endl;
        int a = 2, b = 3;

        std::cout << "a = " << a << ", b = " << b << ENDL<<std::endl;
        swap(a, b);
        std::cout << "swap (a, b) \t\ta = " << a << ", b = " << b << std::endl;

        std::cout << "min(a, b) = \t\t" << min(a, b) << std::endl;
        std::cout << "max(a, b) = \t\t" << max(a, b) << std::endl;

    std::cout <<MAGENTA<< "\n==================== Test with double ====================" <<RESET_COLOR<< std::endl;
        double x = 3.5, y = 2.1;

        std::cout << "x = " << x << ", y = " << y << ENDL<<std::endl;
        std::cout << "min(3.5, 2.1) = \t" << min(x, y) << std::endl;
        std::cout << "max(3.5, 2.1) = \t" << max(x, y) << std::endl;

    std::cout <<MAGENTA<< "\n==================== Test with string ====================" <<RESET_COLOR<< std::endl;
        std::string s1 = "chocolat";
        std::string s2 = "chat";

        std::cout << "s1 = " << s1 << ", s2 = " << s2 << ENDL<<std::endl;
        swap(s1, s2);
        std::cout << "swap (s1, s2) \t\ts1 = " << s1 << ", s2 = " << s2 << std::endl;

        std::cout << "min(s1, s2) = \t\t" << ::min(s1, s2) << std::endl;
        std::cout << "max(s1, s2) = \t\t" << ::max(s1, s2) << std::endl;

        std::cout <<MAGENTA<< "\n==================== Test with int a = b, return the 2nd ====================" <<RESET_COLOR<< std::endl;
        a = 5, b = 5;

        std::cout << "a = " << a << ", b = " << b <<std::endl;
        std::cout <<"&a = " << LIGHT_CYAN<< &a <<RESET_COLOR<<  ", &b = " << BLUE<< &b <<RESET_COLOR<< ENDL<<std::endl;
        const int &minResult = min(a, b);
        const int &maxResult = max(a, b);

        std::cout << "min(a, b) = \t\t" << min(a, b) <<" (" <<BLUE<< &minResult << RESET_COLOR <<")"<< std::endl;
        std::cout << "max(a, b) = \t\t" << max(a, b) <<" (" << BLUE<<&maxResult << RESET_COLOR <<")"<<ENDL<< std::endl;
        
        return 0;
}







//-----Main d'exo
// int main( void ) 
// {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return 0;
// }

//output:
// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2