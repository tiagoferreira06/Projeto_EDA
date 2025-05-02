/**
 * @file Header.h
 * @brief Declaracao de estruturas e funcoes auxiliares para o trabalho de Grafos.
 *
 * Este arquivo contem a declaracao das estruturas e das funcoes auxiliares utilizadas no trabalho de Grafos,
 * incluindo a estrutura de vertice e adjacente para representar os elementos individuais do grafo, a estrutura de
 * grafo para representar o grafo em si, e as funcoes para criar, manipular e buscar elementos no grafo.
 *
 * @date 25/05/2024
 * @author Tiago Ferreira
 */


#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_VERTICES 25

 /**
  * @brief Estrutura para representar um vertice adjacente.
  */
typedef struct Adjacente {
	int id;
	int peso;
	int valor;
	struct Adjacente* prox;
}Adjacente;

/**
 * @brief Estrutura para representar um vertice de um grafo.
 */
typedef struct Vertice
{
	int valor;
	int id;
	bool visited;
	Adjacente* proxAdjacent;
	struct Vertice* proxVertice;
}Vertice;

/**
 * @brief Estrutura para representar um grafo.
 */
typedef struct Grafo {
	Vertice* inicioGrafo;	
	int numeroVertices;		
	int totVertices;		
}Grafo;

/**
 * @brief Estrutura para o calculo da soma maxima.
 */
typedef struct Resultado {
	int soma;
	Vertice* caminho;
	Grafo* grafo;
} Resultado;

#pragma region DECLARAR FUNÇÕES

Grafo* CriaGrafo(int total);
void MostrarGrafo(Vertice* grafo);

Vertice* CriaVertice(int id, int valor);
Vertice* InserirVertice(Vertice* vertices, Vertice* novo, bool* res);
int ExisteVertice(Vertice* inicio, int id);
Vertice* EliminarVertice(Vertice* vertices, int id, bool* res);
Vertice* EliminaAdjacenciaTodosVertices(Vertice* vertices, int id, bool* res);
Vertice* ProcurarVertice(Vertice* vertices, int id);

Adjacente* EliminarTodasAdj(Adjacente* lista, bool* res);
Adjacente* EliminaAdjacente(Adjacente* lista, int id, bool* res);
Adjacente* CriarAdjacencia(int id, int valor, int peso);
Adjacente* InserirAdjacencia(Adjacente* lista, int id, int valor, int peso);

Grafo* InserirVerticeGrafo(Grafo* grafo, Vertice* novo, bool* res);
int ExisteVerticeGrafo(Grafo* grafo, int id);
Grafo* EliminaVerticeGrafo(Grafo* grafo, int id, bool* res);
Vertice* ProcurarVerticeGrafo(Grafo* grafo, int id);
Grafo* InserirAdjacenciaGrafo(Grafo* grafo, int idOrigem, int idDestino, bool* res);
Grafo* EliminarAdjacenciaGrafo(Grafo* grafo, int idOrigem, int idDestino, bool* res);

bool carregarGrafoDeArquivo(const char* nomeArquivo, Grafo* grafo);

int AtualizaResultado(Resultado* resultado, int somaAtual, Vertice* caminhoAtual);
int BuscaCaminhoMaximo(Vertice* vertice, int somaAtual, Resultado* resultado);
Resultado* CaminhoSomaMaxima(Grafo* grafo);
void ImprimirSomaMaximaMatriz(Grafo* grafo);


int CalculaSomaCaminho(Grafo* grafo, int origem, int destino);
void imprimirSomaCaminho(Grafo* grafo, int origem, int destino);


#pragma endregion