
//parser le fichier inpuit
//verifier si le fichier est ouvert
//verifier si le fichier est vide
//verifier si le fichier est valide
//verifier si le fichier est bien formé
//
#include "BitcoinExchange.hpp"

bool isPositiveNumber(const std::string& valueStr) {
    std::istringstream iss(valueStr);
    float value;
    iss >> value;
    return !iss.fail() && value >= 0 && value <= 1000;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    if (!btc.loadDatabase("data.csv")) {
        std::cerr << "Error: failed to load data.csv" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(input, line); // Skip header line

    while (std::getline(input, line)) {
        if (line.empty())
            continue;

        std::istringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim spaces
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        if (!btc.isValidDateFormat(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value = std::atof(valueStr.c_str());
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        if (!isPositiveNumber(valueStr)) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }



        try {
            float rate = btc.getRateForDate(date);
            float result = rate * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
