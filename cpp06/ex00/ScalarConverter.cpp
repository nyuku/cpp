// ╔────────────────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────────────────╗
//       ✩ 4 types: char, int, float, double à convertir
//       ✩ Entrée en string ->  1 )reconnaitre le type              ex : "p"
//                              2) convertir la string en type reconnu : 'p' = char
//                              3) convertir le char en int, float, double   et print le type reconnu      
// 		 ✩ Choisir un seul type de cast: ici static_cast (autre possible reinterpret_cast(pointeur), dynamic_cast(poly), const_cast)
//          les autres gerent des pointeurs, objet const et polymorphisme
//
//       Analyse: 
//		 ✩ si a un point '.' : float ou double
//       ✩ vérifié en dur si "nan, inf, -inf, etc"
//       ✩ inf/nan -> c'est un double ou float a convertir
//       ✩ (std::string) -> char-int-float-double
//
//       Note:
//        ✩1  find() retourne la première occurrence du caractère.
//          rfind() retourne la dernière occurrence du caractère.
//          Si find() == rfind(), cela signifie que le caractère n'apparaît qu'une seule fois.
//         strsof gere les chiffres geants et nan/inf
//         strtod moins fiable pour nan, rajouter secu
//
//       Process:
//        ✩   detect type -> convert str by the type-> type (strtol,strtol,etc)->static_cast remaining type ->print 

//       ! \ et , sont des caractères spéciaux en C++ et doivent être échappés avec un autre \.
//       ! Les caractères spéciaux sont les suivants : \0, \a, \b, \f, \n, \r, \t, \v.
// ╚────────────────────────────────────────────────────────────────¤◎¤────────────────────────────────────────────────────────────────╝


#include "ScalarConverter.hpp"

//.......................................................................................................
//						Constructor - Destructor- Constructor with arg- Copy constructor                |
//                                          							                                |
//.......................................................................................................
 
    ScalarConverter::ScalarConverter():
            _toConvert(""),
            _escape(""),
            _charResult('0'),
            _intResult(0),
            _floatResult(0.0f),
            _doubleResult(0.0),
            _isChar(false),
            _isInt(false),
            _isFloat(false),
            _isDouble(false),
            _isLong(false),
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
    
    ScalarConverter::ScalarConverter(const std::string & src):
            _toConvert(src),
            _escape(""),
            _charResult('0'),
            _intResult(0),
            _floatResult(0.0f),
            _doubleResult(0.0),
            _isChar(false),
            _isInt(false),
            _isFloat(false),
            _isDouble(false),
            _isLong(false),
            _hasPoint(false),
            _hasSign(false),
            _hasF(false),
            _isNanInf(false),
            _isValid(false)
    {
        // std::cout	<< "Constructor wit argh called" << std::endl;
    }

    ScalarConverter::ScalarConverter( const ScalarConverter & src):             _toConvert(src._toConvert),
                                                                                _charResult(src._charResult),
                                                                                _intResult(src._intResult),
                                                                                _floatResult(src._floatResult),
                                                                                _doubleResult(src._doubleResult),
                                                                                _isChar(src._isChar),
                                                                                _isInt(src._isInt),
                                                                                _isFloat(src._isFloat),
                                                                                _isDouble(src._isDouble),
                                                                                _isLong(src._isLong),
                                                                                _hasPoint(src._hasPoint),
                                                                                _hasSign(src._hasSign),
                                                                                _hasF(src._hasF),
                                                                                _isNanInf(src._isNanInf),
                                                                                _isValid(src._isValid)
    {}
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
            this->_escape = rhs._escape;
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
//								  1)Méthodes de conversions générales
//                                Détection-déviation - Conversion							             |
//.......................................................................................................

    void   ScalarConverter::convert(const std::string &src)
    {
        if (src.empty())
        {
            std::cout << "ERROR: Empty entries" << std::endl;
            return;
        }
        ScalarConverter cast(src);
        cast.detectType(src);
        cast.selectType(src);
        if (cast._isNanInf)
            cast.printAll(src);
        else
            cast.printAll();
        std::cout <<std::endl;
    }

    void    ScalarConverter::detectType(std::string src) 
    {
        if (src == "nan" || src == "nanf" || src == "inf" ||src == "+inf" || src == "-inf" || src == "inff" ||src == "+inff" || src == "-inff")
            nanInf(src);
        initFlags(src);
        checkDigit(src);
        checkSign();
        checkFloatDouble();
        checkChar(src);
        checkInt(src);
    }

    void ScalarConverter::selectType(std::string src)
    {
        bool flags[4]            = {_isChar, _isInt, _isFloat, _isDouble};
        const char* flagNames[4] = {"Char", "Int", "Float", "Double"};

        if (!(_isNanInf) && !(_isValid) && !(_isLong))
        {
            std::cout <<LIGHT_RED<< "ERROR: Invalid data.\n" <<RESET_COLOR<< std::endl;
            return;
        }
        convertByType(src);
        int i = 0;
       
        while (i < 4)
        {
            if (flags[i])
            {
                std::cout <<LIGHT_MAGENTA<<"\nType: "<<RESET_COLOR<<flagNames[i];
                if (_hasPlus== true || _hasSign == true)
                    std::cout << ", with sign";
                if (_isNanInf )
                    std::cout << ", pseudo literals";
                std::cout << ENDL;
                break;
            }
            i++;
        }
        explicitConversion(i);
    }

    void ScalarConverter::convertByType(std::string src) 
    {
        if (_isChar) 
        {
            if(_charResult == '0') 
                _charResult = src[0]; // si Echappement \t, \n, etc
        }
        else if (_isInt) 
            SrcInt(src);
        else if (_isFloat)
            SrcFloat(src);
        else if (_isDouble)
            SrcDouble(src);
    }

    void ScalarConverter::explicitConversion(int type)
    {
        switch(type)
        {
            case(CHAR):
                this->_intResult = static_cast<int>(this->_charResult);
                this->_floatResult = static_cast<float>(this->_charResult);
                this->_doubleResult = static_cast<double>(this->_charResult);
                break;
            case(INT):
                this->_floatResult = static_cast<float>(this->_intResult);
                this->_charResult = static_cast<char>(this->_intResult);
                this->_doubleResult =  static_cast<double>(this->_intResult);
                break;
            case(FLOAT):
                this->_intResult = static_cast<int>(this->_floatResult);
                this->_doubleResult = static_cast<double>(this->_floatResult);
                this->_charResult = static_cast<char>(this->_intResult);// converti en entier->char
                break;
            case(DOUBLE):
                this->_intResult =  static_cast<int>(this->_doubleResult);
                this->_floatResult = static_cast<float>(this->_doubleResult);
                this->_charResult = static_cast<char>(this->_intResult);// converti en entier->char
                break;//patate pas sur
            default:
                break;
        }
    }


