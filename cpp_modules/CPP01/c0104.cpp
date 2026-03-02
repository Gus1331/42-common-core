#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main(int argc, char **argv) {
    if (argc != 4) return 1;
    char *filename = argv[1];
    char *s1 = argv[2];
    char *s2 = argv[3];

    if (!filename || ! s1) return 1;

    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error opening " << filename << " :(" << endl;
        return 1;
    }

    string content;

    {
        string line;
        while (getline(file, line)) {
            content.append(line);
            content.append("\n");
        }
    }

    string outfilename = "";
    outfilename.append(filename);
    outfilename.append(".replace");
    ofstream outfile(outfilename.c_str());

    if (!outfile.is_open()) {
        cout << "Error creating .replace file" << endl;
        return 1;
    }

    {
        int i = 0;

        while (content[i]) {
            int j = 0;
            while (content[i + j] == s1[j] && s1[j])
                j++;
            if (!s1[j]) {
                content.erase(i, j);
                content.insert(i, s2);
                i += strlen(s2);
                continue;
            }
            i++;
        }
    }

    outfile << content;

    return 0;
}
