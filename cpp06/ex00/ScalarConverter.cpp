// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ si a un point : float ou double
//       ✩ vérifié en dur si nan, inf, -inf
//       ✩(std::string) -> char-int-float-double
//       ✩ 4 types: char, int, float, double à convertir
//       ✩ cas à gérer: nan, inf, -inf, char, int, float, doubles
//       ✩ float
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝


#include "ScalarConverter.hpp"

//.......................................................................................................
//										Constructor - Destructor- Constructor with arg
//                                          							|
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
    std::cout << "Destructor called" << std::endl;
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
     std::cout	<< "Constructor wit argh called" << std::endl;
}
//.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................


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
//										   Getters
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
//										    Méthodes 
//                              Détection-Conversion-Impression 													|
//.......................................................................................................
 
void ScalarConverter::detectType(std::string src) 
{
// Initialisation des flags, pré-tri.check si 1x
// find() retourne la première occurrence du caractère.
// rfind() retourne la dernière occurrence du caractère.
// Si find() == rfind(), cela signifie que le caractère n'apparaît qu'une seule fois.
//(src.find('-') != std::string::npos) => not found. pos = pas trouvé
//if find == rfind = 1seul occurence

    
       //verifie en dur les cas particuliers nan, inf, inff
    if (src == "nan" || src == "nanf" || src == "+inf" || src == "-inf" || src == "+inff" || src == "-inff") {
        //exepction a lancer
        _isNanInf = true;
        _isValid = true;  // C'est un cas valide
        return;
    }
    //check s'il y a une signe '-'/'.'/'f' dans la string. +- que au debut
    _hasSign = ((src.find('-') != std::string::npos) && (src.find('-') == src.rfind('-') && src.find('-') == 0));
    _hasPlus = ((src.find('+') != std::string::npos) && (src.find('+') == src.rfind('+') && src.find('+') == 0));
    _hasPoint = ((src.find('.') != std::string::npos) && (src.find('.') == src.rfind('.')));
    _hasF = (!src.empty() && src.back() == 'f' && src.find('f') == src.rfind('f'));//float

    if (_hasPlus==true && _hasSign == true) 
    {
        _isValid = false;
        return;
    }
 
    //vérifie si "." -> float ou double
    if (_hasPoint) 
    {
        if (_hasF) 
        { // Vérifie que 'f' est bien à la fin
            _isFloat = true;  
            _isValid = true;
        }
        else //if (!_hasF) 
        { // Si pas de 'f', alors c'est un double
            _isDouble = true;
            _isValid = true;
        }
    }

        //si un seul character = char
    else if (src.length() == 1 && !std::isdigit(src[0])) 
    {
            _isChar = true;  
            _isValid = true;
    }
    //check chiffre +42, -42, 42 !! +42 +-42
    else if (!src.empty() && src.size() > 1 && (std::isdigit(src[0]) || (_hasPlus== true || _hasSign == true)))
    {
       for (std::size_t i = 1; i < src.size(); ++i) //on decale de 1
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
