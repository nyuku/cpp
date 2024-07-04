#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
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

// We don't have to write virtual or override in the child class,
// but it is a good practice to do so, to make the intent clear.