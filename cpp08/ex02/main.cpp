#include "MutantStack.hpp"


int main()
{
   
    std::cout <<LIGHT_BLUE<< "\n==================== Test 1 - iterator ====================" <<RESET_COLOR<< std::endl;
        MutantStack<int> mstack;//Création d'une pile vide de type int.
        std::cout<<LIGHT_GREEN<<"Push: 5, 7 "<< RESET_COLOR<< ENDL;;
        mstack.push(5);
        mstack.push(17);

        std::cout <<LIGHT_CYAN<< "Dernière rentrée [top]: "<< RESET_COLOR << mstack.top() << std::endl;

        std::cout <<LIGHT_RED<< "Retrait du dernier [pop]: "<< RESET_COLOR<< mstack.top()<< ENDL;
        mstack.pop();

        std::cout <<LIGHT_CYAN<< "Taille de la stack: "<< RESET_COLOR <<mstack.size() << std::endl; // 1

        std::cout<<LIGHT_GREEN<<"Push: 3, 5, 737, 0"<< RESET_COLOR<< ENDL;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0); // haut de la pile

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        std::cout <<LIGHT_CYAN<< "Affichage de Stack par iterator " << RESET_COLOR<<"[ " ;
        while (it != ite)
        {
            
            MutantStack<int>::iterator next = it;
            ++next;// on decale de 1, avant la fin
            std::cout << *it ;
            if (next != ite)
                std::cout << ", ";
            ++it;
        }
        std::cout << " ]" << std::endl << std::endl;

    std::cout <<LIGHT_BLUE<< "\n==================== Test 2 - cop constructor stack ====================" <<RESET_COLOR<< std::endl;
        std::stack<int> s(mstack); // copie de constructeur stacak Vérifie que la copie fonctionne
        //[ 5, 3, 5, 737, 0 ]
        
        std::cout <<LIGHT_CYAN<< "Dernière rentrée [top]: "<< RESET_COLOR <<s.top() << std::endl;  // Affiche 3
        std::cout <<LIGHT_RED<< "Retrait du dernier [pop]: "<< RESET_COLOR<< s.top()<< ENDL;
        s.pop();
        std::cout <<LIGHT_CYAN<< "Dernière rentrée [top]: "<< RESET_COLOR << s.top() << std::endl;  // Affiche 2

    return 0;
}
