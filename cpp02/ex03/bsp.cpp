

#include "Fixed.hpp"
#include "Point.hpp"
// division par 2.0f pour garder la précision ( 2/5 = [int]2 et [float]2,5)
//de type fixed car stock la valeur en virgule fixe, cohérence et la précision
Fixed areaTriangle( Point const a, Point const b, Point const c)
 {
    Fixed tmp((a.getX() * (b.getY() - c.getY()) + 
           b.getX() * (c.getY() - a.getY()) + 
           c.getX() * (a.getY() - b.getY())) / 2.0f);
    return (std::abs(tmp.getRawBits()));

}

//1 (true) : La condition est vraie.
//0 (false) : La condition est fausse.
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed baseTriangle = areaTriangle(a, b, c);
    Fixed ab_Triangle = areaTriangle(point, a, b);
    Fixed ac_Triangle = areaTriangle(point, c, a);
    Fixed bc_Triangle = areaTriangle(point, b, c);

    if (ab_Triangle.getRawBits() == 0 || ac_Triangle.getRawBits() == 0 || bc_Triangle.getRawBits() == 0)
        return (false);

    bool resulto = (baseTriangle.getRawBits() == (ab_Triangle.getRawBits() + ac_Triangle.getRawBits() + bc_Triangle.getRawBits()));

    return(resulto);

}