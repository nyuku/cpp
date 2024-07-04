#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:

protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal( std::string type);
	WrongAnimal( const WrongAnimal &cpy);
	WrongAnimal& operator=( const WrongAnimal &rhs );
	~WrongAnimal();

	void	makeSound() const;

	const std::string	getType( void ) const;

	void	setType( const std::string type );

};

#endif
