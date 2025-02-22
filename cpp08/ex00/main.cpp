// Deque:
        // Application pour deque -> rotation (sur une liste d'éléments de données).
        // Sens des aiguilles d'une montre : retirer élément de l'arrière et l'insérer à l'avant.

#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void printContainer(T &container)
{
    std::cout <<LIGHT_BLUE<< "Container: " <<RESET_COLOR;
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
   
        std::vector<int> v;
        std::list<int> l;
        std::deque<int> d;
        int value = 5;

        for (int i = 0; i < 10; i++)
        {
            v.push_back(i);
            l.push_back(i);
            d.push_back(i);
        }
        std::cout <<LILAC<< "\n==================== Test 1 - with vector ====================" <<RESET_COLOR<< std::endl;
            printContainer(v);
            std::cout << "To find: "<< value << std::endl;
            easyfind(v, value);

        std::cout <<LILAC<< "\n==================== Test 2 - with list ====================" <<RESET_COLOR<< std::endl;
            printContainer(l);
            value = 2;
            std::cout << "To find: "<< value << std::endl;
            easyfind(l, value);

        std::cout <<LILAC<< "\n==================== Test 3 - with deque ====================" <<RESET_COLOR<< std::endl;
            printContainer(d);
            value = 12;
            std::cout << "To find: "<< value << std::endl;
            easyfind(d, value);
            std::cout << std::endl;
    return 0;
}