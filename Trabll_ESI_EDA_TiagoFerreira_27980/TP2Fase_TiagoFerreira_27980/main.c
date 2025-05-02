/**
 * @mainpage Trabalho de Estrutura de Dados - Grafos
 *
 * @section intro_sec Introducao
 *
 * Este trabalho consiste na implementacao de operacoes basicas em grafos utilizando a linguagem de programacao C.
 * Inclui a criacao de um grafo, insercao e remocao de vertices e arestas, busca de caminho com soma maxima e exibicao do grafo.
 *
 * @section func_sec Alguma das Funcionalidades Implementadas
 *
 * - Criacao de um grafo vazio
 * - Insercao e remocao de vertices e arestas
 * - Busca de caminho com a maior soma
 * - Exibicao do grafo
 *
 * @section example_sec Exemplo
 *
 * Aqui esta um exemplo simples de como criar um grafo, adicionar alguns vertices e arestas, e buscar o caminho com a maior soma:
 *
 * @code{.c}
 * #include <stdio.h>
 * #include "Header.h"
 *
 * int main() {
 *     // Criar um grafo
 *     Grafo* grafo = CriaGrafo(10);
 *
 *     // Adicionar alguns vertices e arestas
 *     InserirVerticeGrafo(grafo, CriaVertice(1,563));
 *     InserirVerticeGrafo(grafo, CriaVertice(2,100));
 *     InserirAdjacenciaGrafo(grafo, 1, 2);
 *      
 *     MostrarGrafo(grafo->inicioGrafo);
 * 
 *     // Buscar o caminho com a maior soma
 *     Resultado* resultado = CaminhoSomaMaxima(grafo);
 *
 *     return 0;
 * }
 * @endcode
 *
 * @section notes_sec Notas
 *
 * - Todas as funcionalidades foram implementadas conforme especificado no enunciado da disciplina.
 * - O codigo fonte esta organizado em seis arquivos: main.c, functions.c, Vertices.c, Adjacencias.c, GereFicheiro.c e Header.h.
 * - Cada arquivo contem um conjunto de funcionalidades relacionadas.
 *
 * @section author_sec Autor
 *
 * Este trabalho foi desenvolvido por Tiago Ferreira.
 */


#include "../TP2Fase_TiagoFerreira_27980/Header.h"