//.......................................................................................................
//								  2) Méthodes de conversion individuelles
//                                  argv[1] -> type reconnu                    							|
//.......................................................................................................

    void ScalarConverter::SrcInt(std::string src) 
    {
        _intResult = (strtol(src.c_str(), NULL, 10));
    }

    void ScalarConverter::SrcFloat(std::string src) 
    {
        _floatResult = (strtof(src.c_str(), NULL));
    }

    void ScalarConverter::SrcDouble(std::string src) 
    {
        _doubleResult = static_cast<double>(std::strtod(src.c_str(), NULL));
    }

//.......................................................................................................
//								  Méthodes de conversions utils
//                                Gestion des plus cas particuliers										|
//.......................................................................................................

    void    ScalarConverter::nanInf(std::string src)
    {
        _isNanInf = true;
        if (src == "nanf" || src == "-inff" || src == "+inff" || src == "inff" )
            _isFloat = true;
        else
            _isDouble = true;
    }

    void ScalarConverter::initFlags(std::string src) // ✩1
    {
        _hasSign = ((src.find('-') != std::string::npos) && (src.find('-') == src.rfind('-') && (src.find('-') == 0 || src.find('-') == 1)));
        _hasPlus = ((src.find('+') != std::string::npos) && (src.find('+') == src.rfind('+') && (src.find('+') == 0 || src.find('+') == 1)));
        _hasPoint = ((src.find('.') != std::string::npos) && (src.find('.') == src.rfind('.')) && src.find('.')!= 0);// si pas .67
        _hasF = (!src.empty() && (src.back() == 'f' || src.back() == 'F') &&
        (src.find('f') == src.rfind('f') || src.find('F') == src.rfind('F')));
    }

     void ScalarConverter::checkDigit(std::string src)// check si poin?
    {
        int iteratorF = 0;
        int iteratorP = 0;
        int iteratorU = 0;
        if(_hasPoint)
        { 
            for (std::string::size_type  i = 0; i < src.length(); ++i) 
            {
                if (src[i] == 'F' || src[i] == 'f')
                    iteratorF++;
                if (src[i] == '.')
                    iteratorP++;
                if (src[i] == '-')
                    iteratorU++;

                if (!std::isdigit(static_cast<unsigned char>(src[i])) && src[i] != 'F' && src[i] != 'f' && src[i] != '.' && src[i] != '-'&& src[i] != '+') 
                {
                    _isValid = false;
                    return;
                }
            }
            if(iteratorF > 1 || iteratorP > 1 || iteratorU > 1)
                _isValid = false;
            else
                _isValid = true;
        }
    }
    
    void ScalarConverter::checkSign()
    {

        if (_hasPlus == true && _hasSign == true) 
        {
            _isValid = false;
            std::cout << "ERROR: to much sign" << std::endl;
            return;
        }
    }

    void ScalarConverter::checkFloatDouble()
    {
        if (_hasPoint && _isValid) 
        {
            if (_hasF) 
            {
                _isFloat = true;  
            }
            else
            {
                _isDouble = true;
            }
        }
    }

    void ScalarConverter::checkChar(std::string src)
    {
        if (src[0] == '\\' && src.length() == 2 )
        {
            checkEscape(src);
            _isChar = true;  
            _isValid = true;
            return;
        }
        else if (src.length() == 1 && std::isprint(src[0]) && !std::isdigit(src[0])) 
        {

            _isChar = true;  
            _isValid = true;
        }
    }

    void    ScalarConverter::checkEscape(std::string src)
    {
        if (src == "\\0") 
        {
            _charResult = '\0';
            _escape = "Null character (NUL)";
        }
        else if (src == "\\a") 
        {
            _charResult = '\a';
            _escape = "Alert (BEL)";
        }
        else if (src == "\\b") 
        {
            _charResult = '\b';
            _escape = "Backspace (BS)";
        }
        else if (src == "\\f") 
        {
            _charResult = '\f';
            _escape = "Form feed (FF)";
        }
        else if (src == "\\n") 
        {
            _charResult = '\n';
            _escape = "Newline (LF)";
        }
        else if (src == "\\r") 
        {
            _charResult = '\r';
            _escape = "Carriage return (CR)";
        }
        else if (src == "\\t") 
        {
            _charResult = '\t';
            _escape = "Horizontal tab (TAB)";
        }
        else if (src == "\\v") 
        {
            _charResult = '\v';
            _escape = "Vertical tab (VT)";
        }
        else 
        {
            _isValid = false;
            return;
        }
    }

    void ScalarConverter::checkInt(std::string src) //e nettoyer
    {
        if (!src.empty() && (std::isdigit(src[0]) || _hasPlus || _hasSign)) 
        {
            if (src.size() == 1 && (_hasPlus || _hasSign))
                return;

            for (std::size_t i = 1; i < src.size(); ++i) 
            {
                if (!std::isdigit(src[i]))
                    return;
            }
            long long value = std::strtoll(src.c_str(), NULL, 10);
            //poru chifre geant
            if ( value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) 
            {
                this->_charResult =  value;
                SrcInt(src);

                // printChar();
                // printInt();
                // printFloat(src);
                // printDouble(src);
                _isNanInf = true; // pas sur
                printAll(src);

                _isValid = false;  // On empêche tout autre traitement
                _isLong = true;
                return;
            }
            
            _isInt = true;  
            _isValid = true;
            _intResult = static_cast<int>(value);
        }
    }

