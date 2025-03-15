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
    
    // Initialisation des conteneurs 
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(5);
    vec.push_back(40);
    vec.push_back(42);
    vec.push_back(50);
    
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(42);
    lst.push_back(5);
    
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(42);
    deq.push_back(500);

    std::cout << "\n==================== Test 1 - with vector ====================" << std::endl;
    std::cout <<LIGHT_BLUE<< "1." << RESET_COLOR;
    printContainer(numbers);
    std::cout << "To find: " << value << std::endl;
    easyfind(numbers, value);

    std::cout <<LIGHT_BLUE<< "\n2." << RESET_COLOR;
    printContainer(vec);
    std::cout << "To find: " << value << std::endl;
    easyfind(vec, value);

    std::cout << "\n==================== Test 2 - with list ====================" << std::endl;
    std::cout <<LIGHT_BLUE<< "3." << RESET_COLOR;
    printContainer(lst);
    value = 2;
    std::cout << "To find: " << value << std::endl;
    easyfind(lst, value);
    std::cout << std::endl;

    value = 7;
    std::cout << "To find: " << value << std::endl;
    easyfind(lst, value);

    std::cout << "\n==================== Test 3 - with deque ====================" << std::endl;
    std::cout <<LIGHT_BLUE<< "4." << RESET_COLOR;
    printContainer(deq);
    value = 12;
    std::cout << "To find: " << value << std::endl;
    easyfind(deq, value);
    std::cout << std::endl;

    value = 100;
    std::cout << "To find: " << value << std::endl;
    easyfind(deq, value);
    std::cout << std::endl;

    return 0;
}