int main() {
    bool* res = false;
    Grafo* grafo = CriaGrafo(MAX_VERTICES);


#pragma endregion

#pragma region GRAFO

    InserirVerticeGrafo(grafo, CriaVertice(1, 7), &res);
    InserirVerticeGrafo(grafo, CriaVertice(2, 53), &res);
    InserirVerticeGrafo(grafo, CriaVertice(3, 183), &res);
    InserirVerticeGrafo(grafo, CriaVertice(4, 439), &res);
    InserirVerticeGrafo(grafo, CriaVertice(5, 863), &res);
    InserirVerticeGrafo(grafo, CriaVertice(6, 497), &res);
    InserirVerticeGrafo(grafo, CriaVertice(7, 383), &res);
    InserirVerticeGrafo(grafo, CriaVertice(8, 563), &res);
    InserirVerticeGrafo(grafo, CriaVertice(9, 79), &res);
    InserirVerticeGrafo(grafo, CriaVertice(10, 973), &res);
    InserirVerticeGrafo(grafo, CriaVertice(11, 287), &res);
    InserirVerticeGrafo(grafo, CriaVertice(12, 63), &res);
    InserirVerticeGrafo(grafo, CriaVertice(13, 343), &res);
    InserirVerticeGrafo(grafo, CriaVertice(14, 169), &res);
    InserirVerticeGrafo(grafo, CriaVertice(15, 583), &res);
    InserirVerticeGrafo(grafo, CriaVertice(16, 627), &res);
    InserirVerticeGrafo(grafo, CriaVertice(17, 343), &res);
    InserirVerticeGrafo(grafo, CriaVertice(18, 773), &res);
    InserirVerticeGrafo(grafo, CriaVertice(19, 959), &res);
    InserirVerticeGrafo(grafo, CriaVertice(20, 943), &res);
    InserirVerticeGrafo(grafo, CriaVertice(21, 767), &res);
    InserirVerticeGrafo(grafo, CriaVertice(22, 473), &res);
    InserirVerticeGrafo(grafo, CriaVertice(23, 103), &res);
    InserirVerticeGrafo(grafo, CriaVertice(24, 699), &res);
    InserirVerticeGrafo(grafo, CriaVertice(25, 303), &res);

	InserirAdjacenciaGrafo(grafo, 1, 2, &res);
	InserirAdjacenciaGrafo(grafo, 2, 3, &res);
	InserirAdjacenciaGrafo(grafo, 3, 4, &res);
	InserirAdjacenciaGrafo(grafo, 4, 5, &res);
	InserirAdjacenciaGrafo(grafo, 6, 7, &res);
	InserirAdjacenciaGrafo(grafo, 7, 8, &res);
	InserirAdjacenciaGrafo(grafo, 8, 9, &res);
	InserirAdjacenciaGrafo(grafo, 9, 10, &res);
	InserirAdjacenciaGrafo(grafo, 11, 12, &res);
	InserirAdjacenciaGrafo(grafo, 12, 13, &res);
	InserirAdjacenciaGrafo(grafo, 13, 14, &res);
	InserirAdjacenciaGrafo(grafo, 14, 15, &res);
	InserirAdjacenciaGrafo(grafo, 16, 17, &res);
	InserirAdjacenciaGrafo(grafo, 17, 18, &res);
	InserirAdjacenciaGrafo(grafo, 18, 19, &res);
	InserirAdjacenciaGrafo(grafo, 19, 20, &res);
	InserirAdjacenciaGrafo(grafo, 21, 22, &res);
	InserirAdjacenciaGrafo(grafo, 22, 23, &res);
	InserirAdjacenciaGrafo(grafo, 23, 24, &res);
	InserirAdjacenciaGrafo(grafo, 24, 25, &res);
	InserirAdjacenciaGrafo(grafo, 1, 6, &res);
	InserirAdjacenciaGrafo(grafo, 6, 11, &res);
	InserirAdjacenciaGrafo(grafo, 11, 16, &res);
	InserirAdjacenciaGrafo(grafo, 16, 21, &res);
	InserirAdjacenciaGrafo(grafo, 2, 7, &res);
	InserirAdjacenciaGrafo(grafo, 7, 12, &res);
	InserirAdjacenciaGrafo(grafo, 12, 17, &res);
	InserirAdjacenciaGrafo(grafo, 17, 22, &res);
	InserirAdjacenciaGrafo(grafo, 3, 8, &res);
	InserirAdjacenciaGrafo(grafo, 8, 13, &res);
	InserirAdjacenciaGrafo(grafo, 13, 18, &res);
	InserirAdjacenciaGrafo(grafo, 18, 23, &res);
	InserirAdjacenciaGrafo(grafo, 4, 9, &res);
	InserirAdjacenciaGrafo(grafo, 9, 14, &res);
	InserirAdjacenciaGrafo(grafo, 14, 19, &res);
	InserirAdjacenciaGrafo(grafo, 19, 24, &res);
	InserirAdjacenciaGrafo(grafo, 5, 10, &res);
	InserirAdjacenciaGrafo(grafo, 10, 15, &res);
	InserirAdjacenciaGrafo(grafo, 15, 20, &res);
	InserirAdjacenciaGrafo(grafo, 20, 25, &res);

#pragma endregion


    //EliminarAdjacenciaGrafo(grafo, 2, 5, &res);
    //EliminaVerticeGrafo(grafo, 8, &res);

    MostrarGrafo(grafo->inicioGrafo);
    imprimirSomaCaminho(grafo, 6, 10);

    ImprimirSomaMaximaMatriz(grafo);
    
    return 0;
}