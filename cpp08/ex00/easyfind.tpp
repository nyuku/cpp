#include "easyfind.hpp"

// ╔───────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────╗
// 		 Template fonction sur container d'entier
//
//       Retour: false-> Element not found! et retourne un itérateur vers la fin
//       Option: lancer exeption
//         
// ╚───────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────╝

//=======================================================================================================
//										   Easyfind				    	    							|
//=======================================================================================================

    template <typename T>
    typename T::iterator easyfind(T &container, int toFind)
    {
        typename T::iterator it = std::find(container.begin(), container.end(), toFind);
        if (it == container.end()) 
        {
            std::cout <<LIGHT_RED<< "Element not found!" <<RESET_COLOR<< std::endl;
            return container.end(); // Retourne un itérateur vers la fin
        }
        std::cout << "Found: " << *it << std::endl;
        return it; // Retourne l'itérateur où l'élément a été trouvé
    }
