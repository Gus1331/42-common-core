
#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/Form.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
std::cout << "========= TESTE 1: Sucesso ao Assinar =========" << std::endl;
    try {
        Bureaucrat chefe("Chefe", 10);
        Form contrato("Contrato de Aluguel", 45, 30);

        std::cout << chefe << std::endl;
        std::cout << contrato << std::endl;

        // O chefe tem nota 10, o contrato exige 45. Deve funcionar!
        chefe.signForm(contrato);

        std::cout << contrato << std::endl; // Deve mostrar como assinado
    }
    catch (std::exception &e) {
        std::cout << "Excecao inesperada: " << e.what() << std::endl;
    }

    std::cout << "\n========= TESTE 2: Falha por Nota Baixa =========" << std::endl;
    try {
        Bureaucrat estagiario("Estagiario", 120);
        Form alvara("Alvara de Construcao", 50, 20);

        std::cout << estagiario << std::endl;
        std::cout << alvara << std::endl;

        // O estagiario tem nota 120, o alvará exige 50. Vai falhar!
        estagiario.signForm(alvara);

        std::cout << alvara << std::endl; // Deve continuar como NAO assinado
    }
    catch (std::exception &e) {
        std::cout << "Excecao inesperada: " << e.what() << std::endl;
    }

    std::cout << "\n========= TESTE 3: Criacao de Form Invalido (Nota muito alta) =========" << std::endl;
    try {
        Form formInvalido("Formulario Secreto", 0, 50); // Nota 0 nao existe
    }
    catch (std::exception &e) {
        std::cout << "Sucesso ao pegar excecao: " << e.what() << std::endl;
    }

    std::cout << "\n========= TESTE 4: Criacao de Form Invalido (Nota muito baixa) =========" << std::endl;
    try {
        Form formInvalido2("Formulario Inutil", 151, 50); // Nota 151 nao existe
    }
    catch (std::exception &e) {
        std::cout << "Sucesso ao pegar excecao: " << e.what() << std::endl;
    }

    return 0;
}
