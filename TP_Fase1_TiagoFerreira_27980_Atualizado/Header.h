/**
 * @file Header.h
 * @brief Declaração de estruturas e funções auxiliares para o arquivo main.c.
 *
 * Este arquivo contém a declaração das estruturas e das funções auxiliares utilizadas no arquivo main.c,
 * incluindo a estrutura No para representar os elementos individuais da matriz, a estrutura Matriz para
 * representar a matriz, e as funções para carregar dados de um arquivo para a matriz, imprimir a matriz,
 * criar uma nova linha, criar uma nova coluna, remover uma linha e remover uma coluna.
 *
 * @date 15/05/2024
 * @author Tiago Ferreira
 */

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#pragma region EstruturaParaMatriz

typedef struct No No;
typedef struct Matriz Matriz;
 
/*
  * @brief Estrutura para representar os elementos individuais da matriz.
  */
 struct No {
	int n;
	No* pbaixo;
	No* pdireita;
};

/**
 * @brief Estrutura para representar a matriz.
 */
struct Matriz {
	int coluna;
	int linha;
	No* ini;
};

#pragma endregion

#pragma region imprimirLista
void imprimirLista(Matriz* matriz);
#pragma endregion

#pragma region CriaListaMatriz
Matriz* CriaLista(int linhas, int colunas);
#pragma endregion

#pragma region ProcurarNumeroMatriz
No* ProcurarNumeroMatriz(Matriz* matriz, int linha, int coluna);
#pragma endregion

#pragma region FicheiroParaListaMatriz
int FicheiroParaLista(Matriz* matriz, const char* fileName);
#pragma endregion

#pragma region AdicionarLinha
int AdicionarLinha(Matriz* matriz, int posicao, int num[]);
#pragma endregion

#pragma region AdicionarColuna
int AdicionarColuna(Matriz* matriz, int posicao, int num[]);
#pragma endregion

#pragma region eliminarLinha
int eliminarLinha(Matriz* matriz, int pos);
#pragma endregion

#pragma region eliminarColuna
int eliminarColuna(Matriz* matriz, int pos);
#pragma endregion

#pragma region SomaMaxima
int SomaMaximaAux(Matriz* matriz, int linha, int* colunasUsadas);
int SomaMaxima(Matriz* matriz);
#pragma endregion