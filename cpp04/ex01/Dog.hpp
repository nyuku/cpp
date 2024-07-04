#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog( std::string type);
		Dog( const Dog &cpy);
		Dog& operator=( const Dog &rhs );
		~Dog();

		virtual void makeSound() const;
};

#endif