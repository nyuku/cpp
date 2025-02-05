// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ si a un point : float ou double
//       ✩ vérifié en dur si nan, inf, -inf, etc
//       ✩ (std::string) -> char-int-float-double
//       ✩ 4 types: char, int, float, double à convertir

//        ✩1  find() retourne la première occurrence du caractère.
//          rfind() retourne la dernière occurrence du caractère.
//          Si find() == rfind(), cela signifie que le caractère n'apparaît qu'une seule fois.
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝


#include "ScalarConverter.hpp"

//.......................................................................................................
//						Constructor - Destructor- Constructor with arg- Copy constructor                |
//                                          							                                |
//.......................................................................................................
 
    ScalarConverter::ScalarConverter():
            _toConvert(""),
            _charResult('0'),
            _intResult(0),
            _floatResult(0.0f),
            _doubleResult(0.0),
            _isChar(false),
            _isInt(false),
            _isFloat(false),
            _isDouble(false),
            _hasPoint(false),
            _hasSign(false),
            _hasF(false),
            _isNanInf(false),
            _isValid(true)
    {
        std::cout	<< "Constructor standard called" << std::endl;
    }

    ScalarConverter::~ScalarConverter()
    {
        // std::cout << "Destructor called" << std::endl;
    }
    
    ScalarConverter::ScalarConverter(std::string src):
            _toConvert(src),
            _charResult('0'),
            _intResult(0),
            _floatResult(0.0f),
            _doubleResult(0.0),
            _isChar(false),
            _isInt(false),
            _isFloat(false),
            _isDouble(false),
            _hasPoint(false),
            _hasSign(false),
            _hasF(false),
            _isNanInf(false),
            _isValid(false)
    {
        // std::cout	<< "Constructor wit argh called" << std::endl;
    }

    ScalarConverter::ScalarConverter(ScalarConverter const & src)
    {
        *this = src;
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
 
    ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &rhs)
        {
            this->_toConvert = rhs._toConvert;
            this->_charResult = rhs._charResult;
            this->_intResult = rhs._intResult;
            this->_floatResult = rhs._floatResult;
            this->_doubleResult = rhs._doubleResult;

            this->_isChar = rhs._isChar;
            this->_isInt = rhs._isInt;
            this->_isFloat = rhs._isFloat;
            this->_isDouble = rhs._isDouble;

            this->_hasPoint = rhs._hasPoint;
            this->_hasSign = rhs._hasSign;
            this->_hasF = rhs._hasF;
            this->_isNanInf = rhs._isNanInf;

            this->_isValid = rhs._isValid;
        }
        return *this;
    }

//.......................................................................................................
//										   Getters                                                      |
//.......................................................................................................
    
    char ScalarConverter::getChar() const 
    {
        return _charResult;
    }

    int ScalarConverter::getInt() const 
    {
        return _intResult;
    }

    float ScalarConverter::getFloat() const 
    {
        return _floatResult;
    }

    double ScalarConverter::getDouble() const 
    {
        return _doubleResult;
    }

    bool ScalarConverter::getValid() const 
    {
        return _isValid;
    }

//.......................................................................................................
//								  Méthodes de conversion individuelles
//                                cast simple pour tous les types sauf lui-même							|
//.......................................................................................................

    void ScalarConverter::SrcChar(std::string src) 
    {
        _charResult = static_cast<char>(std::atoi(src.c_str()));
    }

    void ScalarConverter::SrcInt(std::string src) 
    {
        _intResult = static_cast<int>(std::strtol(src.c_str(), NULL, 10));
    }

    void ScalarConverter::SrcFloat(std::string src) 
    {
        _floatResult = static_cast<float>(std::strtof(src.c_str(), NULL));
    }

    void ScalarConverter::SrcDouble(std::string src) 
    {
        _doubleResult = static_cast<double>(std::strtod(src.c_str(), NULL));
    }

//.......................................................................................................
//								  Méthodes de conversions générales
//                                Détection-déviation - Conversion							             |
//.......................................................................................................

void   ScalarConverter::convert(const std::string &src)
{
    if (src.empty())
    {
        std::cout << "ERROR: Empty entries" << std::endl;
        return;
    }
    ScalarConverter cast(src); // cree l'objet
    cast.detectType(src);
    cast.selectType(src);
    cast.printAll();
}

void    ScalarConverter::detectType(std::string src) 
{
    if (src == "nan" || src == "nanf" || src == "+inf" || src == "-inf" || src == "+inff" || src == "-inff")
       nanInf(src);
    initFlags(src);
    checkSign();
    checkFloatDouble();
    checkChar(src);
    checkInt(src);
}


void ScalarConverter::selectType(std::string src)
{
    if( !(_isNanInf) && !(_isValid))
    {
        std::cout << "Invalid data." << std::endl;
        return;
    }
    bool flags[4] = {_isChar, _isInt, _isFloat, _isDouble};

    convertByType(src);
    
    // 2eme partie, print les autres cast
    void (ScalarConverter::*conversions[4])(std::string) = 
    {
        &ScalarConverter::SrcChar,
        &ScalarConverter::SrcInt,
        &ScalarConverter::SrcFloat,
        &ScalarConverter::SrcDouble
    };
    int i = 0, j = 0;
    const char* flagNames[4] = {"_isChar", "_isInt", "_isFloat", "_isDouble"};
    while (j < 3 || i < 4)
    {
        if (flags[i])
        {
            std::cout <<LIGHT_MAGENTA<<"\nType: "<<RESET_COLOR<<flagNames[i];
            if (_hasPlus== true || _hasSign == true)
                std::cout << ", with sign";
            if (_isNanInf )
                std::cout << ", pseudo literals";
            std::cout << ENDL;
        }
        if (!flags[i]) //On évite de caster le type détecté
        {
            (this->*conversions[i])(src);
            j++; 
        }
        i++;
    }
}

