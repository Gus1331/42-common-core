#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main (int argc, char *argv[]) {
	int i = 1;
	if (argc > 1) {

		while (i < argc) {
			std::string s = argv[i];
			for (int j = 0; j < (int)s.size(); j++) {
				cout << (char)toupper(s[j]);
			}
			i++;
		}
	} else {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	cout << endl;
	return 0;
}
