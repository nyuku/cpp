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
//
//       ✩ Testez Span avec au moins 10 000 nombres
//       ✩ 3 exceptions à créer/gérer:
//              - std::invalid_argument : n < 2 
//              - std::FullContainerException : container plein > n
//              - std::InsufficientDataException: < 2 éléments
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝
#include ".hpp"

//.......................................................................................................
//										Constructor - Destructor		
//                                      With argh - Copy                    							|
//.......................................................................................................

    Span::Span() : _n(0) {}
    Span::~Span() {}

    Span::Span(unsigned int n) : _n(n) 
    {
        if (n<= 1)
            throw std::invalid_argument("Error: n must be greater than 1");
    }

//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
    
    Span & Span::operator=(Span const & rhs)
    {
        if (this != &rhs)
        {
            _n = rhs._n;
            _container = rhs._container;
        }
        return *this;
    }

 //.......................................................................................................
//										 Copy constructor
//                          Init "variable const" par la liste d'int, que 2 variables	
//                          methode: liste d’initialisation                                             |
//.......................................................................................................
    Span::Span(Span const & rhs) : _n(rhs._n), _container(rhs._container) 
    {
        *this = rhs;
    }

//=======================================================================================================
//										   Fonctions membres											|
//=======================================================================================================
    void Span::addNumber(unsigned int addNumber)
    {
        if (_container.size() >= _n)
            throw std::FullContainerException("Error: Container is full");
        _container.push_back(addNumber);
    }
/*
    sort: tri dans l'ordre croissant
    shortest: init la valeur a la 1ere difference
    boucle: compare la difference entre chaque element
*/
    unsigned int Span::shortestSpan()
    {
        if (_container.size() <= 1)
            throw std::InsufficientDataException ("Error: Container is empty or has only one element");
        std::sort(_container.begin(), _container.end());
        unsigned int shortest = _container[1] - _container[0];
        for (size_t i = 1; i < _container.size(); i++)
        {
            if (_container[i] - _container[i - 1] < shortest)
                shortest = _container[i] - _container[i - 1];
        }
        return shortest;
    }

/*
    sort: tri dans l'ordre croissant
    longest: difference entre le dernier et le premier element
*/
    unsigned int Span::longestSpan()
    {
        if (_container.size() <= 1)
            throw std::InsufficientDataException("Error: Container is empty or has only one element");
        std::sort(_container.begin(), _container.end());
        return _container[_container.size() - 1] - _container[0];
    }

    void    Span::fillContainer(std::vector<int>::iterator begin, std::vector<int>::iterator end)
    {
        size_t count = 0;
        std::vector<int>::iterator i = begin;
        for (i; it != end; ++it)
            count++;
        if (_container.size() + count > _maxSize || count < 1)
            throw std::overflow_error("Error: Adding these numbers would exceed the Span's capacity!");
        for (i; it != end; ++it)
            _container.push_back(*it);
    }

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================


//=======================================================================================================
//										   Operator <<					    							|
//=======================================================================================================


//=======================================================================================================
//										   Exceptions					    							|
//=======================================================================================================