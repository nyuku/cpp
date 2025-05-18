// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ associer une date à un taux de bitcoin
//       ✩ Bien choisir le type de container pour stocker les données
//       ✩ map: Il associe une clé (std::string, la date) à une valeur (float, le taux de bitcoin).
//          une fonction lit  lit le fichier CSV et remplit la map avec les données
//         
// 		 ✩ charge base données depuis un fichier CSV, parsing valeur et date, verifier ouverture
//       ✩ gérer les convertions et verifier les formats et validité
//       ✩ calcule la valeur du bitcoin en fonction de la date  YYYY-MM-DD
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>

#include <sstream>
#include <cstdlib>
#include <limits>
#include <algorithm>




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



class BitcoinExchange
{
    private:
        
        std::map<std::string, float> _csvdata;
        std::string _date; 
    public:

    //    ✩  ---------   Constructor - Destructor  - Copy    --------- 
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &other);

    //    ✩  ---------   Opérator    ---------
        BitcoinExchange&operator=(const BitcoinExchange &other);

    //    ✩  ---------  Fonctions   ---------   ✩
        bool loadDatabase(const std::string& filename);
        bool isValidDateFormat(const std::string& dateStr) const;
        float getRateForDate(const std::string& dateStr) const;

    //    ✩  --------- utils   ---------   ✩
        bool checkFileOpen(std::ifstream &file)const;
        void processFile(std::ifstream& input);
        bool isPositiveNumber(const std::string& valueStr);

};
#endif