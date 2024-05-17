/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:55:49 by angela            #+#    #+#             */
/*   Updated: 2024/05/04 00:55:50 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"Zombie.hpp"

// Crée un zombie, lui donne un nom
// retourne un pointeur de type classe zombue, persistant en dehors de la fonction.
//char * = zombie *
//on the heap
Zombie *newZombie( std::string name)
{
	Zombie	*new_zombie;
	new_zombie = new Zombie(name);
	new_zombie->announce(); 
	return (new_zombie);
}