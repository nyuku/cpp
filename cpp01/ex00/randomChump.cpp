/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:55:53 by angela            #+#    #+#             */
/*   Updated: 2024/05/04 00:55:54 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

//Crée un zombie éphémère sur la stack
// lui donne un nom et le fait se présenter.
// dès qu'on sort de la fonction
void randomChump( std::string name )
{
	Zombie snow(name);
	snow.announce();
}