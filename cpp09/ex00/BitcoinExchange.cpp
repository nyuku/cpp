

// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Lire un fichier CSV de taux (data.csv) contenant des paires date, taux.

// Lire un fichier d’entrée (input.txt) contenant des lignes date | valeur.

// Pour chaque ligne de input.txt, trouver le taux le plus proche dans le passé (ou le même jour) et multiplier par la valeur.

// Afficher le résultat ou des messages d’erreur.
//       ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "BitcoinExchange.hpp"



//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................
    BitcoinExchange::BitcoinExchange() {}
    BitcoinExchange::~BitcoinExchange() {}

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
    {
        if (this != &other)
            this->_csvdata = other._csvdata;
        return *this;
    }

//.......................................................................................................
//										 Copy Constructors                                               |
//.......................................................................................................
    BitcoinExchange::BitcoinExchange(BitcoinExchange &other) 
    {
        this->_csvdata = other._csvdata;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Ignore la première ligne (header)

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        float rate = std::atof(rateStr.c_str());
        if (rate > std::numeric_limits<float>::max()) {
            std::cerr << "Error: value exceeds float limit for date " << date << std::endl;
            continue;  // Skip this entry if the value is too large
        }
        _csvdata[date] = rate;
    }

    return true;
}

// Vérifie le format de date "YYYY-MM-DD"
bool BitcoinExchange::isValidDateFormat(const std::string& dateStr) const
{
    if (dateStr.length() != 10)
        return false;
    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    for (size_t i = 0; i < dateStr.length(); ++i) {
        if ((i == 4 || i == 7))
            continue;
        if (!isdigit(dateStr[i]))
            return false;
    }

    return true;
}

// Trouve le taux pour une date exacte ou la date précédente la plus proche
float BitcoinExchange::getRateForDate(const std::string& dateStr) const
{
    std::map<std::string, float>::const_iterator it = _csvdata.lower_bound(dateStr);

    // Si la date n'existe pas exactement, on prend la précédente
    if (it != _csvdata.end() && it->first != dateStr) {
        if (it == _csvdata.begin())
            throw std::runtime_error("Error: no earlier date in database.");
        --it;
    }

    if (it == _csvdata.end())
        throw std::runtime_error("Error: no matching or earlier date found.");

    return it->second;
}
//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================


//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================


//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================