#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
//--------------------      Constructor- destructor     --------------------
	Cat();
	~Cat();

	Cat( std::string type);
    //--------------------------    Copy constructor    ----------------------------

	Cat( const Cat &cpy);
	
	//--------------------------    Operator    ----------------------------
	Cat& operator=( const Cat &rhs );

   //--------------------------    Fonctions membres     -----------------------
	virtual void makeSound() const;
};

#endif

// We don't have to write virtual or override in the child class,
// but it is a good practice to do so, to make the intent clear.