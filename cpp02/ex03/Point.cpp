/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:44:46 by angela            #+#    #+#             */
/*   Updated: 2024/06/20 01:09:36 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

//--------------     DEFAULT Constructor - Destructor   ---------------
    Point::Point(): _x(0), _y(0) // init à 0
    {
    }

    Point::~Point()
    {
    }

//----------------------   Constructor     ---------------------------
   Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)// Point::Point(float const x, float const y): x(x), y(y) //float
    {
    }
    //copie objet a= b(existants)
    Point::Point(const Point & obj): _x(obj.getX()), _y(obj.getY())//copie les valeur de x et y de obj
    {
    }


//----------------------   Operateur     ---------------------------
//mais...assigne les valeurs d'un objet existant à un autre objet existant. mais on est en full const au niveau des valeurs è.é
//compile que si on met en // ou si les valeurs passent en non const
    // Point & Point::operator=( const Point &obj)
    // {
    //     this->_x = obj.getX();
    //     this->_y = obj.getY();
    //     return (*this);
    // }


//-----------------------getters setters--------------------------------
const Fixed& Point::getX() const 
{
    return _x;
}

// Getter pour _y
const Fixed& Point::getY() const 
{
    return _y;
}