#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
private:

protected:
	std::string	type;

public:
	Animal();
	Animal( std::string type);
	Animal( const Animal &cpy);
	Animal& operator=( const Animal &rhs );
	virtual ~Animal();

	virtual void	makeSound() const;

	const std::string	getType( void ) const;
	void	setType( const std::string type );

};

#endif

