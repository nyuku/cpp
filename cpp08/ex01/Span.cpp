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

    Span::Span(unsigned int n) : _n(n),_i(0)
    {
        if (n<= 1)
            throw std::invalid_argument(LIGHT_RED "Error: the size given must be greater than 1" RESET_COLOR);
        _container = std::vector<unsigned int>(_n, UINT_MAX); // initialise tout à 0
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
            throw std::invalid_argument(LIGHT_RED "Error: Cannot add a negative number" RESET_COLOR);
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
    
        std::srand(time(0));
        
        std::vector<unsigned int>::iterator start = begin;
        //check qte d'element ajouter
        size_t count = 0;
        for (; start != end; ++start)
            count++;
        if (count > _n || count < 1)// respect ce qui a deja éte mis
            throw FullContainerException();
        //check iterator begin et end du container
        if (begin < _container.begin() || end > _container.end())
            throw std::out_of_range("Iterators out of container bounds.");


        if (overwrite == true)
        {
            std::cout << "FillContainer: Overwrite mode activated" << std::endl;
            _i = 0;
            // start = begin;
        }
        else if (!overwrite && _i > 0)
        {
            size_t offsetBegin = std::distance(_container.begin(), begin);
            size_t offsetEnd   = std::distance(_container.begin(), end);
            if (offsetBegin < _i && offsetEnd <= _i)
                throw std::out_of_range("Iterator begin is out of range, risk of damaging current data");
                //va print par dessus ce qui est deja dans le container
        }
    
        // start = _i + begin;// onrespect ce qu'il y a deja dans le container
        if (begin < _container.begin() + _i)
        {
            start = _container.begin() + _i;  // si begin est dans la data,Commence à l'endroit où les éléments ont été remplis
        }
        else
        {
            start = begin;  // Commence à partir du 'begin' passé en arg
        }

        for (; start != end; ++start)
        {   
            *start = (std::rand() % 10000 + 1); // pour eviter _container[_i]

            // on met à jour _i seulement si on va plus loin que ce qu’on avait déjà rempli
            size_t pos = std::distance(_container.begin(), start) + 1;
            if (pos > _i)
                _i = pos;
        }
    }

//=======================================================================================================
//										   utils												|
//=======================================================================================================

    void Span::printContainer() const
    {
        std::cout << LIGHT_BLUE << "Container size: "<< this->getn() << RESET_COLOR;
        if (_container.empty())
        {
            std::cout << "[ empty ]" << std::endl;
            return;
        }

        std::cout << "[ ";
        for (size_t i = 0; i < _container.size(); ++i)
        {
            if (_container[i] != UINT_MAX)
                std::cout << _container[i];
            else
                std::cout << "-";// rand() ne donne pas  de 0
            if (i < _container.size() - 1)
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

    unsigned int Span::getn() const
    {
        return _n;
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
        return (LIGHT_RED "Error: Container is empty or has only one element" RESET_COLOR);
    }
