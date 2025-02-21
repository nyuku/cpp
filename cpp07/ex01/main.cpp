
#include "iter.hpp"

//=======================================================================================================
//										   Fonctions test										    	|
//=======================================================================================================
#include <cctype> // Pour std::toupper
#include <cmath> // Pour std::round
//----int
void printInt(int x) 
{
    std::cout << x << " ";
}
void plusTwo(int &x) 
{
    x += 2;
}
//----string - char
void printString(std::string s) 
{
    std::cout << s << " ";
}
void toUppercase(char &c) 
{
    c = std::toupper(c); // Utilise la fonction standard C++
}
void InvertBool(bool &b) 
{
    b = !b;
}
//----double
void roundValue(double &x) {
    x = std::round(x); // Arrondit au nombre entier le plus proche
}
//----float
void squareFloat(float &x) 
{
    x = x * x;
}
//=======================================================================================================
//										   Fonctions print tab										    |
//=======================================================================================================
template <typename T>
void printArray(T *array, size_t length) 
{
    if (!array) return;

    std::cout << "[ ";
    for (size_t i = 0; i < length; i++) {
        std::cout << array[i]; 
        if (i < length - 1) std::cout << ", "; 
    }
    std::cout << " ]" << std::endl;
}


//=======================================================================================================
//										   Main									                	    |
//=======================================================================================================

int main() 
{
    std::cout <<LILAC<< "\n==================== Test with int - Print ====================" <<RESET_COLOR<< std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        std::cout << "Array of int: \t\t\t";
        iter(arr, 5, printInt);
        std::cout << std::endl;

    std::cout <<LILAC<< "\n==================== Test with str - Print ====================" <<RESET_COLOR<< std::endl;
        std::string strArr[] = {"Hello", "World", "Template"};
        std::cout << "Array of strings: \t\t";
        iter(strArr, 3, printString);
        std::cout << std::endl;

    std::cout <<LILAC<< "\n==================== Test with int - PlusTwo ====================" <<RESET_COLOR<< std::endl;
        
        int tab[] ={10, 20, 30, 40, 50, 60};
        std::cout << "Array of int, before: \t\t";
        printArray(tab, 6);
        iter(tab, 6, plusTwo);
        std::cout << "Array of int, after: \t\t";
        printArray(tab, 6);
    
    std::cout <<LILAC<< "\n==================== Test with char - toUppercase ====================" <<RESET_COLOR<< std::endl;
        char c[] = "hello";
        std::cout << "Array of char, before: \t\t" << c << std::endl;
        iter(c, 5, toUppercase);
        std::cout << "Array of char, after: \t\t" << c << std::endl;

    std::cout <<LILAC<< "\n==================== Test with bool - InvertBool ====================" <<RESET_COLOR<< std::endl;
        bool boolArr[] = {true, true, true, false};
        std::cout << "Array of bool, before: \t\t";
        printArray(boolArr, 4);

        iter(boolArr, 4, InvertBool);
        std::cout << "Array of bool, after: \t\t";
        printArray(boolArr, 4);
        std::cout << std::endl;

    std::cout <<LILAC<< "\n==================== Test with double - roundValue ====================" <<RESET_COLOR<< std::endl;
        double doubleArr[] = {3.7, 4.9, 5.1};
        std::cout << "Array of double, before: \t";
        printArray(doubleArr, 3);

        iter(doubleArr, 3, roundValue);
        std::cout << "Array of double, after: \t";
        printArray(doubleArr, 3);
        std::cout << std::endl;

    std::cout <<LILAC<< "\n==================== Test with float - squareFloat ====================" <<RESET_COLOR<< std::endl;
        float floatArr[] = {1.1, 2.2};
        std::cout << "Array of float, before: \t";
        printArray(floatArr, 2);

        iter(floatArr, 2, squareFloat);
        std::cout << "Array of float, after: \t\t";
        printArray(floatArr, 2);
        std::cout << std::endl;

    return 0;
}