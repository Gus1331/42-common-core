
#include "easyfind/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // ---- Teste 1: Usando std::vector ----
    std::vector<int> meu_vector;
    meu_vector.push_back(10);
    meu_vector.push_back(20);
    meu_vector.push_back(30);
    meu_vector.push_back(40);
    meu_vector.push_back(50);
    
    std::cout << "--- Teste com Vector ---" << std::endl;
    int* ptr1 = easyfind(meu_vector, 30);
    if (ptr1 != 0) {
        std::cout << "Encontrado! Valor: " << *ptr1 << std::endl;
    }

    // ---- Teste 2: Usando std::list ----
    std::list<int> minha_list;
    minha_list.push_back(100);
    minha_list.push_back(200);
    minha_list.push_back(300);
    
    std::cout << "\n--- Teste com List ---" << std::endl;
    int* ptr2 = easyfind(minha_list, 200);
    if (ptr2 != 0) {
        std::cout << "Encontrado! Valor: " << *ptr2 << std::endl;
    }

    // ---- Teste : Valor inexistente ----
    
    std::cout << "\n--- Teste Valor inexistente ---" << std::endl;
    int* ptr3 = easyfind(minha_list, 555);
    if (ptr3 == 0) {
        std::cout << "Default retornado! Valor ptr: " << ptr3 << std::endl;
    }

    return 0;
}
