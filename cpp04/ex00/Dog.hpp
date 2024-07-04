#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
	//--------------------      Constructor- destructor     --------------------
		Dog();
		~Dog();

		Dog( std::string type);
		Dog( const Dog &cpy);
    //--------------------------    Operator    ----------------------------
		Dog& operator=( const Dog &rhs );

   //--------------------------    Fonctions membres     -----------------------
		virtual void makeSound() const;
};

#endif