//.......................................................................................................
//								         Print des types                                                |
//.......................................................................................................
   
    void	ScalarConverter::printAll(std::string src)
    {
        if((!(_isNanInf) && !(_isValid)) || (_isLong))
            return;
        printChar();
        printInt();
        if (!src.empty() || _isNanInf)
        {  
            printFloat(src);
            printDouble(src);
        }
        else
        {
            printFloat();
            printDouble();
        }
    }

   void ScalarConverter::printChar()
   {
        std::cout << CYAN << "\n▶ char:   " << RESET_COLOR;
        if (_isNanInf)
            std::cout << " impossible" << std::endl;
        else if (!isprint(_charResult) || _isLong)
        { 
            std::cout << " not displayable ";
            if(_escape != "")
                std::cout << "   ▶ ascii:" << _escape;
            std::cout << std::endl;
        }
        else if (_charResultStr.empty())
            std::cout << "'" << _charResult << "'" << std::endl;
        else
            std::cout << _charResultStr << std::endl;
    }

    void ScalarConverter::printInt()
    {
        std::cout << BLUE << "▶ int:     " << RESET_COLOR;
        if (_isLong || _isNanInf || _intResult < std::numeric_limits<int>::min() || _intResult > std::numeric_limits<int>::max())
            std::cout << "impossible" << std::endl;
        else
            std::cout << _intResult << std::endl;
    }

    void ScalarConverter::printFloat(std::string src)
    {
        std::cout << CYAN << "▶ float:   " << RESET_COLOR;
        float value;
        if (src.empty())
        {
            value =  _floatResult;
        }
        else
        {
            value = std::strtof(src.c_str(), NULL);
            // if (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity())
            // {
            //     std::cout << (value > 0 ? "+inf" : "-inf") << "f" << std::endl;
            //     return;
            // }
            if (std::isinf(value))
            {
                if (value > 0)
                    std::cout << "+inf";
                else
                    std::cout << "-inf";

                std::cout << "f" << std::endl;
                return;
            }
        }
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    }

    void ScalarConverter::printDouble(std::string src)
    {
        std::cout << BLUE << "▶ double:  " << RESET_COLOR;
        double result;

        if (src.empty()) 
        {
            result = _doubleResult;
        } 
        else
        {
            result = std::strtod(src.c_str(), NULL);
            if (std::isnan(result)) 
            {
                std::cout << "nan" << std::endl;
                return;
            }
            else if (std::isinf(result))
            {
                if (result > 0)
                    std::cout << "+inf" << std::endl;
                else
                    std::cout << "-inf" << std::endl;

                return;
            }
            // else if (result > std::numeric_limits<double>::max() || result < -std::numeric_limits<double>::max())
            // {
            //     std::cout << "+inf" << std::endl;
            //     return;
            // }
        }
    std::cout << std::fixed << std::setprecision(1) << result << std::endl;
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
