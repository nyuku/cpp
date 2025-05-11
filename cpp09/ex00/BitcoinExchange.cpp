

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
    if (!file.is_open()) 
        return (false);

    std::string line;
    std::getline(file, line); // Ignore la première ligne (header)

    while (std::getline(file, line)) 
    {
        std::istringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        float rate = std::atof(rateStr.c_str());
        if (rate > std::numeric_limits<float>::max()) {
            std::cerr <<LIGHT_RED<< ENDL<<"Error: value exceeds float limit for date " <<RESET_COLOR<< date << std::endl;
            continue;  // Skip this entry if the value is too large
        }
        _csvdata[date] = rate;
    }

    return (true);
}

// Vérifie le format de date "YYYY-MM-DD"
bool BitcoinExchange::isValidDateFormat(const std::string& dateStr) const
{
    const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    for (size_t i = 0; i < dateStr.length(); ++i) //verifie si que chiffre
    {
        if ((i == 4 || i == 7))//"YYYY-MM-DD"
            continue;
        if (!isdigit(dateStr[i]))
            return false;
    }
    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());
    if (year < 2009 || year > 2023) // Bitcoin started in 2009
    {
        std::cerr << LIGHT_RED <<ENDL<< "Error: Year out of range." << RESET_COLOR << std::endl;
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {  
        std::cerr << LIGHT_RED <<ENDL<< "Error: There's something odd in the number" << RESET_COLOR << std::endl;
        return false;
    }
    if (month == 2 && day == 29) //bissextile
    {
        if (!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) 
        {
            std::cerr << LIGHT_RED <<ENDL<< "Error: This is not a leap year, this February 29 is invalid." << RESET_COLOR << std::endl;
            return false;
        }
    }
    else if (day > daysInMonth[month - 1]) 
    {
        std::cerr << LIGHT_RED <<ENDL<< "Error: This is an invalid day for the given month." << RESET_COLOR << std::endl;
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
//										   utils												|
//=======================================================================================================
    bool BitcoinExchange::checkFileOpen(std::ifstream& file) const 
    {
        if (!file.is_open()) 
        {
            std::cerr <<LIGHT_RED<< "Error: could not open input file." <<RESET_COLOR<< std::endl;
            return false;
        }
        return true;
    }
    
    void BitcoinExchange::processFile(std::ifstream& input) 
    {
        if (!loadDatabase("data.csv")) {
            std::cerr << LIGHT_RED << "Error: failed to load data.csv" << RESET_COLOR << std::endl;
            return;
        }
    
        std::string line;
        std::getline(input, line); // Skip header line
    
        while (std::getline(input, line)) {
            if (line.empty()) continue;
    
            std::istringstream ss(line);
            std::string date, valueStr;
    
            if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
                std::cerr << "\tError: bad input => " << line << std::endl;
                continue;
            }
    
            // Trim spaces
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    
            if (!isValidDateFormat(date)) 
            {
                std::cerr << "\tError: bad input => " << date << std::endl;
                continue;
            }
    
            float value = std::atof(valueStr.c_str());
            if (value > 1000) {
                std::cerr <<ENDL<<LIGHT_RED<< "Error: value too large." <<RESET_COLOR<<  std::endl;
                std::cerr<<"\tBad input => "<<RESET_COLOR<< value << std::endl;
                continue;
            }
    
            if (!isPositiveNumber(valueStr)) {
                std::cerr <<LIGHT_RED<<ENDL<< "Error: not a positive number." <<RESET_COLOR<< std::endl;
                continue;
            }
    
            try 
            {
                float rate = getRateForDate(date);
                float result = rate * value;
                std::cout <<LIGHT_CYAN<< date <<RESET_COLOR<< "    ===> " <<LIGHT_BLUE<< value <<RESET_COLOR<<" * "<< rate<< " \t\t= " << LIGHT_MAGENTA<<result <<RESET_COLOR<< std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    
//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================


//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================
bool BitcoinExchange::isPositiveNumber(const std::string& valueStr) 
{
    std::istringstream iss(valueStr);
    float value;
    iss >> value;
    return !iss.fail() && value >= 0 && value <= 1000;
}