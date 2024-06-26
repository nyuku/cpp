/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:27:35 by angela            #+#    #+#             */
/*   Updated: 2024/06/20 00:32:44 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	bool resulto;
	//good plan--------------------------------------------------------------------------
	Point	p(1.5f, 1);
	Point	a(0, 0);
	Point	b(4, 4);
	Point	c(8, 0);
	resulto = bsp(a, b, c, p);
	std::cout << std::endl<< "Bon triangle" << std::endl<< std::endl;
	if (resulto == false)
		std::cout << std::endl<< "false is not a triangle" << std::endl;
	else
		std::cout << "true is a triangle" << std::endl;

	// sur une arrete AB------------------------------------------------------------------
	Point p2(2, 2);
	Point a2(0, 0);
	Point b2(4, 4);
	Point c2(8, 0);
	resulto = bsp(a2, b2, c2, p2);
	std::cout << std::endl<< std::endl<< "bad triangle, point sur une arrete AB" << std::endl;
	if (resulto == false)
		std::cout << std::endl<< "false is not a triangle" << std::endl;
	else
		std::cout << std::endl<< "true is a triangle" << std::endl;

	//Point pp sur l'arête AC------------------------------------------------------
    Point p3(4, 0);
    Point a3(0, 0);
    Point b3(4, 4);
    Point c3(8, 0);
	resulto = bsp(a3, b3, c3, p3);
		std::cout << std::endl<< std::endl<< "bad triangle,Point pp sur l'arête AC" << std::endl;
	if (resulto == false)
		std::cout << std::endl<< "false is not a triangle" << std::endl;
	else
		std::cout << std::endl<< "true is a triangle" << std::endl;

	//point en dehors du triangle------------------------------------------------------------------
	   // Exemple 1 : Point p4 en dehors du triangle
    Point p4(10, 10);
    Point a4(0, 0);
    Point b4(4, 4);
    Point c4(8, 0);
	resulto = bsp(a4, b4, c4, p4);
		std::cout << std::endl<< std::endl<< "bad triangle,Point exterieur" << std::endl;
	if (resulto == false)
		std::cout << std::endl<< "false is not a triangle" << std::endl;
	else
		std::cout << std::endl<< "true is a triangle" << std::endl;


	
	return (0);
}