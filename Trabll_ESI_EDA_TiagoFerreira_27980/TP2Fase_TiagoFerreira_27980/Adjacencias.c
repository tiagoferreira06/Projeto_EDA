/**
 * @file Adjacencias.c
 * @brief Implementacao das funcoes de manipulacao de adjacencias para o trabalho de Grafos.
 *
 * Este arquivo contem a implementacao das funcoes responsaveis pela criacao, insercao, remocao e eliminacao de adjacencias
 * em uma estrutura de grafo. Estas funcoes sao cruciais para a manipulacao eficiente das adjacencias dos vertices dentro do grafo,
 * permitindo operacoes como adicionar novas adjacencias, remover adjacencias especificas e eliminar todas as adjacencias de um vertice.
 *
 * @date 25/05/2024
 * @autor Tiago Ferreira
 */


#include "Header.h"

#pragma region ADJACENCIAS


/**
 * @brief Elimina todas as adjacencias de uma lista de adjacencias.
 *
 * Esta funcao remove todas as adjacencias de uma lista de adjacencias.
 *
 * @param lista Ponteiro para o inicio da lista de adjacencias.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O ponteiro atualizado para o inicio da lista de adjacencias.
 */
Adjacente* EliminarTodasAdj(Adjacente* lista, bool* res) {
	*res = false;

	Adjacente* aux = lista;

	while (aux != NULL) {
		if (aux) {
			lista = aux->prox;
		}
		free(aux);
		aux = lista;
	}
	lista = NULL;
	*res = true;
	return lista;
}


/**
 * @brief Elimina uma adjacencia especifica de uma lista de adjacencias.
 *
 * Esta funcao remove uma adjacencia especifica de uma lista de adjacencias.
 *
 * @param lista Ponteiro para o inicio da lista de adjacencias.
 * @param id O ID da adjacência a ser removida.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O ponteiro atualizado para o inicio da lista de adjacencias.
 */
Adjacente* EliminaAdjacente(Adjacente* lista, int id, bool* res) {
	*res = false;
	Adjacente* anterior = NULL;

	if (lista == NULL) return NULL;

	Adjacente* aux = lista;

	while (aux != NULL && aux->id != id) {
		anterior = aux;
		aux = aux->prox;
	}

	if (!aux) return lista;

	if (anterior == NULL) {
		lista = aux->prox;
	}
	else
	{
		anterior->prox = aux->prox;
	}

	free(aux);
	*res = true;
	return lista;
}


/**
 * @brief Cria uma nova adjacencia.
 *
 * Esta funcao aloca memoria para uma nova adjacencia e inicializa seu ID.
 *
 * @param id O ID da adjacencia.
 * @param peso O peso da adjacencia.
 * @param valor O valor da adjacencia.
 * @return Um ponteiro para a nova adjacencia.
 */
Adjacente* CriarAdjacencia(int id, int valor, int peso) {
	Adjacente* aux;

	aux = (Adjacente*)malloc(sizeof(Adjacente));
	if (aux == NULL) return NULL;

	aux->id = id;
	aux->peso = peso;
	aux->prox = NULL;
	aux->valor = valor;

	return aux;
}


/**
 * @brief Insere uma nova adjacencia na lista de adjacencias.
 *
 * Esta funcao insere uma nova adjacencia na lista de adjacencias mantida pelo vertice.
 *
 * @param lista Ponteiro para o inicio da lista de adjacencias.
 * @param id O ID do vertice adjacente a ser inserido.
 * @param peso O peso da adjacencia.
 * @param valor O valor da adjacencia.
 * @return O ponteiro atualizado para o inicio da lista de adjacencias.
 */
Adjacente* InserirAdjacencia(Adjacente* lista, int id, int valor, int peso) {
	Adjacente* aux;

	aux = CriarAdjacencia(id, valor, peso);

	if (aux == NULL) return NULL;

	if (lista == NULL) {
		lista = aux;
	}
	else
	{
		Adjacente* aux2 = lista;
		while (aux2->prox != NULL) {
			aux2 = aux2->prox;
		}
		aux2->prox = aux;

	}

	return lista;
}


#pragma endregion