#include "RobotomyRequestForm/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(string target) {
    target.append("_shrubbery");
    ofstream file(target);
    
    if (file.is_open()) {
        file << "                                                         ." << endl <<
            "                                              .         ;  " << endl <<
            "                 .              .              ;%     ;;   " << endl <<
            "                   ,           ,                :;%  %;   " << endl <<
            "                    :         ;                   :;%;'     .,   " << endl <<
            "           ,.        %;     %;            ;        %;'    ,;" << endl <<
            "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << endl <<
            "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << endl <<
            "               ;%;      %;        ;%;        % ;%;  ,%;'" << endl <<
            "                `%;.     ;%;     %;'         `;%%;.%;'" << endl <<
            "                 `:;%.    ;%%. %@;        %; ;@%;%'" << endl <<
            "                    `:%;.  :;bd%;          %;@%;'" << endl <<
            "                      `@%:.  :;%.         ;@@%;'   " << endl <<
            "                        `@%.  `;@%.      ;@@%;         " << endl <<
            "                          `@%%. `@%%    ;@@%;        " << endl <<
            "                            ;@%. :@%%  %@@%;       " << endl <<
            "                              %@bd%%%bd%%:;     " << endl <<
            "                                #@%%%%%:;;" << endl <<
            "                                %@@%%%::; "<< endl <<
            "                                %@@@%(o);  . '         " << endl <<
            "                                %@@@o%;:(.,'         " << endl <<
            "                            `.. %@@@o%::;         " << endl <<
            "                               `)@@@o%::;         " << endl <<
            "                                %@@(o)::;        " << endl <<
            "                               .%@@@@%::;         " << endl <<
            "                               ;%@@@@%::;.          " << endl <<
            "                              ;%@@@@/%%:;;;. " << endl <<
            "                          ...;%@@@@@%%:;;;;,.." << endl << EOF;
    } else {
        cout << "Error openin the file." << endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other) {
    if (this != &other) {
        this->setIsSigned(other.getIsSigned());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

/* Methods */

void RobotomyRequestForm::beSigned(const Bureaucrat& b) {
    
}