//.......................................................................................................
//								  Méthodes de conversions utils
//                                Gestion des plus cas particuliers										|
//.......................................................................................................

    // va juste faire le cast selon le type et stocker dans la variable
    void ScalarConverter::convertByType(std::string src) 
    {
        // fonction attende un C-string (const char*)
        if (_isChar) 
            _charResult = src[0];
        else if (_isInt) 
            _intResult = std::atol(src.c_str());
        else if (_isFloat)
            _floatResult = std::atof(src.c_str());
        else if (_isDouble)
            _doubleResult = std::strtod(src.c_str(), NULL);
    }
    void    ScalarConverter::nanInf(std::string src)
    {
        _isNanInf = true;
        if (src == "nanf" || src == "-inff" || src == "+inff")
            _isFloat = true;
        else
            _isDouble = true;
    }

    void ScalarConverter::initFlags(std::string src) // ✩1
  
    {
        _hasSign = ((src.find('-') != std::string::npos) && (src.find('-') == src.rfind('-') && src.find('-') == 0));
        _hasPlus = ((src.find('+') != std::string::npos) && (src.find('+') == src.rfind('+') && src.find('+') == 0));
        _hasPoint = ((src.find('.') != std::string::npos) && (src.find('.') == src.rfind('.')));
        _hasF = (!src.empty() && src.back() == 'f' && src.find('f') == src.rfind('f'));
    }

    void ScalarConverter::checkSign()
    {
        if (_hasPlus == true && _hasSign == true) 
        {
            _isValid = false;
            std::cout << "ERROR: to much" << std::endl;
            return;
        }
    }

    void ScalarConverter::checkFloatDouble()
    {
        if (_hasPoint) 
        {
            if (_hasF) 
            {
                _isFloat = true;  
                _isValid = true;
            }
            else
            {
                _isDouble = true;
                _isValid = true;
            }
        }
    }

    void ScalarConverter::checkChar(std::string src)
    {
        if (src.length() == 1 && !std::isdigit(src[0])) 
        {
            _isChar = true;  
            _isValid = true;
        }
    }

    void ScalarConverter::checkInt(std::string src)
    {
        if (!src.empty() && (std::isdigit(src[0]) || (_hasPlus== true || _hasSign == true)))
        {
            if(src.size() == 1 && (_hasPlus== true || _hasSign == true))
                return;
            for (std::size_t i = 1; i < src.size(); ++i) //on decale de 1 car deja check le src[0]
            {
                if (!std::isdigit(src[i]))
                {
                    return;
                }
            }
            _isInt = true;  
            _isValid = true;
        }
    }

//.......................................................................................................
//								         Print des types                                                |
//.......................................................................................................
   
    void	ScalarConverter::printAll()
    {
        if(!(_isNanInf) && !(_isValid) )
            return;
        printChar();
        printInt();
        printFloat();
        printDouble();
    }

    void	ScalarConverter::printChar()
    {
        int	i = static_cast<int>(_charResult);

        std::cout	<<CYAN<< "\n▶ char:    "<< RESET_COLOR;
        if (i < 127 && i >= 32)
            std::cout	<< "'" << _charResult << "'" << std::endl;
        else if (_isNanInf)
            std::cout << "impossible" << std::endl;
        else
            std::cout	<< "not displayable" << std::endl;
    }

    void	ScalarConverter::printInt()
    {
        std::cout	<<BLUE<< "▶ int:     "<< RESET_COLOR;
        if (_isNanInf)
            std::cout << "impossible" << std::endl;
        else
            std::cout << _intResult << std::endl;
    }

    void	ScalarConverter::printFloat()
    {
        std::cout	<<CYAN<< "▶ float:   "<< RESET_COLOR;
        std::cout << std::fixed << std::setprecision(1) << _floatResult << "f" << std::endl;
    }

    void	ScalarConverter::printDouble()
    {
        std::cout	<<BLUE<< "▶ double:  "<<RESET_COLOR;
        std::cout << std::fixed << std::setprecision(1) << _doubleResult <<"\n"<< std::endl;
    }

//............................................. TEST ..........................................................
    // 	std::cout << "--- BOOL TESTS ---" << std::endl;
	// std::cout << "point:   " << _hasPoint << std::endl;
	// std::cout << "sign:    " << _hasSign << std::endl;
	// std::cout << "f:       " << _hasF << std::endl;
	// std::cout << "isChar:  " << _isChar <<std::endl;
	// std::cout << "isInt:   " << _isInt <<std::endl;
	// std::cout << "ifFlt:   " << _isFloat <<std::endl;
	// std::cout << "isDble:  " << _isDouble <<std::endl;
	// std::cout << "isNanIn: " << _isDouble <<std::endl;
	// std::cout << "isValid: " << _isValid <<std::endl;
	// std::cout << std::endl;
