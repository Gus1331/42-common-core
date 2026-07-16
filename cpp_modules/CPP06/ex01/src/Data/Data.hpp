

#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::endl;

class Data {
    private:
        string user;
        string pass;
        bool banned;
    public:
        Data();
        Data(string user, string pass);
        Data(Data &other);
        Data&operator=(Data &other);

        ~Data();

        /* Methods */
        void login();
        void ban();

        /* Getters & Setters*/
        string getUser();
        string getPass();
        bool getBanned();

        void setUser(string user);
        void setPass(string pass);
};

#endif


