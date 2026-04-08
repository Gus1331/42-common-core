#include "Point.hpp"

static Fixed sign(Point p1, Point p2, Point p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
		    (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp (Point a, Point b, Point c, Point x) {
    Fixed d1 = sign(x, a, b);
    Fixed d2 = sign(x, b, c);
    Fixed d3 = sign(x, c, a);

    if ((d1 > 0 && d2 > 0 && d3 > 0))
        return true;
    else if ((d1 < 0 && d2 < 0 && d3 < 0))
        return true;
    return false;
}
