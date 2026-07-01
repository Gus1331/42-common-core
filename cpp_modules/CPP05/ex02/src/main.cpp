
#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    // Inicializa o gerador de números aleatórios para o Robotomy
    std::srand(std::time(NULL));

    std::cout << "=========================================================" << std::endl;
    std::cout << "📋 TESTE 1: ShrubberyCreationForm (Requer: Sign 145, Exec 137)" << std::endl;
    std::cout << "=========================================================" << std::endl;
    {
        Bureaucrat alice("Alice", 150); // Nota muito baixa para tudo
        Bureaucrat bob("Bob", 140);     // Consegue assinar, mas não executar
        Bureaucrat charlie("Charlie", 130); // Consegue fazer tudo

        ShrubberyCreationForm form1("home");

        std::cout << "\n--- Tentando executar sem assinatura ---" << std::endl;
        charlie.executeForm(form1); // Deve falhar porque não está assinado

        std::cout << "\n--- Tentando assinar com nota baixa ---" << std::endl;
        alice.signForm(form1); // Deve falhar (150 < 145)

        std::cout << "\n--- Assinando com nota correta, mas tentando executar com nota baixa ---" << std::endl;
        bob.signForm(form1); // Sucesso na assinatura
        bob.executeForm(form1); // Deve falhar na execução (140 < 137)

        std::cout << "\n--- Execução com sucesso (Criará o arquivo home_shrubbery) ---" << std::endl;
        charlie.executeForm(form1); // Sucesso!
    }

    // std::cout << "\n=========================================================" << std::endl;
    // std::cout << "📋 TESTE 2: RobotomyRequestForm (Requer: Sign 72, Exec 45)" << std::endl;
    // std::cout << "=========================================================" << std::endl;
    // {
    //     Bureaucrat boss("Chefe", 40); // Consegue fazer tudo
    //     RobotomyRequestForm form2("Bender");

    //     boss.signForm(form2);

    //     std::cout << "\n--- Executando múltiplas vezes para testar os 50% de chance ---" << std::endl;
    //     for (int i = 0; i < 4; i++) {
    //         std::cout << "[Tentativa " << i + 1 << "]:" << std::endl;
    //         boss.executeForm(form2);
    //         std::cout << "-----------------------" << std::endl;
    //     }
    // }

    // std::cout << "\n=========================================================" << std::endl;
    // std::cout << "📋 TESTE 3: PresidentialPardonForm (Requer: Sign 25, Exec 5)" << std::endl;
    // std::cout << "=========================================================" << std::endl;
    // {
    //     Bureaucrat vicePresident("Vice-Presidente", 20); // Consegue assinar, não executar
    //     Bureaucrat president("Presidente", 1);          // Deus no ecossistema

    //     PresidentialPardonForm form3("Arthur Dent");

    //     std::cout << "\n--- Tentando assinar e executar pelo Vice ---" << std::endl;
    //     vicePresident.signForm(form3);       // Sucesso
    //     vicePresident.executeForm(form3);   // Falha (20 < 5)

    //     std::cout << "\n--- Execução com sucesso pelo Presidente ---" << std::endl;
    //     president.executeForm(form3);       // Sucesso!
    // }

    // std::cout << "\n=========================================================" << std::endl;
    // std::cout << "📋 TESTE CUSTOMIZADO: Polimorfismo através de ponteiros AForm" << std::endl;
    // std::cout << "=========================================================" << std::endl;
    // {
    //     Bureaucrat god("God Admin", 1);
        
    //     // Array de ponteiros da classe base apontando para as filhas (Polimorfismo pura)
    //     AForm* forms[3];
    //     forms[0] = new ShrubberyCreationForm("garden");
    //     forms[1] = new RobotomyRequestForm("Wall-E");
    //     forms[2] = new PresidentialPardonForm("Ford Prefect");

    //     for (int i = 0; i < 3; i++) {
    //         std::cout << "\nProcessando formulário: " << forms[i]->getName() << std::endl;
    //         god.signForm(*forms[i]);
    //         god.executeForm(*forms[i]);
    //         delete forms[i]; // Evitando memory leak (garanta que o destrutor de AForm é virtual!)
    //     }
    // }

    return 0;
}
