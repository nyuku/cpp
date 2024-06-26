/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:26:58 by angela            #+#    #+#             */
/*   Updated: 2024/06/20 01:09:53 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
				Fixed	const _x;
		        Fixed	const _y;
                // Fixed	_x;// pour l'operateur d'affectation
		        // Fixed	_y;

	public:
    //--------------------  Constructor- destructor     --------------------
                Point();
		        ~Point();

                Point(const Fixed f1, const Fixed f2);
                Point(Point const &obj);// constructeur par copie
    //--------------------------    Operator    ----------------------------
                Point &operator=( const Point & obj);//operateur d'affectation
    // ------------------------     Getters- Setter     ------------------------
                // void	setX(Fixed f);
                // void	setY(Fixed f);
                const Fixed& getX() const;
                const Fixed& getY() const;
};

#endif