#include "Array.hpp"

// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ allocation avec et sans initialisation ,() forcent une initialisation par défaut.
// 		 ✩ new int(), alloue sur le tas (heap)
// 		 ✩ new int; alloue sur le tas (heap) et initialise pas
// 		            contiendra une valeur aléatoire
//
// 		 ✩  new int[n]; → Tableau non initialisé (valeurs aléatoires) ❌
// 		 ✩  new int[n](); → Tableau entièrement initialisé à 0 ✅
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

//=======================================================================================================
//										   Print							            				|
//=======================================================================================================

    template <typename T>
    void printArray(Array<T> &tab, std::string name, unsigned int index, bool change)
    {
        
        std::cout <<BLUE<< "Tableau "<<name << ": "<<RESET_COLOR;
        if (tab.size() == 0)
        {
            std::cout <<LIGHT_RED<< "Array is empty" <<RESET_COLOR<< std::endl;
        }
        else
        {
            for (unsigned int i = 0; i < tab.size(); i++)
            {
                if (index == i && change ==true)
                    std::cout << LIGHT_CYAN"["<< tab[i] << "] "<<RESET_COLOR;
                else
                std::cout <<"["<< tab[i] << "] ";
            }
            std::cout << std::endl;
        }
    }

//=======================================================================================================
//										   Main             											|
//=======================================================================================================

    int main() 
    {        
            std::cout <<MAGENTA<< "\n==================== Test 1 - no param, empty tab ====================" <<RESET_COLOR<< std::endl;
                Array<int>noParam;

                std::cout <<LIGHT_BLUE<< "Taille du tableau par 'size': " << noParam.size() <<RESET_COLOR<< std::endl;
                printArray(noParam,"noParam", 0, false);

            std::cout <<MAGENTA<< "\n==================== Test 2 - char - operator[]====================\n" <<RESET_COLOR<< std::endl;
                try
                {
                    Array<char>charArray(20);

                    std::cout <<LIGHT_BLUE<< "Taille du tableau par 'size': " << charArray.size() <<RESET_COLOR<< std::endl;
                    for (unsigned int i = 0; i < charArray.size(); i++)
                    {
                        charArray[i] = i + 65;
                    }
                    printArray(charArray, "charArray", 0, false);

                    charArray[7] = 'a';
                    std::cout << "\ncharArray[7] = " << charArray[7] << std::endl;
                    printArray(charArray, "charArray", 7, true);
                }
                catch (const std::out_of_range &e) 
                {
                    std::cerr <<LIGHT_RED<< "ERROR: " <<RESET_COLOR<< e.what() << std::endl;
                }

            std::cout <<MAGENTA<< "\n==================== Test 3 - int with 5 elements - operator[]out of bound ====================\n" <<RESET_COLOR<< std::endl;
        
                try 
                {
                    Array<int> numbersTab(5);

                    std::cout <<LIGHT_BLUE<< "Taille du tableau par 'size': " << numbersTab.size() <<RESET_COLOR<< std::endl;
                    for (unsigned int i = 0; i < numbersTab.size(); i++)
                    {
                        numbersTab[i] = i+3;
                    }
                    printArray(numbersTab, "numbersTab",0, false);
                    std::cout << "\nnumbersTab[6]= 42" << std::endl;
                    numbersTab[6] = 42;
                }
                catch (const std::out_of_range &e) 
                {
                    std::cerr <<LIGHT_RED<< "ERROR: " <<RESET_COLOR<< e.what() << std::endl;
                }

            std::cout <<MAGENTA<< "\n==================== Test 4 - float copy with 3 elements ====================\n" <<RESET_COLOR<< std::endl<<"(copying musn’t affect the other array)"<<ENDL<<ENDL;
                try
                { 
                    Array<float> numbersTab(3);
                    std::cout <<LIGHT_BLUE<< "Taille du tableau par 'size': " << numbersTab.size() <<RESET_COLOR<< std::endl;
                    for (unsigned int i = 0; i < numbersTab.size(); i++)
                    {
                        numbersTab[i] = i + 10.5;
                    }
                    Array<float> tabCopy = numbersTab;
                    printArray(numbersTab,"numbersTab", 0 , false);
                    printArray(tabCopy,"tabCopy   ", 0, false);
                    std::cout << ENDL;

                    std::cout <<  "Modification de Tabcopy"<< std::endl;
                    for (unsigned int i = 0; i < tabCopy.size(); i++)
                    {
                        tabCopy[i] = i + 2.7;
                    }
                    printArray(numbersTab, "numbersTab", 0, false);
                    printArray(tabCopy, "tabCopy\t    ", 0, false);
                    std::cout << ENDL;
                }
                catch (const std::out_of_range &e) 
                {
                    std::cerr <<LIGHT_RED<< "ERROR: " <<RESET_COLOR<< e.what() << std::endl;
                }
            std::cout <<MAGENTA<< "\n==================== Test 5 - double with 4 elements - operator[] ====================\n" <<RESET_COLOR<< std::endl;
                try 
                {
                    Array<double> numbersTab(8);
                    std::cout <<LIGHT_BLUE<< "Taille du tableau par 'size': " << numbersTab.size() <<RESET_COLOR<< std::endl;
                    for (unsigned int i = 0; i < numbersTab.size(); i++)
                    {
                        numbersTab[i] = i + 10.55;
                    }
                    printArray(numbersTab, "numbersTab", 0, false);
                    std::cout << "\nnumbersTab[5]= 42" << std::endl;
                    numbersTab[6] = 42;
                    printArray(numbersTab, "numbersTab", 6, true);
                }
                catch (const std::out_of_range &e) 
                {
                    std::cerr <<LIGHT_RED<< "ERROR: " <<RESET_COLOR<< e.what() << std::endl;
                }

        return 0;
    }
