/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:09 by angela            #+#    #+#             */
/*   Updated: 2024/07/06 15:23:22 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

/*
	Classe enfant
*/

class WrongCat : public WrongAnimal
{
public:
//--------------------      Constructor- destructor     --------------------
	WrongCat();
	~WrongCat();
	WrongCat( std::string type);
	WrongCat( const WrongCat &cpy);
//--------------------------    Operator    ----------------------------
	WrongCat& operator=( const WrongCat &rhs );

//--------------------------    Fonctions membres virtuel    ----------------------------
	// void makeSound() const;
};

#endif