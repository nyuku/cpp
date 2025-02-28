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
   
        int value = 5;
        std::vector<int> numbers = {10, 20, 30, 40, 50};
        std::vector<int> vec = {10, 20, 30, 5, 40, 42, 50};
        std::list<int> lst = {1, 2, 3, 42, 5};
        std::deque<int> deq = {100, 200, 300, 42, 500};

        std::cout <<LILAC<< "\n==================== Test 1 - with vector ====================" <<RESET_COLOR<< std::endl;
            printContainer(numbers);
            std::cout << "To find: "<< value << std::endl;
            easyfind(numbers, value);

            printContainer(vec);
            std::cout << "To find: "<< value << std::endl;
            easyfind(vec, value);

        std::cout <<LILAC<< "\n==================== Test 2 - with list ====================" <<RESET_COLOR<< std::endl;
            printContainer(lst);
            value = 2;
            std::cout << "To find: "<< value << std::endl;
            easyfind(lst, value);

        std::cout <<LILAC<< "\n==================== Test 3 - with deque ====================" <<RESET_COLOR<< std::endl;
            printContainer(deq);
            value = 12;
            std::cout << "To find: "<< value << std::endl;
            easyfind(deq, value);
            std::cout << std::endl;
    return 0;
}