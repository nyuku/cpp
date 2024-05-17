/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:56:20 by angela            #+#    #+#             */
/*   Updated: 2024/05/04 00:56:21 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int i = 0;
	//array of C.zombie
	zombie = new Zombie[N];
	while (i < N)
	{
		zombie[i].setName(name);
		zombie[i].announce();
		i++;
	}
	return (zombie);
}
