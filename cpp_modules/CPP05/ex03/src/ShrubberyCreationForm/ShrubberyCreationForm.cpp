#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("file_shrubbery") {
}

ShrubberyCreationForm::ShrubberyCreationForm(string target): AForm("ShrubberyCreationForm", 145, 137) {
    this->target = target;
    this->target.append("_shrubbery");
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137), target(other.getTarget()) {
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other) {
    if (this != &other) {
        this->setIsSigned(other.getIsSigned()); // ?
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

/* Methods */
void ShrubberyCreationForm::execute(Bureaucrat const &executor)const {
    if (this->getGradeToExecute() < executor.getGrade())
        throw (AForm::GradeTooLowException());
    else if (!this->getIsSigned())
        throw (AForm::NotSignedException());
    ofstream outfile(this->target.c_str());
    
    if (outfile.is_open()) {
        outfile << "                                                         .       " <<
            "                                                         .       " << endl <<
            "                                              .         ;        " <<
            "                                              .         ;        " << endl <<
            "                 .              .              ;%     ;;         " <<
            "                 .              .              ;%     ;;         " << endl <<
            "                   ,           ,                :;%  %;          " <<
            "                   ,           ,                :;%  %;          " << endl <<
            "                    :         ;                   :;%;'     .,   " <<
            "                    :         ;                   :;%;'     .,   " << endl <<
            "           ,.        %;     %;            ;        %;'    ,;     " <<
            "           ,.        %;     %;            ;        %;'    ,;     " << endl <<
            "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " <<
            "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << endl <<
            "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " <<
            "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << endl <<
            "               ;%;      %;        ;%;        % ;%;  ,%;'         " <<
            "               ;%;      %;        ;%;        % ;%;  ,%;'         " << endl <<
            "                `%;.     ;%;     %;'         `;%%;.%;'           " <<
            "                `%;.     ;%;     %;'         `;%%;.%;'           " << endl <<
            "                 `:;%.    ;%%. %@;        %; ;@%;%'              " <<
            "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << endl <<
            "                    `:%;.  :;bd%;          %;@%;'                " <<
            "                    `:%;.  :;bd%;          %;@%;'                " << endl <<
            "                      `@%:.  :;%.         ;@@%;'                 " <<
            "                      `@%:.  :;%.         ;@@%;'                 " << endl <<
            "                        `@%.  `;@%.      ;@@%;                   " <<
            "                        `@%.  `;@%.      ;@@%;                   " << endl <<
            "                          `@%%. `@%%    ;@@%;                    " <<
            "                          `@%%. `@%%    ;@@%;                    " << endl <<
            "                            ;@%. :@%%  %@@%;                     " <<
            "                            ;@%. :@%%  %@@%;                     " << endl <<
            "                              %@bd%%%bd%%:;                      " <<
            "                              %@bd%%%bd%%:;                      " << endl <<
            "                                #@%%%%%:;;                       " <<
            "                                #@%%%%%:;;                       " << endl <<
            "                                %@@%%%::;                        " <<
            "                                %@@%%%::;                        " << endl <<
            "                                %@@@%(o);  . '                   " <<
            "                                %@@@%(o);  . '                   " << endl <<
            "                                %@@@o%;:(.,'                     " <<
            "                                %@@@o%;:(.,'                     " << endl <<
            "                            `.. %@@@o%::;                        " <<
            "                            `.. %@@@o%::;                        " << endl <<
            "                               `)@@@o%::;                        " <<
            "                               `)@@@o%::;                        " << endl <<
            "                                %@@(o)::;                        " <<
            "                                %@@(o)::;                        " << endl <<
            "                               .%@@@@%::;                        " <<
            "                               .%@@@@%::;                        " << endl <<
            "                               ;%@@@@%::;.                       " <<
            "                               ;%@@@@%::;.                       " << endl <<
            "                              ;%@@@@/%%:;;;.                     " <<
            "                              ;%@@@@/%%:;;;.                     " << endl <<
            "                          ...;%@@@@@%%:;;;;,..                   " <<
            "                          ...;%@@@@@%%:;;;;,..                   " << endl;
        outfile.close();
    } else {
        cout << "Error openin the file." << endl;
    }
}

string ShrubberyCreationForm::getTarget() {
    return this->target;
}
