#include "iter.hpp"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::string;

void sum1int(int &ptr) {
	(ptr)++;
}

void sum1char(char &ptr) {
	(ptr)++;
}

void putChar(const char &c){
	cout << c;
}

int	main() {
	int a[5] = {1,2,3,4,5};
	char b[3] = {'a', 'b', 'c'};

	cout << "Before sum1" << endl;

	for (int i = 0; i < 5; i++) cout << a[i] << " ";
	cout << endl;
		
	for (int i = 0; i < 3; i++) cout << b[i] << " ";
	cout << endl;

	iter(a, 5, sum1int);
	iter(b, 3, sum1char);

	cout << "After sum1" << endl;

	for (int i = 0; i < 5; i++) cout << a[i] << " ";
	cout << endl;
		
	for (int i = 0; i < 3; i++) cout << b[i] << " ";
	cout << endl;

	const char c[3] = {'A', 'B', 'C'};
	iter(c, 3, putChar);
	cout << endl;
		
	return (0);
}

/* // main's subject


*/
