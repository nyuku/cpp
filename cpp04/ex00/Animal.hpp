#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	private:

	protected:
		std::string	type;

	public:
	//--------------------      Constructor- destructor     --------------------
		Animal();
		Animal( std::string type);
		Animal( const Animal &cpy);
		virtual ~Animal();
    //--------------------------    Operator    ----------------------------
		Animal& operator=( const Animal &rhs );

 	//--------------------------    Fonctions membres     -----------------------
		virtual void	makeSound() const;
    // ------------------------     Getters- Setter     -----------------------
		const std::string	getType( void ) const;
		void	setType( const std::string type );

};

#endif
