// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
//       ✩ 
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "RPN.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      Défini d'office un grade, nom	    							|
//.......................................................................................................
    RPN::RPN() {}
    RPN::~RPN() {}
//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    RPN& RPN::operator=(const RPN& other)
    {
        if (this != &other)
            this->_stack = other._stack;
        return *this;
    }

//.......................................................................................................
//										 Copy Constructors                                               |
//.......................................................................................................
    RPN::RPN(const RPN &other) 
    {
        this->_stack = other._stack;
    }


//=======================================================================================================
//										   Fonctions utils											|
//=======================================================================================================
    void RPN::addStack(int a)
    {
        _stack.push(a);
    }

    void RPN::calculus(char op)
    {
        if (_stack.size() < 2) 
            throw std::runtime_error(LIGHT_RED"Error: not enough operands"RESET_COLOR);
        int a = _stack.top();
        _stack.pop();
        int b = _stack.top();
        _stack.pop();
        switch (op)
        {
            case '+':
                _stack.push(a + b);
                break;
            case '-':
                _stack.push(b - a);
                break;
            case '*':
                _stack.push(b * a);
                break;
            case '/':
                if (a == 0)
                    throw std::runtime_error(LIGHT_RED"Error: integer division by zero"RESET_COLOR);
                _stack.push(b / a);
                break;
            default:
                throw std::runtime_error(LIGHT_RED"Error: Unknown operator"RESET_COLOR);
        }
    }
    bool RPN::isOperator(const std::string& token) const
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
            return true;
        else if (token.length() == 1 )
        {
            std::cerr << LIGHT_RED << "Error: Unknown operator : " <<RESET_COLOR<< token << RESET_COLOR << std::endl;
            return false;
        }
        if (token.length() > 1 && std::isdigit(token[1]))
        {
            // Affiche seulement le premier caractère du token
            std::cerr << LIGHT_RED << "Error: Unknown operator : " << RESET_COLOR << token[0] << RESET_COLOR << std::endl;
        }
        else
        {
            // Sinon affiche tout le token
            std::cerr << LIGHT_RED << "Error: Unknown operator : " << RESET_COLOR << token << RESET_COLOR << std::endl;
        }
        return false;
    }
    bool RPN::isNumber(const std::string& token) const
    {
        if (token.length() == 1 && std::isdigit(token[0]))
            return true;
    
        else if (token.length() >= 2 && token[0] == '-') //negatif
        {
            for (size_t i = 1; i < token.size(); ++i) 
            {
                if (!std::isdigit(token[i]))  // Pas un chiffre = invalide
                    return false;
            }
            std::cerr << LIGHT_RED << "Error: negative number : " << RESET_COLOR<< token  << std::endl;
            std::exit(EXIT_FAILURE);  // Termine proprement le programme
        }
        else if(token.length() >=2 && std::isdigit(token[0]))//nb > 9
        {
            for (size_t i = 1; i < token.size(); ++i) 
            {
                if (!std::isdigit(token[i]))  // Pas un chiffre = invalide
                    return false;
            }
            std::cerr << LIGHT_RED << "Error: number is bigger than [0-9] : " <<RESET_COLOR<< token << std::endl;
            std::exit(EXIT_FAILURE);  // Termine proprement le programme
        }
        return false;
    }


//=======================================================================================================
//										   Fonction process												|
//=======================================================================================================
    bool RPN::reversePolishNotation(const std::string& expression, int &result)
    {
        std::istringstream iss(expression);// ne lit pas encore
        std::string token;// on a pas encore parser, ca peut etre -42, abc etc
        int operatorCount = 0;
        int numberCount = 0;
        while (iss >> token) //injecte a token et lit le mot
        {
            if (isNumber(token)) 
            {
                addStack(std::stoi(token));
                numberCount++;
            } 
            else if (isOperator(token)) 
            {
                operatorCount++;
                try 
                {
                    calculus(token[0]);
                } 
                catch (const std::exception& e) 
                {
                    std::cerr << e.what() << std::endl;
                    return false;
                }
            } 
            else 
            {
                std::cerr << LIGHT_RED"Error: Invalid token : "RESET_COLOR<< expression<<LIGHT_RED << " should be something like \"3 4+ 5-\" with number between [0-9] and [+-*/]"<<RESET_COLOR<< std::endl;
                return false;
            }
        }
        if (_stack.size() != 1) //si bien fait, doit rester que 1 resultat
        {
            std::cerr << LIGHT_RED"Error: Invalid expression, should respect Nb = Op + 1 : "RESET_COLOR<< expression<< std::endl;
            return false;
        }
        if (numberCount < 2)
        {
            std::cerr <<LIGHT_RED<< "Error: Not enough numbers for a valid RPN : " <<RESET_COLOR<< expression<< std::endl;
            return false;
        }
        if (operatorCount != numberCount - 1)
        {
            std::cerr <<LIGHT_RED<< "Error: Number of operators must be exactly one less than numbers : "<<RESET_COLOR<< expression << std::endl;
            return false;
        }
        else
            result = _stack.top();
        return true;
    }