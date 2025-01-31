// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ non-instanciable-> constructor private
//       ✩ one static method "convert"
//          ✩(std::string) -> char-int-float-double
//       ✩ 4 types: char, int, float, double à convertir
//       ✩ cas à gérer: nan, inf, -inf, char, int, float, doubles
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
        //    ✩  ---------   Argument      ---------
    	std::string _toConvert;

        //    ✩  ---------   Résultats     ---------
        long    _intResult;
        float   _floatResult;
        double  _doubleResult;
        char    _charResult;

        //    ✩  ---------   Flag des types    ---------
        bool	_isChar;
        bool	_isInt;
        bool	_isFloat;
        bool	_isDouble;

        //    ✩  ---------  Particularité     ---------
        bool	_hasPoint;
        bool	_hasSign;
        bool	_hasPlus
        bool	_hasF;
        bool	_isNanInf;

        //    ✩  ---------  Valid   ---------    
        bool	_isValid;

        //    ✩  ---------   Constructor    --------- 
        ScalarConverter();

    public:
        //    ✩  ---------   Destructor - Constructor with arg- Constructor copy      --------- 
        ~ScalarConverter();
        ScalarConverter(std::string src)
        ScalarConverter(ScalarConverter const & src);

        //    ✩  ---------   Operator      ---------
        ScalarConverter & operator=(ScalarConverter const & rhs);

        //    ✩  ---------   Fonctions membre principale     ---------
        static void convert(const std::string &ref);

        //    ✩  ---------   Getters      ---------
        char	getChar() const;
        int		getInt() const;
        float	getFloat() const;
        double	getDouble() const;

        bool	getValid() const;

        //.......................................................................................................
        //										   Détection-Conversion-Impression                              |
        //.......................................................................................................
        void	detectType(std::string src); //give a flag to the type
        void	checkInvalid(std::string src);
        void    selectType(std::string src); //prend le flag et redirige vers la conversion

        //    ✩  ---------   Fonctions convert     ---------
        void	SrcChar(std::string src);
        void	SrcInt(std::string src);
        void	SrcFloat(std::string src);
        void	SrcDouble(std::string src);
        //    ✩  ---------   Fonctions print    ---------
        void	printChar();
        void	printInt();
        void	printFloat();
        void	printDouble();
};
  
#endif