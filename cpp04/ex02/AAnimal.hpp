#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	private:

	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal( std::string type);
		AAnimal( const AAnimal &cpy);
		AAnimal& operator=( const AAnimal &rhs );
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;

		const std::string	getType( void ) const;
		void	setType( const std::string type );

};

#endif 