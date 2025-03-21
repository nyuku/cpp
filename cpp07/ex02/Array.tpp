// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// |		 
//       ✩ tpp est utilisé pour l’implémentation des templates
//       ✩ instanciation de Array pour un type T
//       ✩ Parce que Array n'est pas une classe unique mais un modèle (template).
//       ✩ int& operator[]-> T& operator[]
//       ✩ try et catch.thrown exceptions must be catchable using try and catch blocks
//       ✩ exepetion out of range: integrante de la librairie
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#include "Array.hpp"

//.......................................................................................................
//								        Constructor - Destructor		
//                                      Constructor with arg- Copy constructor                           |
//.......................................................................................................

    template <typename Type>
    Array<Type>::Array() : _tab(new Type[0]()), _size(0)
    {
        std::cout << "\nConstructor Array called" << std::endl;
    }

    template <typename Type>
    Array<Type>::~Array() 
    {
        delete[] _tab;
        _tab = NULL; 
    }

    template <typename Type>
    Array<Type>::Array(unsigned int n) : _size(n) 
    {
        std::cout << "Constructor Array called with size: "<<n<< std::endl;
        _tab = new Type[n]();
    }

    template <typename Type>
    Array<Type>::Array(const Array& other) : _size(other._size) 
    {
        std::cout << "Copy constructor Array called" << std::endl;
        _tab = new Type[_size](); // Allouer un nouveau tableau
        for (unsigned int i = 0; i < _size; i++) 
        {
            _tab[i] = other._tab[i];
        }
    }
//.......................................................................................................
//										    Opérator =, []												|
//.......................................................................................................
 
    template <typename Type>
    Array<Type>& Array<Type>::operator=(const Array& other) 
    {
        if (this != &other) 
        { 
            delete[] _tab; // Libérer l'ancienne mémoire

            _size = other._size;
            _tab = new Type[_size](); // Allouer un nouveau tableau
            for (unsigned int i = 0; i < _size; i++) 
            {
                _tab[i] = other._tab[i];
            }
        }
        return *this;
    }


    template <typename Type>
    Type &Array<Type>::operator[](unsigned int index)
    {
        if (index >= _size) 
        {
            // std::cerr << "💥 Exception sur index: " << index << " (taille: " << _size << ")" << std::endl;
            throw std::out_of_range("Index out of bounds");
        }
        return _tab[index];
    }

    // Opérateur [] constant
    template <typename Type>
    const Type& Array<Type>::operator[](unsigned int index) const {
        if (index >= _size) 
        {
            // std::cerr << "💥 Exception sur index const: " << index << " (taille: " << _size << ")" << std::endl;
            throw std::out_of_range("Index out of bounds");
        }
        return _tab[index];
    }
//.......................................................................................................
//								  Méthodes de size requis
//                                                                              						|
//.......................................................................................................

    template <typename Type>
    unsigned int Array<Type>::size() const 
    {
        return _size;
    }
