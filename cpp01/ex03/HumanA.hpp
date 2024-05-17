/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:57:04 by angela            #+#    #+#             */
/*   Updated: 2024/05/15 19:57:25 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_equipment; // réference,-> arme existante lors du constructor


	public:

		HumanA(std::string name, Weapon &type);
		~HumanA(void);

		// -----------------  Getters -----------------
//		std::string	getName() const;
//		std::string	getWeapon() const;
		// -----------------  Setters -----------------
		void setWeapon(Weapon & weapon);
		//-------------- Fonction ----------------
		void attack();
};


#endif