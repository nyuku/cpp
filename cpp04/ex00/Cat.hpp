/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:48 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 14:00:44 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/*
     \    /\
	  )  ( ')   *Meow*
      (  /  )
	   \(__)|
*/

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
		Cat& operator=( const Cat &src );

	//--------------------------    Fonctions membres     -----------------------
		virtual void makeSound() const;
};

#endif

// We don't have to write virtual or override in the child class,
// but it is a good practice to do so, to make the intent clear.