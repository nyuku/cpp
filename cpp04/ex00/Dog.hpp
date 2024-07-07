/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:54 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 12:45:32 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
/*
           __
      (___()'`;  * WOOF *
      /,    /`
      \\"--\\
*/

class Dog : public Animal
{
	public:
	//--------------------      Constructor- destructor     --------------------
		Dog();
		~Dog();

		Dog( std::string type);
		Dog( const Dog &cpy);
    //--------------------------    Operator    ----------------------------
		Dog& operator=( const Dog &src );

   //--------------------------    Fonctions membres     -----------------------
		void makeSound() const;
};

#endif