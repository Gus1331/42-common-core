
#include <iostream>
#include <string.h>
#include "Bureaucrat/Bureaucrat.hpp"
#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Intern/Intern.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string RESET = "\033[0m";

    std::cout << YELLOW << "=== Instanciando o Burocrata e o Intern ===" << RESET << std::endl;
    Bureaucrat boss("Boss", 1);
    Intern someRandomIntern;
    AForm* rrf = NULL;

    std::cout << "\n" << YELLOW << "=== Teste 1: Robotomy Request (Caso de Sucesso) ===" << RESET << std::endl;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf; // Evitando leak de memória
            rrf = NULL;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exceção capturada: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << YELLOW << "=== Teste 2: Shrubbery Creation (Caso de Sucesso) ===" << RESET << std::endl;
    try {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
            rrf = NULL;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exceção capturada: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << YELLOW << "=== Teste 3: Presidential Pardon (Caso de Sucesso) ===" << RESET << std::endl;
    try {
        rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
            rrf = NULL;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exceção capturada: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << YELLOW << "=== Teste 4: Formulário Inválido (Caso de Erro) ===" << RESET << std::endl;
    try {
        // Deve printar a mensagem de erro explícita e retornar um ponteiro nulo (NULL)
        rrf = someRandomIntern.makeForm("coffee request", "Intern");
        if (rrf == NULL) {
            std::cout << GREEN << "Sucesso: O ponteiro retornado é NULL para formulário inválido." << RESET << std::endl;
        } else {
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exceção capturada: " << e.what() << RESET << std::endl;
    }

    return 0;
}
