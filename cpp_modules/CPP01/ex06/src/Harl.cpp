#include "Harl.hpp"

void Harl::debug(void) {
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info(void) {
    cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning(void) {
    cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << endl;
}

void Harl::error(void) {
    cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

Harl::Harl() {}

void Harl::complain(string level) {
    string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4]) ()= {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };            
    for (int i = 0; i < 4 ;i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return ;
        }
    }
}