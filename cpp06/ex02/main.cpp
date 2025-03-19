#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

#include <cstdlib>
#include <ctime> 

int main() 
{

    srand(time(0));// pour generate()
    std::cout <<LIGHT_TURCOI<< "\n\n============= Test 1 - generate, identidy(ptr), identify (ref) =============" <<RESET_COLOR<< std::endl;

    std::cout << BLUE<< "\n==== Test generate aleatoire() ====" << RESET_COLOR<< std::endl;
        Base* Tom = generate();
        Base* Jerry = generate();

    std::cout <<MAGENTA<< "\n==== Test identify ptr (Base* p) ====" <<RESET_COLOR<< std::endl;
        identify(Tom);
        identify(Jerry);

    std::cout <<LILAC<< "\n==== Test identify ref (Base& p) ====" <<RESET_COLOR<< std::endl;
        identify(*Tom);
        identify(*Jerry);

    std::cout << "\n==== Nettoyage de la mémoire ====\n";
        delete Tom;
        delete Jerry;


    std::cout <<LIGHT_TURCOI<< "\n\n============= Test 2 - creation direct d'un objet statique(ref) =============" <<RESET_COLOR<< std::endl;
       
        std::cout<<LIGHT_MAGENTA<< "\n== Base A ==" <<RESET_COLOR<< std::endl;
        A ananas;
        identify(ananas);

        std::cout<<LIGHT_MAGENTA<< "\n== Base B ==" <<RESET_COLOR<< std::endl;
        B banane;
        identify(banane); 

        std::cout<<LIGHT_MAGENTA<< "\n== Base C ==" <<RESET_COLOR<< std::endl;
        C chat; 
        identify(chat);


    std::cout <<LIGHT_BLUE<< "\n\n=============  Test 3 - direct avec un objet dynamique (Pointeur) =============" <<RESET_COLOR<< std::endl;

        std::cout<<LIGHT_MAGENTA<< "\n== Base A ==" <<RESET_COLOR<< std::endl;
        Base* p_ananas = new A;
        identify(p_ananas); // Appelle identify(Base*)

        std::cout<<LIGHT_MAGENTA<< "\n== Base B ==" <<RESET_COLOR<< std::endl;
        Base* p_banane = new B;
        identify(p_banane); // Appelle identify(Base*)

        std::cout<<LIGHT_MAGENTA<< "\n== Base C ==" <<RESET_COLOR<< std::endl;
        Base* p_chat = new C;
        identify(p_chat); // Appelle identify(Base*)

    std::cout << "\n==== Nettoyage de la mémoire ====\n\n";
        delete p_ananas;
        delete p_banane;
        delete p_chat;
    return 0;
}
