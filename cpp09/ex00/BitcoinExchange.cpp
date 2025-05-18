

// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Lire un fichier CSV de taux (data.csv) contenant des paires date, taux.
//       ✩ Lire un fichier d’entrée (input.txt) contenant des lignes date | valeur.
//       ✩ Pour chaque ligne de input.txt, trouver le taux le plus proche dans le passé (ou le même jour) et multiplier par la valeur.
//       ✩ Afficher le résultat ou des messages d’erreur.
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
            continue; 
        }
        _csvdata[date] = rate;
    }

    return (true);
}

bool BitcoinExchange::isValidDateFormat(const std::string& dateStr) const
{
    const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
    {
        std::cerr << LIGHT_RED << "Error: Date format must be YYYY-MM-DD." << RESET_COLOR << std::endl;
        return false;
    }

    for (size_t i = 0; i < dateStr.length(); ++i)
    {
        if ((i == 4 || i == 7))
            continue;
        if (!isdigit(dateStr[i]))
        {
            std::cerr << LIGHT_RED << "Error: Date contains non-digit characters." << RESET_COLOR << std::endl;
            return false;
        }
    }
    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());
    if (year < 2009 || year > 2023) // Bitcoin started in 2009
    {
        std::cerr << LIGHT_RED << "Error: Year out of range [2009-2023]. Here year is :" << RESET_COLOR <<year<< std::endl;
        return false;
    }
    if (month < 1 || month > 12) {
        std::cerr << LIGHT_RED << "Error: Invalid month. Must be between 01 and 12. Here month is: " << RESET_COLOR<< month << std::endl;
        return false;
    }

    if (day < 1 || day > 31) {
        std::cerr << LIGHT_RED << "Error: Invalid day. Must be between 01 and 31. Here day is: " << RESET_COLOR<<day << std::endl;
        return false;
    }
    if (month == 2 && day == 29) //bissextile
    {
        if (!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) 
        {
            std::cerr << LIGHT_RED << "Error: This is not a leap year, this February 29 is invalid." << RESET_COLOR << std::endl;
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


float BitcoinExchange::getRateForDate(const std::string& dateStr) const
{
    std::map<std::string, float>::const_iterator it = _csvdata.lower_bound(dateStr);


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
        bool hasData = false;
        
        while (std::getline(input, line)) 
        {
            if (line == "date | value") 
                std::getline(input, line);
            if (line.empty()) continue;
            hasData = true;
            if (line.find('|') == std::string::npos) 
            {
                std::cerr << LIGHT_RED<< "Error: missing separator. " <<RESET_COLOR<< std::endl;
                std::cerr << "\tError: bad input \"" << line << "\""  << std::endl;
                continue;
            }
            if (std::count(line.begin(), line.end(), '|') != 1) 
            {
                std::cerr << LIGHT_RED<< "Error: too many separators. " <<RESET_COLOR<< std::endl;
                std::cerr << "\tError: bad input \"" << line << "\""  << std::endl;
                continue;
            }
            
            
    
            std::istringstream ss(line);
            std::string date, valueStr;
    
            if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) 
            {
                std::cerr <<LIGHT_RED<< "Error: no trace of date or value " <<RESET_COLOR<< std::endl;
                std::cerr << "\tError: bad input \"" << line << "\""  << std::endl;
                continue; 
            }
            // Trim spaces
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

            if (date.empty() || valueStr.empty())
            {
                if (date.empty())
                    std::cerr <<LIGHT_RED<< "Error: missing date " <<RESET_COLOR<< std::endl;
                else if (valueStr.empty())
                    std::cerr <<LIGHT_RED<< "Error: missing value " <<RESET_COLOR<< std::endl;
                std::cerr <<"\tError: bad input \"" << line << "\""  << std::endl;
                continue;
            }
            
    
         
    
            if (!isValidDateFormat(date)) 
            {
                std::cerr << "\tError: bad input date: \"" << date << "\""  << std::endl;
                continue;
            }
    
            float value = std::atof(valueStr.c_str());
            if (value > 1000) {
                std::cerr <<LIGHT_RED<< "Error: value too large." <<RESET_COLOR<<  std::endl;
                std::cerr<<"\tError: bad input \"" << value << "\""  << std::endl;
                continue;
            }
    
            if (!isPositiveNumber(valueStr)) {
                std::cerr <<LIGHT_RED<< "Error: value is not a positive number." <<RESET_COLOR<< std::endl;
                std::cerr<<"\tError: bad input value: \"" << value << "\""  << std::endl;
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
            if (!hasData) {
                std::cerr << LIGHT_RED << "Error: input file is empty or contains only header." << RESET_COLOR << std::endl;
            }
        }
        
    }

    bool BitcoinExchange::isPositiveNumber(const std::string& valueStr) 
    {
        std::istringstream iss(valueStr);
        float value;
        iss >> value;
        return !iss.fail() && value >= 0 && value <= 1000;
    }