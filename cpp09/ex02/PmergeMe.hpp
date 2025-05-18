// ╔─────────────────────────────────────────────────────────¤◎¤─────────────────────────────────────────────────────────╗
// 		 ✩ Entrée une séquence d’entiers positif en argument(->3000)
//       ✩ doit utiliser l’algorithme de tri "merge-insert" Ford-Johnson
//       ✩ au moins deux conteneurs    

//       Affichage:
//       ✩ première ligne, un texte explicite + la séquence d’entiers positifs non triés
//       ✩ deuxième ligne, un texte explicite + la séquence d’entiers positifs triés
//       ✩ troisième ligne, un texte explicite + le temps d’exécution de l’algorithme et le 1er container utilisé
//       ✩ quatrième ligne, un texte explicite + le temps d’exécution de l’algorithme et le 2ème container utilisé
//       ✩ précision pour voir la difference entre les deux containers

//       ✩ Algo:  tri par pair, puis tri par insertion avec sequence de Jacobsthal
//       ✩ Container: std::vector(contiguë) et std::deque
//       ✩ même utilisation (.begin(), .end(), .size(), .push_back(), .insert(),)
// ╚─────────────────────────────────────────────────────────¤◎¤─────────────────────────────────────────────────────────╝

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <set>
#include <iomanip>


#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define BLUE            "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m"
#define MAGENTA		  	"\033[0;35m"
#define LILAC		   	"\033[0;94m"
#define LIGHT_BLUE		"\033[0;34m"
#define LIGHT_TURCOI    "\033[0;36m"
#define LIGHT_RED	  	"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE	    "\033[0;94m"
#define PEACH		    "\033[0;93m"
#define LIGHT_CYAN      "\033[0;36m"
#define BOLD		    "\033[1m"
#define ENDL            std::endl

class PmergeMe
{
    private:
    //    ✩  ---------  Containers   ---------   ✩
        std::vector<int> _vec;
        std::deque<int>  _deq;
        std::string _rawInputCleaned;

    //    ✩  ---------  Fonctions   ---------   ✩
        
        void mergeInsertSortVector(std::vector<int>& vec);
        // void mergeInsertSortDeque(std::deque<int>& deq);

        // Étapes internes de l'algorithme Ford-Johnson
        void recursiveSortVector(std::vector<int>& vec);
        // void recursiveSortDeque(std::deque<int>& deq);

        void insertWithJacobsthalVector(std::vector<int>& sorted, std::vector<int>& pending);
        // void insertWithJacobsthalDeque(std::deque<int>& sorted, std::deque<int>& pending);
    //    ✩  ---------  Utils   ---------   ✩
    void printStatusVector(const std::vector<int>& vec) const;
        // void parseInput(char** argv);
        void parseInputStringVector(const std::string& inputLine) ;//met tout en 1
        std::vector<size_t> generateJacobsthalSequenceVector(size_t max);
        void printContainerVector(const std::string& label, const std::vector<int>& container) const;
        // void printContainer(const std::string& label, const std::deque<int>& container) const;
        bool isDuplicateFreeVector(const std::vector<int>& input) const;
    //    ✩  ---------  Timer   ---------   ✩
        double benchmarkVector();
        void printBenchmarkTime(double timeUs, const std::string& containerName, size_t size);

        void printStatusDeque(const std::deque<int>& deq) const;
        void printContainerDeque(const std::string& prefix, const std::deque<int>& container) const;
        bool isDuplicateFreeDeque(const std::deque<int>& input) const;
        void parseInputStringDeque(const std::string& inputLine) ;
        std::deque<size_t> generateJacobsthalSequenceDeque(size_t max);
        double benchmarkDeque();
        void mergeInsertSortDeque(std::deque<int>& deq);
        void recursiveSortDeque(std::deque<int>& deq);
        void insertWithJacobsthalDeque(std::deque<int>& sorted, std::deque<int>& pending);
    
    public:

    //    ✩  ---------   Constructor - Destructor - Const with arg - Copy    --------- 
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const &src);
    //    ✩  ---------   Opérator    ---------
        PmergeMe &operator=(PmergeMe const &rhs);

    //    ✩  ---------  Fonctions   ---------   ✩
        void sort();   
        void parseInput(char** argv);
       

};
#endif