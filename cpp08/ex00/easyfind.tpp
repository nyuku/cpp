#include "easyfind.hpp"

//Si l'entier est trouvé dans le container, la fonction doit renvoyer un itérateur pointant sur l'élément trouvé. Si l'entier n'est pas trouvé, tu devras renvoyer un itérateur vers la fin du container (container.end()).

//=======================================================================================================
//										   Easyfind				    	    							|
//=======================================================================================================

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end()) {
        std::cout <<LIGHT_RED<< "Element not found!" <<RESET_COLOR<< std::endl;
        return container.end(); // Retourne un itérateur vers la fin
    }
    std::cout << "Found: " << *it << std::endl;
    return it; // Retourne l'itérateur où l'élément a été trouvé
}
