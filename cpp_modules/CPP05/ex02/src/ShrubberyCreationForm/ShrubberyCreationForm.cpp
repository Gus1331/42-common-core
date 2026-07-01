#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) {
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

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other) {
    if (this != &other) {
        this->setIsSigned(other.getIsSigned());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

/* Methods */

void ShrubberyCreationForm::beSigned(const Bureaucrat& b) {
    
}

