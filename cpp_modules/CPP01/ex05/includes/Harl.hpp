
#ifndef __HARL_H__
#define __HARL_H__

#pragma once
class Harl;

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        Harl();
        void complain(string level);

};

#endif
