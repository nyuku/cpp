#include "Brain.hpp"

//.......................................................................................................
//										Constructor - Destructor										|
//.......................................................................................................
Brain::Brain( void )
{
    std::cout <<LIGHT_GREEN<< "Brain created." <<RESET_COLOR<< std::endl;
    for (int i = 0; i < 100; i++)
		_ideas[i] = "plop nothing in here";
}

Brain::~Brain( void )
{
    std::cout<<LIGHT_RED << "Brain destroyed." <<RESET_COLOR<< std::endl;
}

Brain::Brain( const Brain& src )
{
    *this = src;
}
//.......................................................................................................
//										    Opérator 													|
//.......................................................................................................
Brain& Brain::operator=( const Brain& src )
{
    std::cout << "Brain copy called." << std::endl;
    if ( this != &src ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = src._ideas[i];
        }
    }
    return *this;
}

//=======================================================================================================
//										   Getters-Setters												|
//=======================================================================================================

void Brain::setIdeas(std::string ideas, int i)
{
    if (i >= 0 and i <= 100)
        this->_ideas[i] = ideas;
}

std::string Brain::getIdeas(int i) const
{   
        if (i >= 0 and i <= 100)
        return this->_ideas[i];
    return(0);
}
