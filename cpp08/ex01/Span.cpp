// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 ✩ Span pouvant stocker un maxium de 'N' entiers
//       ✩ Fonctions à implémenter : 
//             - addNumber() afin d’ajouter un seul nombre à la Span, exception si dépasse 'N'
//       ✩ Fonctions membre
//             - shortestSpan(): retourne la plus petite différence entre des entiers [3, 5, 8, 17] => 2
//             - longestSpan(): retourne la différence entre les plus grands entiers  [3, 5, 8, 17] => 14
//             -> exception si nombre d’entiers insuffisant < 2 ou aucune différence trouvée
//       ✩ Fonctions bonus: qui ajoute plusieurs nombres à la fois via une plage d'itérateurs(bord donnés) 
//                          sans rappeler addNumber() plusieurs fois
//       ✩ Testez Span avec au moins 10 000 nombres
//
//       ✩ 3 exceptions à créer/gérer:
//              - std::invalid_argument : nb < 0 
//              - std::FullContainerException : container plein > n
//              - std::InsufficientDataException: < 2 éléments

//      Creation span: -"reserve" alloue la mémoire pour _n éléments sans en ajouter. ensuite l’ajout réel via addNumber().
//                     - push_back() ajoute un élément à la fin du vecteur, augmentant sa taille.
//                     ->on cree span avec la taille n directement -> index géré par le constructeur _i

// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include "Span.hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      With argh - Copy                    							|
//.......................................................................................................

    Span::Span() : _n(0), _i(0),_container()
    {
        std::cout << "Default constructor called" << std::endl;
    }

    Span::~Span() {}

    Span::Span(unsigned int n) : _n(n),_i(0), _container(n)
    {
        std::cout << "value constructor called" << std::endl;
        if (n<= 1)
            throw std::invalid_argument(LIGHT_RED"Error: the size given must be greater than 1"RESET_COLOR);
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    
    Span & Span::operator=(Span const & rhs)
    {
        if (this != &rhs)
        {
            _n = rhs._n;
            _i = rhs._i;
            _container = rhs._container;
        }
        return *this;
    }

 //.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................
    Span::Span(Span const & rhs) : _n(rhs._n), _i(rhs._i),  _container(rhs._container) {}

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
    void Span::addNumber(int addNumber)
    {
        if (_i >= _n)
            throw FullContainerException();
        if (addNumber < 0) 
            throw std::invalid_argument(LIGHT_RED"Error: Cannot add a negative number"RESET_COLOR);
        _container[_i++] = addNumber;
    }
/*
    sort: tri dans l'ordre croissant
    shortest: init la valeur a la 1ere difference
    boucle: compare la difference entre chaque element
    ! ca modifie direct l'original...pas fou
*/

   
    unsigned int Span::shortestSpan()
    {
        unsigned int span = 0;
        unsigned int shortest = 0;
        std::vector<unsigned int> tmp;
        tmp = _container; // Copie pour ne pas trier l'original
        unsigned int a = tmp[0];
        unsigned int b = tmp[1];
        
        if (_i <= 1)
            throw InsufficientDataException();
       
        std::sort(tmp.begin(), tmp.end());

        shortest = tmp[1] - tmp[0];
        for (size_t i = 2; i < tmp.size(); i++)
        {
            span = tmp[i] - tmp[i - 1];
            if (span < shortest)
            {
                shortest = span;
                a = tmp[i - 1];
                b = tmp[i];
            }
        }
        std::cout<< shortest << ", between " << a << " and " << b <<std::endl;
        return shortest;
    }


/*
    sort: tri dans l'ordre croissant
    longest: difference entre le dernier et le premier element
*/
    unsigned int Span::longestSpan()
    {
        if (_i <= 1)
            throw InsufficientDataException();
        std::sort(_container.begin(), _container.end());
        std::cout<< _container[_container.size() - 1] - _container[0] <<" ,between "<<_container[_container.size() - 1] << " - " << _container[0] << std::endl;
        return _container[_container.size() - 1] - _container[0];
    }

    void    Span::fillContainer(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end,  bool overwrite = false)
    {
        if (begin == end)
            throw InsufficientDataException();
    
        std::srand(std::time(0));
        // size_t count = 0;
        std::vector<unsigned int>::iterator start = begin;
        // for (; start != end; ++start)
        //     count++;
        if (overwrite == true)
        {
            std::cout << "FillContainer: Overwrite mode activated" << std::endl;
            _i = 0;
            start = begin;
        }
        // if ((_i + count) > _n || count < 1)// respect ce qui a deja éte mis
        //     throw FullContainerException();
        else
            start = _i + begin;// onrespect ce qu'il y a deja dans le container
       
        for (; start != end; ++start)
            _container[_i++] = (std::rand() % 10000 + 1);
    }

//=======================================================================================================
//										   utils												|
//=======================================================================================================

    void Span::printContainer() const
    {
        if (_container.empty())
        {
            std::cout << "[ empty ]" << std::endl;
            return;
        }

        std::cout << "[ ";
        for (size_t i = 0; i < _i; ++i)
        {
            std::cout << _container[i];
            if (i < _i - 1)
                std::cout << ", ";
        }
        std::cout << " ]" << std::endl << std::endl;;
    }

//=======================================================================================================
//										   Getter				    							|
//=======================================================================================================
    std::vector<unsigned int>::iterator Span::getContainerBegin()
    {
        return _container.begin();
    }

    std::vector<unsigned int>::iterator Span::getContainerEnd()
    {
        return _container.end();
    }

//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================
    const char* Span::FullContainerException::what() const throw()
    {
        return (LIGHT_RED "Error: Container is full, adding these numbers would exceed the Span's capacity!" RESET_COLOR);
    }

    const char* Span::InsufficientDataException::what() const throw()
    {
        return (LIGHT_RED"Error: Container is empty or has only one element"RESET_COLOR);
    }
