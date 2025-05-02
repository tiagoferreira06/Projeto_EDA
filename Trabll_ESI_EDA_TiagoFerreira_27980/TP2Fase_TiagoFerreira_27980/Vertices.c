/**
 * @file Vertices.c
 * @brief Implementacao das funcoes de manipulacao de vertices para o trabalho de Grafos.
 *
 * Este arquivo contem a implementacao das funcoes responsaveis pela criacao, insercao, busca, verificacao e remocao de vertices
 * em uma estrutura de grafo. Estas funcoes são essenciais para a manipulacao eficiente dos vertices dentro do grafo, permitindo
 * operacoes como adicionar novos vertices, verificar a existencia de um vertice, procurar um vertice especifico e remover vertices,
 * assim como gerenciar suas adjacencias.
 *
 * @date 25/05/2024
 * @autor Tiago Ferreira
 */

#include "Header.h"

#pragma region VERTICES

/**
 * @brief Cria um novo vertice.
 *
 * Esta funcao aloca memoria para um novo vertice e inicializa seus atributos.
 *
 * @param id O ID do vertice.
 * @param valor O valor do vertice.
 * @return Um ponteiro para o novo vertice.
 */
Vertice* CriaVertice(int id, int valor) {
	Vertice* aux = (Vertice*)malloc(sizeof(Vertice));

	aux->valor = valor;
	aux->id = id;
	aux->proxAdjacent = NULL;
	aux->proxVertice = NULL;

	return aux;

}


/**
 * @brief Insere um novo vertice na lista de vertices.
 *
 * Esta função insere um novo vertice na lista de vertices mantida pelo grafo.
 *
 * @param vertices Ponteiro para o inicio da lista de vertices.
 * @param novo Novo vertice a ser inserido.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O ponteiro atualizado para o inicio da lista de vertices.
 */
Vertice* InserirVertice(Vertice* vertices, Vertice* novo, bool* res) {
	*res = false;
	Vertice* anterior = NULL;

	//Grafo vazio
	if (vertices == NULL) {
		vertices = novo;
		//printf("Vertice inserido no inicio");
		return vertices;

	}

	if (ExisteVertice(vertices, novo->id) == 1) {
		//printf("Este vertice ja existe.");
		return vertices;

	}
	else
	{
		Vertice* aux = vertices;
		while (aux != NULL && aux->id < novo->id) { //achar o vertice anterior ao que vai inserir
			anterior = aux;
			aux = aux->proxVertice;
		}
		*res = true;
		if (anterior == NULL) { //inserir no inicio
			novo->proxVertice = vertices;
			vertices = novo;
		}
		else
		{
			novo->proxVertice = aux;
			anterior->proxVertice = novo;
		}
	}

	return vertices;
}


/**
 * @brief Verifica se um vertice com o ID especificado existe na lista de vertices.
 *
 * Esta funcao verifica se um vertice com o ID especificado ja existe na lista de vertices.
 *
 * @param inicio Ponteiro para o inicio da lista de vertices.
 * @param id O ID do vertice a ser verificado.
 * @return 1 se o vErtice existe, -1 se nao existe.
 */
int ExisteVertice(Vertice* inicio, int id) {

	Vertice* aux = inicio;

	while (aux != NULL) {
		if (aux->id == id) {
			return 1;
		}
		aux = aux->proxVertice;
	}

	return -1;

}


/**
 * @brief Elimina um vertice da lista de vertices.
 *
 * Esta funcao remove um vertice da lista de vertices mantida pelo grafo.
 *
 * @param vertices Ponteiro para o inicio da lista de vertices.
 * @param id O ID do vertice a ser removido.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O ponteiro atualizado para o início da lista de vertices.
 */
Vertice* EliminarVertice(Vertice* vertices, int id, bool* res) {
	*res = false;

	Vertice* aux = vertices;
	Vertice* anterior = NULL;

	while (aux->id < id) {
		anterior = aux;
		aux = aux->proxVertice;
	}

	//CASO SEJA O PRIMEIRO VERTICE
	if (anterior == NULL) {
		aux->proxAdjacent = EliminarTodasAdj(aux->proxAdjacent, res);
		if (*res == false) {
			return vertices;
		}
		vertices = aux->proxVertice;
	}
	else // PARA OUTROS CASOS 
	{
		anterior->proxVertice = aux->proxVertice;
	}
	free(aux);
	*res = true;
	return vertices;
}


/**
 * @brief Elimina as adjacencias de todos os vertices que possuem o ID especificado.
 *
 * Esta funcao remove as adjacencias de todos os vertices na lista de vertices mantida pelo grafo que possuem o
 * ID especificado.
 *
 * @param vertices Ponteiro para o inicio da lista de vertices.
 * @param id O ID das adjacencias a serem removidas.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O ponteiro atualizado para o inicio da lista de vertices.
 */
Vertice* EliminaAdjacenciaTodosVertices(Vertice* vertices, int id, bool* res) {
	*res = false;

	if (vertices == NULL) return NULL;

	Vertice* aux = vertices;

	while (aux != NULL) {
		aux->proxAdjacent = EliminaAdjacente(aux->proxAdjacent, id, res);
		aux = aux->proxVertice;
	}

	*res = true;
	return vertices;
}


/**
 * @brief Procura um vertice na lista de vertices pelo seu ID.
 *
 * Esta funcao procura um vertice na lista de vertices mantida pelo grafo pelo seu ID especificado.
 *
 * @param vertices Ponteiro para o inicio da lista de vertices.
 * @param id O ID do vertice a ser procurado.
 * @return Um ponteiro para o vertice se encontrado, NULL caso contrario.
 */
Vertice* ProcurarVertice(Vertice* vertices, int id) {
	if (vertices == NULL) return NULL;

	Vertice* aux = vertices;

	while (aux != NULL) {
		if (aux->id == id) {
			return aux;
		}
		aux = aux->proxVertice;
	}

	return NULL;
}

#pragma endregion