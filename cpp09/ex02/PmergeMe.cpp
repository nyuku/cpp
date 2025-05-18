

// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "PmergeMe.hpp"

//.......................................................................................................
//										Constructor - Destructor- copy				            		|
//.......................................................................................................
    PmergeMe::PmergeMe() {}

    PmergeMe::~PmergeMe() {}

    PmergeMe::PmergeMe(PmergeMe const &src)
    {
        *this = src;
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
    {
        if (this != &rhs)
        {
            _vec = rhs._vec;
            // _deque = rhs._deque;
        }
        return *this;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
void PmergeMe::sort()
{
    
    std::cout << "Before: ";
    //print raw input
    std::cout << LIGHT_CYAN << _rawInputCleaned << RESET_COLOR << std::endl;
    
    benchmarkVector();//lance l'algo + timer
    // benchmarkDeque();

    std::cout << "After: ";
    printContainer("", _vec); // ou _deque
}



//=======================================================================================================
//										  Utils				    							|
//=======================================================================================================
void PmergeMe::printStatusSorting(const std::vector<int>& vec) const
{
    std::cout << LIGHT_CYAN << "Status: " << RESET_COLOR << "[ ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << " ";
    }
    std::cout << " ]" << std::endl;
}    
void PmergeMe::printContainer(const std::string& prefix, const std::vector<int>& container) const
{
    std::cout << prefix;
    std::cout << "[ ";
    for (size_t i = 0; i < container.size(); ++i)
    {
        std::cout << container[i];
        if (i != container.size() - 1)
            std::cout << " ";
    }
    std::cout << " ]" << std::endl;
}

bool PmergeMe::isDuplicateFree(const std::vector<int>& input) const
{
    std::set<int> seen;
    for (size_t i = 0; i < input.size(); ++i) {
        if (seen.find(input[i]) != seen.end()) {
            return false; // doublon trouvé
        }
        seen.insert(input[i]);
    }
    return true; // aucun doublon
}


void PmergeMe::parseInput(char** argv) //all in one
    {
        std::string allArgs;
        for (int i = 1; argv[i]; ++i) 
        {
            allArgs += argv[i];
            allArgs += " ";
        }
        parseInputString(allArgs);
    }

    void PmergeMe::parseInputString(const std::string& inputLine) 
    {
        std::istringstream iss(inputLine);
        std::string token;
        bool first = true;
    
        while (iss >> token) 
        {
            // Vérifie que le token est composé uniquement de chiffres
            if (!first)
                _rawInputCleaned += " ";
            if (token.find_first_not_of("0123456789") != std::string::npos) //check le token entier si caracter valid selon ref
            {
                std::cerr <<LIGHT_RED<< "Error: Invalid input here: " <<RESET_COLOR<< token << std::endl;
                std::exit(EXIT_FAILURE);
            }
    
            long value = std::strtol(token.c_str(), NULL, 10);
    
            // Vérifie les bornes
            if (value < 0 || value > std::numeric_limits<int>::max()) 
            {
                std::cerr << "Error: Out of range '" << token << "'" << std::endl;
                std::exit(EXIT_FAILURE);
            }
    
            _vec.push_back(static_cast<int>(value));//met dans les containers
            // _deque.push_back(static_cast<int>(value));
            _rawInputCleaned += token + " ";
            first = false;
        }
    
        if (_vec.empty()) 
        {
            std::cerr << "Error: No input numbers." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    
        // Optionnel : check de doublons
        if (!isDuplicateFree(_vec)) {
            std::cerr << "Error: Duplicate values found." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t max)
    {
        std::vector<size_t> seq;
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
//										   Timer- algo					    							|
//=======================================================================================================
    void PmergeMe::benchmarkVector()
    {
        clock_t start = clock();

        mergeInsertSortVector(_vec);

        clock_t end = clock();
        double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // us

        std::cout << "Time to process a range of " 
                << _vec.size() 
                << " elements with std::vector : " 
                << elapsed 
                << " us" << std::endl;
    }

    // void PmergeMe::benchmarkDeque()
    // {
    //     clock_t start = clock();

    //     mergeInsertSortDeque(_deque);

    //     clock_t end = clock();
    //     double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // us

    //     std::cout << "Time to process a range of " 
    //             << _deque.size() 
    //             << " elements with std::deque : " 
    //             << elapsed 
    //             << " us" << std::endl;
    // }

//=======================================================================================================
//										   Merge Insert Sort 										|           
//=======================================================================================================
    void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
    {
        if (vec.size() <= 1) return; // Si le vecteur est déjà trié ou vide, rien à faire

        // Étape 1 : Diviser le vecteur en deux moitiés
        std::vector<int> maxima;  // Pour stocker les plus grands de chaque paire
        std::vector<int> pending; // Pour stocker les éléments restants à insérer
    
        size_t i = 0;
        // Étape 1 : Séparer les paires
        while (i + 1 < vec.size())//s'il y a un next donc au moins 2element
        {
            if (vec[i] > vec[i + 1]) //on a un maxima en [i]
            {
                maxima.push_back(vec[i]);
                pending.push_back(vec[i + 1]);
            }
            else
            {
                maxima.push_back(vec[i + 1]);
                pending.push_back(vec[i]);
            }
            i += 2;
        }
        if (i < vec.size())
        pending.push_back(vec[i]);

        std::cout << "\n==========merge insert sort=============" << std::endl;
        std::cout << "\n\nPending(merge) : ";
        printStatusSorting(pending); // Affiche l'état de tri
        std::cout << "Maxima(merge) : ";
        printStatusSorting(maxima); // Affiche l'état de tri
        std::cout<<ENDL;
        // Étape 2 : Trier les maxima récursivement jusqu'à 1 élément
        if (maxima.size() > 1)
            recursiveSortVector(maxima);

        // Étape 3 : Insérer les autres éléments dans l'ordre optimisé
        insertWithJacobsthalVector(maxima, pending);

        // Étape 4 : Écraser vec avec la séquence triée finale
        vec = maxima;
    }

    void PmergeMe::recursiveSortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    // Diviser le vecteur en deux moitiés  
    std::cout << "\n==========recursive SortVector=============" << std::endl; 
    std::cout << "Before splitting: ";
    printStatusSorting(vec);

    size_t mid = vec.size() / 2;

    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());

    // Tri récursif sur chaque moitié
    recursiveSortVector(left);
    recursiveSortVector(right);

    std::cout << "Left sorted: ";
    printStatusSorting(left);
    std::cout << "Right sorted: ";
    printStatusSorting(right);

    // Fusion des deux moitiés triées
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }

    // Copier le reste si un côté est terminé
    while (i < left.size())
        vec[k++] = left[i++];
    while (j < right.size())
        vec[k++] = right[j++];
    std::cout << "After merging: ";
    printStatusSorting(vec);
}

void PmergeMe::insertWithJacobsthalVector(std::vector<int>& sorted, std::vector<int>& pending)
{
    std::vector<bool> inserted(pending.size(), false);
    size_t i = 0;
    if (pending.empty())
        return;
    std::cout << "\n========== insert Jacobsthal=============" << std::endl;
    // Générer la séquence de Jacobsthal jusqu'à la taille de pending
    std::vector<size_t> jacobsthalSeq = generateJacobsthalSequence(pending.size());
    std::cout << "Jacobsthal sequence: ";
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
    {
        std::cout << jacobsthalSeq[i] << " ";
    }
    std::cout << std::endl;

    // On parcourt les indices dans l'ordre de la séquence de Jacobsthal
   
    std::cout << "Sorted avant(maxima): ";
    printStatusSorting(sorted); // Affiche l'état de tri
    std::cout << "Pending avant: ";
    printStatusSorting(pending); // Affiche l'état de tri

    for ( i = 0; i < jacobsthalSeq.size(); ++i)
    {
        size_t idx = jacobsthalSeq[i];
       
        if (idx >= pending.size())
            continue;

        int value = pending[idx];
        std::cout << "\nValue to insert from pending: " << pending[idx] << ", index: " << idx << std::endl;
        std::cout <<LIGHT_GREEN<< "\nafter insert: "<<RESET_COLOR;
       // Affiche l'état de tri

        // Insertion par recherche binaire dans 'sorted'
        std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
        sorted.insert(it, value);
        inserted[idx] = true;
        printStatusSorting(sorted);
        ///probeleme vec la suite sans sequence
        // while(i < pending.size())
        // {
        //     if (!inserted[i])
        //     {
        //         int value = pending[i];
        //         std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
        //         sorted.insert(it, value);
        //         inserted[i] = true;

        //         std::cout << "Inserted: " << value <<", round: "<<i<< std::endl;
        //         std::cout <<LIGHT_TURCOI<< "Sorted apres insertion: "<<RESET_COLOR;
        //         printStatusSorting(sorted);
        //         std::cout <<LIGHT_TURCOI<< "Pending apres insertion: "<<RESET_COLOR;
        //         printStatusSorting(pending); // Affiche l'état de tri
        //     }
        //     i++;
        // }
         // Affiche l'état de tri
        // std::cout << "Inserted: " << value <<", round: "<<i<< std::endl;
        // std::cout <<LIGHT_TURCOI<< "Sorted apres insertion: "<<RESET_COLOR;
        // printStatusSorting(sorted);
        // std::cout <<LIGHT_TURCOI<< "Pending apres insertion: "<<RESET_COLOR;
        // printStatusSorting(pending); // Affiche l'état de tri
    }
    while(i < pending.size())
        {
            std::cout<<"End of Jacobsthal sequence, insert remaining elements"<<std::endl;
            if (!inserted[i])
            {
                int value = pending[i];
                std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
                sorted.insert(it, value);
                inserted[i] = true;

                std::cout << "Inserted: " << value <<", round: "<<i<< std::endl;
                std::cout <<LIGHT_TURCOI<< "Sorted apres insertion: "<<RESET_COLOR;
                printStatusSorting(sorted);
                std::cout <<LIGHT_TURCOI<< "Pending apres insertion: "<<RESET_COLOR;
                printStatusSorting(pending); // Affiche l'état de tri
            }
            i++;
        }
    printStatusSorting(sorted); // Affiche l'état de tri
    // // Vider le vecteur pending si besoin
    // pending.clear();
}
