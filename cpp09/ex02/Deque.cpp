// Pas de fonction template générique unique. Fais deux vraies versions, une pour deqtor, une pour deque.
#include "PmergeMe.hpp"
//=======================================================================================================
//										  Printing				    			        				|
//=======================================================================================================
    void PmergeMe::printStatusDeque(const std::deque<int>& deq) const
    {
        std::cout << LIGHT_CYAN << "Status Deque: " << RESET_COLOR << "[ ";
        for (size_t i = 0; i < deq.size(); ++i)
        {
            std::cout << deq[i];
            if (i != deq.size() - 1)
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
    void PmergeMe::printContainerDeque(const std::string& prefix, const std::deque<int>& container) const
    {
        std::cout << prefix;
        std::cout << "[ ";
        for (size_t i = 0; i < container.size(); ++i)
        {
            std::cout << container[i];
            if (i != container.size() - 1)
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
//=======================================================================================================
//										  Utils				    				            			|
//=======================================================================================================
    bool PmergeMe::isDuplicateFreeDeque(const std::deque<int>& input) const
    {
        std::set<int> seen;
        for (size_t i = 0; i < input.size(); ++i) {
            if (seen.find(input[i]) != seen.end()) {
                return false; 
            }
            seen.insert(input[i]);
        }
        return true; 
    }

    std::deque<size_t> PmergeMe::generateJacobsthalSequenceDeque(size_t max)
    {
        std::deque<size_t> seq;
        if (max == 0)
            return seq;
    
        size_t J0 = 0;
        size_t J1 = 1;
    
        seq.push_back(J0);
        if (J1 < max)
            seq.push_back(J1);
    
        while (true)
        {
            size_t next = J1 + 2 * J0;
            if (next >= max)
                break;
    
            // Évite les doublons : on vérifie que next est différent du dernier élément inséré
            if (seq.empty() || next != seq.back())
                seq.push_back(next);
    
            J0 = J1;
            J1 = next;
        }
    
        return seq;
    }
//=======================================================================================================
//										  Parsing				    				            		|   
//
//=======================================================================================================
    void PmergeMe::parseInputStringDeque(const std::string& inputLine) 
    {
        bool rawempty = false;
        std::istringstream iss(inputLine);
        std::string token;
        bool first = true;
        if (inputLine.empty()) 
        {
            std::cerr << "Error: Empty input." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (inputLine.length() > 3000) 
        {
            std::cerr <<LIGHT_RED<< "Error: Input too long." <<RESET_COLOR<< std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (inputLine.length() < 2) 
        {
            std::cerr <<LIGHT_RED<< "Error: Input too short to be sorted." <<RESET_COLOR<< std::endl;
            std::exit(EXIT_FAILURE);
        }
        while (iss >> token) 
        {

            if (!first && rawempty == true)
                _rawInputCleaned += " ";
            if (token.find_first_not_of("0123456789") != std::string::npos) //check le token entier si caracter valid selon ref
            {
                std::cerr <<LIGHT_RED<< "Error: Invalid input here: " <<RESET_COLOR<< token << std::endl;
                std::exit(EXIT_FAILURE);
            }

            long value = std::strtol(token.c_str(), NULL, 10);

        
            if (value < 0 || value > std::numeric_limits<int>::max()) 
            {
                std::cerr << "Error: Out of range '" << token << "'" << std::endl;
                std::exit(EXIT_FAILURE);
            }

            _deq.push_back(static_cast<int>(value));//met dans les containers
            if (_rawInputCleaned.empty())
                rawempty = true;
            if (rawempty == true)
                _rawInputCleaned += token + " ";
            first = false;
        }

        if (_deq.empty()) 
        {
            std::cerr << "Error: No input numbers." << std::endl;
            std::exit(EXIT_FAILURE);
        }


        if (!isDuplicateFreeDeque(_deq)) {
            std::cerr <<LIGHT_RED<< "Error: Duplicate values found." << RESET_COLOR<< std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

//=======================================================================================================
//										  Main				    				            			| 
//========================================================================================================
    void PmergeMe::benchmarkDeque()
    {
        clock_t start = clock();

        mergeInsertSortDeque(_deq);

        clock_t end = clock();
        double timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // us

        std::cout << "Time to process a range of " 
                <<LIGHT_GREEN
                << _deq.size() <<RESET_COLOR
                << std::fixed << std::setprecision(5)
                << " elements with "
                <<LIGHT_GREEN
                <<"std::deque "
                <<RESET_COLOR
                <<": " 
                <<LIGHTPURPLE
                << timer 
                <<RESET_COLOR
                << " us" << std::endl;
    }

    void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq)
    {
        if (deq.size() <= 1) return; // Si le container est déjà trié ou vide, rien à faire

        // Étape 1 : Diviser le container en deux moitiés
        std::deque<int> maxima;  // Pour stocker les plus grands de chaque paire
        std::deque<int> pending; // Pour stocker les éléments restants à insérer
    
        size_t i = 0;
        // Étape 1 : Séparer les paires
        while (i + 1 < deq.size())//s'il y a un next donc au moins 2element
        {
            if (deq[i] > deq[i + 1]) //on a un maxima en [i]
            {
                maxima.push_back(deq[i]);
                pending.push_back(deq[i + 1]);
            }
            else
            {
                maxima.push_back(deq[i + 1]);
                pending.push_back(deq[i]);
            }
            i += 2;
        }
        if (i < deq.size())
        pending.push_back(deq[i]);

        
        // Étape 2 : Trier les maxima récursivement jusqu'à 1 élément
        if (maxima.size() > 1)
            recursiveSortDeque(maxima);

        // Étape 3 : Insérer les autres éléments dans l'ordre optimisé
        insertWithJacobsthalDeque(maxima, pending);

        // Étape 4 : Écraser deq avec la séquence triée finale
        deq = maxima;
    }

    void PmergeMe::recursiveSortDeque(std::deque<int>& deq)
    {
        if (deq.size() <= 1)
            return;

        size_t mid = deq.size() / 2;

        std::deque<int> left(deq.begin(), deq.begin() + mid);
        std::deque<int> right(deq.begin() + mid, deq.end());

       
        recursiveSortDeque(left);
        recursiveSortDeque(right);


        // Fusion des deux moitiés triées
        size_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
                deq[k++] = left[i++];
            else
                deq[k++] = right[j++];
        }

   
        while (i < left.size())
            deq[k++] = left[i++];
        while (j < right.size())
            deq[k++] = right[j++];
    
    }

    void PmergeMe::insertWithJacobsthalDeque(std::deque<int>& sorted, std::deque<int>& pending)
{
    std::deque<bool> inserted(pending.size(), false);
    size_t i = 0;
    if (pending.empty())
        return;

    std::deque<size_t> jacobsthalSeq = generateJacobsthalSequenceDeque(pending.size());
    for ( i = 0; i < jacobsthalSeq.size(); ++i)
    {
        size_t idx = jacobsthalSeq[i];
       
        if (idx >= pending.size())
            continue;

        int value = pending[idx];

        std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
        sorted.insert(it, value);
        inserted[idx] = true;

        
    }
    while(i < pending.size())
        {
            if (!inserted[i])
            {
                int value = pending[i];
                std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
                sorted.insert(it, value);
                inserted[i] = true;

            }
            i++;
        }
 
}





// // Pas de fonction template générique unique. Fais deux vraies versions, une pour deqtor, une pour deque.
// #include "PmergeMe.hpp"
// //=======================================================================================================
// //										  Printing				    			        				|
// //=======================================================================================================
//     void PmergeMe::printStatusDeque(const std::deque<int>& deq) const
//     {
//         std::cout << LIGHT_CYAN << "Status: " << RESET_COLOR << "[ ";
//         for (size_t i = 0; i < deq.size(); ++i)
//         {
//             std::cout << deq[i];
//             if (i != deq.size() - 1)
//                 std::cout << ", ";
//         }
//         std::cout << " ]" << std::endl;
//     }
//     void PmergeMe::printContainerDeque(const std::string& prefix, const std::deque<int>& container) const
//     {
//         std::cout << prefix;
//         std::cout << "[ ";
//         for (size_t i = 0; i < container.size(); ++i)
//         {
//             std::cout << container[i];
//             if (i != container.size() - 1)
//                 std::cout << ", ";
//         }
//         std::cout << " ]" << std::endl;
//     }
// //=======================================================================================================
// //										  Utils				    				            			|
// //=======================================================================================================
//     bool PmergeMe::isDuplicateFreeDeque(const std::deque<int>& input) const
//     {
//         std::set<int> seen;
//         for (size_t i = 0; i < input.size(); ++i) {
//             if (seen.find(input[i]) != seen.end()) {
//                 return false; // doublon trouvé
//             }
//             seen.insert(input[i]);
//         }
//         return true; // aucun doublon
//     }

//     std::deque<size_t> PmergeMe::generateJacobsthalSequenceDeque(size_t max)
//     {
//         std::deque<size_t> seq;
//         if (max == 0)
//             return seq;
    
//         size_t J0 = 0;
//         size_t J1 = 1;
    
//         seq.push_back(J0);
//         if (J1 < max)
//             seq.push_back(J1);
    
//         while (true)
//         {
//             size_t next = J1 + 2 * J0;
//             if (next >= max)
//                 break;
    
//             // Évite les doublons : on vérifie que next est différent du dernier élément inséré
//             if (seq.empty() || next != seq.back())
//                 seq.push_back(next);
    
//             J0 = J1;
//             J1 = next;
//         }
    
//         return seq;
//     }
// //=======================================================================================================
// //										  Parsing				    				            		|   
// //
// //=======================================================================================================
//     void PmergeMe::parseInputStringDeque(const std::string& inputLine) 
//     {
//         std::istringstream iss(inputLine);
//         std::string token;
//         bool first = true;
//         if (inputLine.empty()) 
//         {
//             std::cerr << "Error: Empty input." << std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//         if (inputLine.length() > 3000) 
//         {
//             std::cerr <<LIGHT_RED<< "Error: Input too long." <<RESET_COLOR<< std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//         if (inputLine.length() < 2) 
//         {
//             std::cerr <<LIGHT_RED<< "Error: Input too short to be sorted." <<RESET_COLOR<< std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//         while (iss >> token) 
//         {
//             // Vérifie que le token est composé uniquement de chiffres
//             if (!first)
//                 _rawInputCleaned += " ";
//             if (token.find_first_not_of("0123456789") != std::string::npos) //check le token entier si caracter valid selon ref
//             {
//                 std::cerr <<LIGHT_RED<< "Error: Invalid input here: " <<RESET_COLOR<< token << std::endl;
//                 std::exit(EXIT_FAILURE);
//             }

//             long value = std::strtol(token.c_str(), NULL, 10);

//             // Vérifie les bornes
//             if (value < 0 || value > std::numeric_limits<int>::max()) 
//             {
//                 std::cerr << "Error: Out of range '" << token << "'" << std::endl;
//                 std::exit(EXIT_FAILURE);
//             }

//             _deq.push_back(static_cast<int>(value));//met dans les containers
//             // _deque.push_back(static_cast<int>(value));
//             _rawInputCleaned += token + " ";
//             first = false;
//         }

//         if (_deq.empty()) 
//         {
//             std::cerr << "Error: No input numbers." << std::endl;
//             std::exit(EXIT_FAILURE);
//         }

//         // Optionnel : check de doublons
//         if (!isDuplicateFreeDeque(_deq)) {
//             std::cerr <<LIGHT_RED<< "Error: Duplicate values found." << RESET_COLOR<< std::endl;
//             std::exit(EXIT_FAILURE);
//         }
//     }

// //=======================================================================================================
// //										  Main				    				            			| 
// //========================================================================================================
//     void PmergeMe::benchmarkDeque()
//     {
//         clock_t start = clock();

//         mergeInsertSortDeque(_deq);

//         clock_t end = clock();
//         double timer = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // us

//         std::cout << "Time to process a range of " 
//                 <<LIGHT_GREEN
//                 << _deq.size() <<RESET_COLOR
//                 << std::fixed << std::setprecision(5)
//                 << " elements with "
//                 <<LIGHT_GREEN
//                 <<"std::deque "
//                 <<RESET_COLOR
//                 <<": " 
//                 <<LIGHTPURPLE
//                 << timer 
//                 <<RESET_COLOR
//                 << " us" << std::endl;
//     }

//     void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq)
//     {
//         if (deq.size() <= 1) return; // Si le container est déjà trié ou vide, rien à faire

//         // Étape 1 : Diviser le container en deux moitiés
//         std::deque<int> maxima;  // Pour stocker les plus grands de chaque paire
//         std::deque<int> pending; // Pour stocker les éléments restants à insérer
    
//         size_t i = 0;
//         // Étape 1 : Séparer les paires
//         while (i + 1 < deq.size())//s'il y a un next donc au moins 2element
//         {
//             if (deq[i] > deq[i + 1]) //on a un maxima en [i]
//             {
//                 maxima.push_back(deq[i]);
//                 pending.push_back(deq[i + 1]);
//             }
//             else
//             {
//                 maxima.push_back(deq[i + 1]);
//                 pending.push_back(deq[i]);
//             }
//             i += 2;
//         }
//         if (i < deq.size())
//         pending.push_back(deq[i]);

//         // std::cout << "\n==========merge insert sort=============" << std::endl;
//         // std::cout << "\n\nPending(merge) : ";
//         // printStatusDeque(pending);
//         // std::cout << "Maxima(merge) : ";
//         // printStatusDeque(maxima);
//         // std::cout<<ENDL;
        
//         // Étape 2 : Trier les maxima récursivement jusqu'à 1 élément
//         if (maxima.size() > 1)
//             recursiveSortDeque(maxima);

//         // Étape 3 : Insérer les autres éléments dans l'ordre optimisé
//         insertWithJacobsthalDeque(maxima, pending);

//         // Étape 4 : Écraser deq avec la séquence triée finale
//         deq = maxima;
//     }

//     void PmergeMe::recursiveSortDeque(std::deque<int>& deq)
//     {
//         if (deq.size() <= 1)
//             return;
//         // Diviser le container en deux moitiés  
//         // std::cout << "\n==========recursive Sortdeque=============" << std::endl; 
//         // std::cout << "Before splitting: ";
//         // printStatusDeque(deq);

//         size_t mid = deq.size() / 2;

//         std::deque<int> left(deq.begin(), deq.begin() + mid);
//         std::deque<int> right(deq.begin() + mid, deq.end());

//         // Tri récursif sur chaque moitié
//         recursiveSortDeque(left);
//         recursiveSortDeque(right);

//         // std::cout << "Left sorted: ";
//         // printStatusDeque(left);
//         // std::cout << "Right sorted: ";
//         // printStatusDeque(right);

//         // Fusion des deux moitiés triées
//         size_t i = 0, j = 0, k = 0;
//         while (i < left.size() && j < right.size())
//         {
//             if (left[i] < right[j])
//                 deq[k++] = left[i++];
//             else
//                 deq[k++] = right[j++];
//         }

//         // Copier le reste si un côté est terminé
//         while (i < left.size())
//             deq[k++] = left[i++];
//         while (j < right.size())
//             deq[k++] = right[j++];
//         // std::cout << "After merging: ";
//         // printStatusDeque(deq);
//     }

//     void PmergeMe::insertWithJacobsthalDeque(std::deque<int>& sorted, std::deque<int>& pending)
// {
//     std::deque<bool> inserted(pending.size(), false);
//     size_t i = 0;
//     if (pending.empty())
//         return;
//     // std::cout << "\n========== insert Jacobsthal=============" << std::endl;
//     // Générer la séquence de Jacobsthal jusqu'à la taille de pending
//     // std::deque<size_t> jacobsthalSeq = generateJacobsthalSequenceDeque(pending.size());
//     // std::cout << "Jacobsthal sequence: ";
//     // for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
//     // {
//     //     std::cout << jacobsthalSeq[i] << " ";
//     // }
//     // std::cout << std::endl;

//     // On parcourt les indices dans l'ordre de la séquence de Jacobsthal
   
//     // std::cout << "Sorted avant(maxima): ";
//     // printStatusDeque(sorted); 
//     // std::cout << "Pending avant: ";
//     // printStatusDeque(pending);

//     for ( i = 0; i < jacobsthalSeq.size(); ++i)
//     {
//         size_t idx = jacobsthalSeq[i];
       
//         if (idx >= pending.size())
//             continue;

//         int value = pending[idx];
//         // std::cout << "\nValue to insert from pending: " << pending[idx] << ", index: " << idx << std::endl;
//         // std::cout <<LIGHT_GREEN<< "\nafter insert: "<<RESET_COLOR;
//        // Affiche l'état de tri

//         // Insertion par recherche binaire dans 'sorted'
//         std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
//         sorted.insert(it, value);
//         inserted[idx] = true;
//         // printStatusDeque(sorted);
        
//     }
//     while(i < pending.size())
//         {
//             // std::cout<<"End of Jacobsthal sequence, insert remaining elements"<<std::endl;
//             if (!inserted[i])
//             {
//                 int value = pending[i];
//                 std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
//                 sorted.insert(it, value);
//                 inserted[i] = true;

//                 // std::cout << "Inserted: " << value <<", round: "<<i<< std::endl;
//                 // std::cout <<LIGHT_TURCOI<< "Sorted apres insertion: "<<RESET_COLOR;
//                 // printStatusDeque(sorted);
//                 // std::cout <<LIGHT_TURCOI<< "Pending apres insertion: "<<RESET_COLOR;
//                 // printStatusDeque(pending); // Affiche l'état de tri
//             }
//             i++;
//         }
//     // printStatusDeque(sorted); // Affiche l'état de tri
 
// }
