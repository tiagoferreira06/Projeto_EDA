/**
 * @mainpage Projeto de Manipulacaoo de Matrizes
 *
 * @section intro_sec Introducao
 *
 * Este projeto tem como objetivo fornecer funcoes para manipulacao de matrizes, incluindo carregar dados de um arquivo,
 * adicionar ou remover linhas e colunas, imprimir a matriz e calcular a soma maxima de numeros na matriz onde nem a linha
 * nem a coluna podem ser repetidas.
 *
 * @section start_sec Como Comecar
 *
 * Para comecar a usar este projeto, você pode incluir o arquivo Header.h em seu codigo e utilizar as funcoes fornecidas
 * para manipular matrizes. Veja o exemplo abaixo para uma demonstracao simples de como usar algumas dessas funcoes:
 *
 * @code{.c}
 * #include "Header.h"
 * #include <stdio.h>
 *
 * int main() {
 *     // Exemplo de uso das funcoes
 *     Matriz* matriz = CriaLista(3, 3); // Cria uma matriz 3x3
 *     FicheiroParaLista(matriz, "dados.txt"); // Carrega dados de um arquivo
 *     imprimirLista(matriz); // Imprime a matriz
 *     // Mais operações de manipulação de matriz...
 *     return 0;
 * }
 * @endcode
 */

 /**
  * @file main.c
  * @brief Este arquivo contem a função principal para executar as funcoes auxiliares.
  *
  * Este arquivo contem a funcao principal que demonstra o uso das funcoes auxiliares para manipulacao de uma matriz.
  * As funcoes incluem carregar dados de um arquivo para a matriz, imprimir a matriz, criar uma nova linha,
  * remover uma coluna e calcular a soma maxima de numeros na matriz onde nem a linha nem a coluna podem ser repetidas.
  *
  * @date 15/05/2024
  * @author Tiago Ferreira
  */

#include <stdio.h>
#include "Header.h"

#pragma region main

 /**
  * @brief Funcao principal
  *
  * Esta funcao demonstra o uso das funcoes auxiliares para manipulacao de uma matriz.
  *
  * @return 1 se o programa for executado com sucesso.
  */

int main() {
    int num[] = { 1, 3 , 45, 3, 1 };

    // Cria uma matriz de 5x5
    Matriz* matriz = CriaLista(5, 5);
    // Carrega dados de um arquivo para a matriz
    FicheiroParaLista(matriz,"dados.txt");

    imprimirLista(matriz);
    printf("\n\n");

    //AdicionarLinha(matriz, 1, num);
    //imprimirLista(matriz);
    //printf("\n\n");
    //AdicionarColuna(matriz, 5, num);
    //eliminarColuna(matriz, 1);
    imprimirLista(matriz);
    printf("\n");
    printf("%d", SomaMaxima(matriz));
    return 1;
}

#pragma endregion