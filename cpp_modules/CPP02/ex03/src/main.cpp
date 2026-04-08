#include "Point.hpp"

bool bsp(Point a, Point b, Point c, Point x);
void testPoint(string name, Point const a, Point const b, Point const c, Point const p)
{
	cout << "Teste: " << name << endl;

	cout << "Ponto (" 
			  << p.getX() << ", " 
			  << p.getY() << ") -> ";

	if (bsp(a, b, c, p))
		cout << "DENTRO do triangulo";
	else
		cout << "FORA do triangulo";

	cout << "\n--------------------------\n";
}

int main(void)
{
	Point a(0, 0);
	Point b(5, 10);
	Point c(10, 0);

	cout << "Triangulo:\n";
	cout << "A(0,0), B(10,0), C(5,10)\n";
	cout << "==========================\n\n";

	Point inside(5, 5);
	Point outside(10, 10);
	Point edge(5, 0);
	Point vertex(0, 0);
	Point far(100, 100);

	Point	t(5, 9.99f);

	testPoint("MyTeste", a, b, c, t);
	testPoint("Dentro", a, b, c, inside);
	testPoint("Fora", a, b, c, outside);
	testPoint("Na aresta (deve dar FALSE)", a, b, c, edge);
	testPoint("No vertice (deve dar FALSE)", a, b, c, vertex);
	testPoint("Muito longe", a, b, c, far);

	return 0;
}
