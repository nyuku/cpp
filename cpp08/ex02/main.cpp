
// ╔────────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────────╗
//      Le but de l’exercice : 
//          créer une classe MutantStack(Stack) en y ajoutant la possibilité d’itérer sur ses éléments (begin()/end())

//      ->std::stack ne fournit pas d’itérateurs
//      ->on va chercher et expose les itérateurs du conteneur sous-jacent Deque
// ╚────────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────────╝
#include "MutantStack.hpp"


int main()
{
   
    std::cout <<LIGHT_BLUE<< "\n==================== Test 1 - iterator ====================" <<RESET_COLOR<< std::endl;
        MutantStack<int> mstack;//Création d'une pile vide de type int.
        std::cout<<LIGHT_GREEN<<"Push: 5, 17 "<< RESET_COLOR<< ENDL;;
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

    std::cout <<LIGHT_BLUE<< "\n==================== Test 2 - copy constructor, on normal stack ====================" <<RESET_COLOR<< std::endl;
        std::stack<int> s(mstack);
        
        std::cout <<LIGHT_CYAN<< "Dernière rentrée [top]: "<< RESET_COLOR <<s.top() << std::endl;  
        std::cout <<LIGHT_RED<< "Retrait du dernier [pop]: "<< RESET_COLOR<< s.top()<< ENDL;
        s.pop();
        std::cout <<LIGHT_CYAN<< "Dernière rentrée [top]: "<< RESET_COLOR << s.top() << std::endl;  

        // std::stack<int>::iterator it = s.begin();
        // std::stack<int>::iterator ite = s.end();
        // while (it != ite) {
        //     std::cout << *it << std::endl;
        //     ++it;
        //}
   
    std::cout <<LIGHT_BLUE<< "\n==================== Test 3 - change stack to list ====================" <<RESET_COLOR<< std::endl;
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(0);
        std::cout <<LIGHT_CYAN<< "Affichage de List par iterator " << RESET_COLOR;
        std::cout << "List [ ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
            std::cout << *it << " ";
        std::cout << "]" << std::endl;

        // std::cout <<LIGHT_BLUE<< "\n==================== Test 4 - normal stack has no iterator ====================" <<RESET_COLOR<< std::endl;
    
        // std::stack<int> s;
        // s.push(1);
        // s.push(2);
        // s.push(3);

        // std::stack<int>::iterator it = s.begin(); // ❌ 
        
    return 0;
}
