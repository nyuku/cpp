// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ non-instanciable-> constructors private
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
# include <iomanip>

#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define BLUE      "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m"
#define MAGENTA		  	"\033[0;35m"
#define LILAC		   	"\033[0;94m"
#define LIGHT_BLUE		   	"\033[0;34m"
#define LIGHT_TURCOI    "\033[0;36m"
#define LIGHT_RED	  	"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE	    "\033[0;94m"
#define PEACH		    "\033[0;93m"
#define LIGHT_CYAN      "\033[0;36m"
#define BOLD		    "\033[1m"
#define ENDL            std::endl

enum Type { CHAR, INT, FLOAT, DOUBLE };

class ScalarConverter
{
    private:

        //    ✩  ---------   Constructor    --------- 
        ScalarConverter();
        ScalarConverter(const std::string & src);
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        //    ✩  ---------   Argument      ---------
        std::string _toConvert;

        //    ✩  ---------   Résultats     ---------
        char    _charResult;
        long    _intResult;
        float   _floatResult;
        double  _doubleResult;
        

        //    ✩  ---------   Flag des types    ---------
        bool	_isChar;
        bool	_isInt;
        bool	_isFloat;
        bool	_isDouble;

        //    ✩  ---------  Particularité     ---------
        bool	_hasPoint;
        bool	_hasSign;
        bool	_hasPlus;
        bool	_hasF;
        bool	_isNanInf;
        bool    _nonDigit;

        //    ✩  ---------  Valid   ---------    
        bool	_isValid;


    public:
        //    ✩  ---------   Destructor - Constructor with arg- Constructor copy      --------- 
        ~ScalarConverter();
  

        //    ✩  ---------   Operator      ---------
        //non-nstanciable 

        //    ✩  ---------   Fonctions membre principale     ---------
        static void convert(const std::string &src);

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
        void    selectType(std::string src); //prend le flag et redirige vers la conversion


        void    convertByType(std::string src);

        void    nanInf(std::string src);
        void    initFlags(std::string src);
        void    checkDigit(std::string src);
        void    checkSign();
        void    checkFloatDouble();
        void    checkChar(std::string src);
        void    checkInt(std::string src);

        //    ✩  ---------   Fonctions convert     ---------
        void	SrcInt(std::string src);
        void	SrcFloat(std::string src);
        void	SrcDouble(std::string src);
        void    explicitConversion(int type);   
        //    ✩  ---------   Fonctions print    ---------
        void    printAll();
        void	printChar();
        void	printInt();
        void	printFloat();
        void	printDouble();
};
  
#endif