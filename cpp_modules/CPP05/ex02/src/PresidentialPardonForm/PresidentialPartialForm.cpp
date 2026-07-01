#include "PresidentialPartialForm/PresidentialPartialForm.hpp"

PresidentialPartialForm::PresidentialPartialForm() {
}

PresidentialPartialForm::PresidentialPartialForm(string target) {
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

PresidentialPartialForm::PresidentialPartialForm(PresidentialPartialForm &other) {

}

PresidentialPartialForm &PresidentialPartialForm::operator=(PresidentialPartialForm &other) {
    if (this != &other) {
        this->setIsSigned(other.getIsSigned());
    }
    return *this;
}

PresidentialPartialForm::~PresidentialPartialForm() {
}

/* Methods */

void PresidentialPartialForm::beSigned(const Bureaucrat& b) {
    
}

