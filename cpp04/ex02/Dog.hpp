#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
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