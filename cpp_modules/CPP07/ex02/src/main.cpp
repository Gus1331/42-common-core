#include <iostream>
#include "Array/Array.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Uma struct simples para testar o comportamento com tipos complexos/customizados
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    std::cout << "=== TESTE 1: Construtor Padrão (Vazio) ===" << std::endl;
    {
        Array<int> emptyArray;
        std::cout << "Tamanho do array vazio: " << emptyArray.size() << std::endl;
    }

    std::cout << "\n=== TESTE 2: Construtor com Tamanho e Inicialização ===" << std::endl;
    {
        unsigned int size = 5;
        Array<int> intArray(size);
        std::cout << "Tamanho do intArray: " << intArray.size() << std::endl;
        
        std::cout << "Valores padrão (devem ser 0): ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Modificando os valores
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = (i + 1) * 10;
        }

        std::cout << "Valores após modificação: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== TESTE 3: Construtor de Cópia (Deep Copy) ===" << std::endl;
    {
        Array<std::string> original(3);
        original[0] = "42";
        original[1] = "Koala";
        original[2] = "Crow";

        std::cout << "Original antes da cópia: " << original[1] << std::endl;

        // Chamando o construtor de cópia
        Array<std::string> copia(original);
        std::cout << "Cópia antes da modificação: " << copia[1] << std::endl;

        // Modificando a cópia para garantir que não afeta o original
        copia[1] = "Rat";
        std::cout << "Cópia após modificação: " << copia[1] << std::endl;
        std::cout << "Original pós modificação da cópia (deve continuar igual): " << original[1] << std::endl;
    }

    std::cout << "\n=== TESTE 4: Operador de Atribuição (=) ===" << std::endl;
    {
        Array<double> arr1(3);
        arr1[0] = 1.1;
        arr1[1] = 2.2;
        arr1[2] = 3.3;

        Array<double> arr2(2);
        arr2[0] = 42.42;
        
        std::cout << "arr2 antes da atribuição (tamanho " << arr2.size() << "): " << arr2[0] << std::endl;
        
        // Atribuição
        arr2 = arr1;
        
        std::cout << "arr2 após atribuição (tamanho " << arr2.size() << "): " << arr2[1] << std::endl;
        
        // Modifica arr1 para testar independência
        arr1[1] = 99.99;
        std::cout << "arr1 modificado: " << arr1[1] << std::endl;
        std::cout << "arr2 deve continuar intacto: " << arr2[1] << std::endl;
    }

    std::cout << "\n=== TESTE 5: Tipos de Dados Customizados (Structs) ===" << std::endl;
    {
        Array<Point> points(2);
        points[0] = Point(5, 10);
        
        std::cout << "Point[0]: " << points[0] << std::endl;
        std::cout << "Point[1] (default): " << points[1] << std::endl;
    }

    std::cout << "\n=== TESTE 6: Tratamento de Exceções (Out of Bounds) ===" << std::endl;
    {
        Array<int> testBounds(4);
        
        // Testando índice válido superior limite
        try {
            std::cout << "Acessando índice 3: " << testBounds[3] << " -> OK!" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado: " << e.what() << std::endl;
        }

        // Testando índice fora do limite (tamanho)
        try {
            std::cout << "Tentando acessar índice 4 (out of bounds)..." << std::endl;
            std::cout << testBounds[4] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Sucesso! Exceção capturada: " << e.what() << std::endl;
        }

        // Testando índice negativo (como o parâmetro é unsigned, ele vai virar um número gigante)
        try {
            std::cout << "Tentando acessar índice -1 (out of bounds)..." << std::endl;
            // Forçando um cast ou apenas passando um valor inválido. 
            // O operador [] geralmente recebe unsigned int, então -1 vira UINT_MAX.
            std::cout << testBounds[-1] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Sucesso! Exceção capturada para índice inválido: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== TESTE 7: Const Array (Acesso em modo Ready-Only) ===" << std::endl;
    {
        Array<int> normalArray(2);
        normalArray[0] = 42;
        
        // Criando uma referência constante para testar o operador[] const
        const Array<int>& constArray = normalArray;
        std::cout << "Acessando constArray[0]: " << constArray[0] << std::endl;
        
        // A linha abaixo não deve compilar se descomentada (comportamento correto):
        // constArray[0] = 24; 
    }

    std::cout << "\n--- Todos os testes finalizados ---" << std::endl;
    return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
