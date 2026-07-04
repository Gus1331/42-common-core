
#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {

    std::cout << "=========================================================" << std::endl;
    std::cout << "📋 TESTE 1: ShrubberyCreationForm (Requer: Sign 145, Exec 137)" << std::endl;
    std::cout << "=========================================================" << std::endl;
    {
        Bureaucrat alice("Alice", 150); // Nota muito baixa para tudo
        Bureaucrat bob("Bob", 140);     // Consegue assinar, mas não executar
        Bureaucrat charlie("Charlie", 130); // Consegue fazer tudo

        ShrubberyCreationForm form1("home");

        std::cout << "\n--- Tentando executar sem assinatura ---" << std::endl;
        try {

            charlie.executeForm(form1); // Deve falhar porque não está assinado
        } catch (AForm::NotSignedException &e) {
            cout << "ok" << endl;
        }

        std::cout << "\n--- Tentando assinar com nota baixa ---" << std::endl;
        try {
            alice.signForm(form1); // Deve falhar (150 < 145)
        } catch (AForm::GradeTooLowException &e) {
            cout << "ok" << endl;
        }

        std::cout << "\n--- Assinando com nota correta, mas tentando executar com nota baixa ---" << std::endl;
        try {
            bob.signForm(form1); // Sucesso na assinatura
            bob.executeForm(form1); // Deve falhar na execução (140 < 137)
        } catch (AForm::GradeTooLowException &e) {
            cout << "ok" << endl;
        }

        std::cout << "\n--- Execução com sucesso (Criará o arquivo home_shrubbery) ---" << std::endl;
        try {
            charlie.executeForm(form1);
            cout << "ok" << endl;
        } catch (AForm::GradeTooLowException &e) {
            cout << "fail" << endl;
        }
    }

    std::cout << "\n=========================================================" << std::endl;
    std::cout << "📋 TESTE 2: RobotomyRequestForm (Requer: Sign 72, Exec 45)" << std::endl;
    std::cout << "=========================================================" << std::endl;
    {
        Bureaucrat boss("Chefe", 40); // Consegue fazer tudo
        RobotomyRequestForm form2("Bender");

        boss.signForm(form2);

        std::cout << "\n--- Executando múltiplas vezes para testar os 50% de chance ---" << std::endl;
        for (int i = 0; i < 8; i++) {
            std::cout << "[Tentativa " << i + 1 << "]:" << std::endl;
            boss.executeForm(form2);
            std::cout << "-----------------------" << std::endl;
        }
    }

    std::cout << "\n=========================================================" << std::endl;
    std::cout << "📋 TESTE 3: PresidentialPardonForm (Requer: Sign 25, Exec 5)" << std::endl;
    std::cout << "=========================================================" << std::endl;
    {
        Bureaucrat vicePresident("Vice-Presidente", 20); // Consegue assinar, não executar
        Bureaucrat president("Presidente", 1);          // Deus no ecossistema

        PresidentialPardonForm form3("Arthur Dent");

        std::cout << "\n--- Tentando assinar e executar pelo Vice ---" << std::endl;
        try {
            vicePresident.signForm(form3);       // Sucesso
            cout << "ok" << endl;
        } catch (AForm::GradeTooLowException &e) {
            cout << "fail" << endl;
        }
        try {
            vicePresident.executeForm(form3);   // Falha (20 < 5)
        } catch (AForm::GradeTooLowException &e) {
            cout << "ok" << endl;
        }

        std::cout << "\n--- Execução com sucesso pelo Presidente ---" << std::endl;
        try {
            president.executeForm(form3);       // Sucesso!
            cout << "ok" << endl;
        } catch (AForm::GradeTooLowException &e) {
            cout << "fail" << endl;
        }
    }

    return 0;
}
