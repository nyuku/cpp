#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat( std::string type);
		Cat( const Cat &cpy);
		Cat& operator=( const Cat &rhs );
		~Cat();

		virtual void makeSound() const;
};

#endif 