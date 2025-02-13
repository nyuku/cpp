#include "Array.hpp"

template <typename T>
void printArray(Array<T> &tab)
{
    std::cout << "Tableau : ";
    if (tab.size() == 0)
    {
        std::cout << "Array is empty" << std::endl;
    }
    else
    {
        for (unsigned int i = 0; i < tab.size(); i++)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
}



int main() 
{
    
        // std::cout <<MAGENTA<< "\n==================== Test with no param ====================" <<RESET_COLOR<< std::endl;
        //     Array<int>noParam;
        //     printArray(noParam);

        // std::cout <<MAGENTA<< "\n==================== Test with char ====================" <<RESET_COLOR<< std::endl;
        //     Array<char>charArray(20);

        // std::cout <<MAGENTA<< "\n==================== Test with float ====================" <<RESET_COLOR<< std::endl;
        // Array<float>floatArray(5);

        // std::cout <<MAGENTA<< "\n==================== Test with double ====================" <<RESET_COLOR<< std::endl;
        // Array<double>doubleArray(4);

        std::cout <<MAGENTA<< "\n==================== Test with int ====================" <<RESET_COLOR<< std::endl;
    
            try 
            {
                Array<int> numbersTab(5);
                for (unsigned int i = 0; i < numbersTab.size(); i++)
                {
                    numbersTab[i] = i;
                }
                printArray(numbersTab);
            }
            catch (const Array<int>::outOfBoundsException &e) 
            {
                std::cerr << "Exception attrapée : " << e.what() << std::endl;
            }

            std::cout <<MAGENTA<< "\n==================== Test with copy ====================" <<RESET_COLOR<< std::endl;
              try
              { 
                 Array<int> numbersTab(5);
                Array<int> tabCopy = numbersTab;
                //tabCopy[0] = 999;
                std::cout << "Après modification de copy[0], numbersTab[0] = " << numbersTab[0] << std::endl;
                printArray(tabCopy);
                printArray(numbersTab);
                std::cout << "Accès à un index hors limites : " << numbersTab[10] << std::endl;
            }
            catch (const Array<int>::outOfBoundsException &e) 
            {
                std::cerr << "Exception attrapée : " << e.what() << std::endl;
            }

    return 0;
}
