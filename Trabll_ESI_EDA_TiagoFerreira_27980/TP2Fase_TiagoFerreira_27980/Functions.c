/**
 * @file Functions.c
 * @brief Implementacoes das funcoes para manipulacao de grafos.
 *
 * Este arquivo contem as implementacoes das funcoes para criacao, manipulacao e busca em grafos.
 *
 * @date 25/04/2024
 * @author Tiago Ferreira
 */

#include "Header.h"

#pragma region GRAFO


/**
 * @brief Cria um novo grafo.
 *
 * Esta função aloca memoria para um novo grafo e inicializa seus atributos.
 *
 * @param total O numero total maximo de vertices permitidos no grafo.
 * @return Um ponteiro para o novo grafo.
 */
Grafo* CriaGrafo(int total) {
	
	Grafo* aux = (Grafo*)malloc(sizeof(Grafo));
	
	if (aux != NULL) {
		aux->inicioGrafo = NULL;
		aux->numeroVertices = 0;
		aux->totVertices = total;		
	}
	return aux;
}


/**
 * @brief Mostra o conteudo do grafo.
 *
 * Esta funcao exibe o conteudo do grafo na saida padrao.
 *
 * @param grafo Ponteiro para o inicio da lista de vertices do grafo.
 */
void MostrarGrafo(Vertice* grafo) {
	Vertice* aux = grafo;
	if (!aux) {
		printf("Vazio");
		return grafo;
	}
	while (aux != NULL) {
		printf("Vertice %d Valor: %d \n", aux->id, aux->valor);
		Adjacente* auxAdj = aux->proxAdjacent;
		while (auxAdj != NULL) {
			printf("\tAdjacente: %d Peso: %d Valor: %d\n", auxAdj->id, auxAdj->peso, auxAdj->valor);
			auxAdj = auxAdj->prox;

		}
		printf("---------------------------------------------");
		printf("\n");
		aux = aux->proxVertice;
	}
}

#pragma endregion

#pragma region GERIR GRAFO


/**
 * @brief Insere um novo vertice no grafo.
 *
 * Esta funcao insere um novo vertice na lista de vertices mantida pelo grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @param novo Novo vertice a ser inserido.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return 1 se o vertice foi inserido com sucesso, 0 caso contrario.
 */
Grafo* InserirVerticeGrafo(Grafo* grafo, Vertice* novo, int* res) {
	
	if (grafo->numeroVertices > grafo->totVertices) {
		return NULL;
	}
	
	*res = 1;

	if (ExisteVerticeGrafo(grafo, novo->id) == 1) {
		//printf("Vertice existente\n");
		return grafo;
	}

	grafo->inicioGrafo = InserirVertice(grafo->inicioGrafo, novo, res);

	if (*res == true) {
		grafo->numeroVertices++;
	}
}


/**
 * @brief Verifica se um vertice com o ID especificado existe no grafo.
 *
 * Esta funcao verifica se um vertice com o ID especificado ja existe no grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @param id O ID do vertice a ser verificado.
 * @return 1 se o vertice existe, -1 se nao existe.
 */
int ExisteVerticeGrafo(Grafo* grafo, int id) {

	int aux = ExisteVertice(grafo->inicioGrafo, id);

	return aux;
}


/**
 * @brief Remove um vertice do grafo.
 *
 * Esta funcao remove um vertice e suas adjacencias do grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @param id O ID do vertice a ser removido.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O grafo atualizado.
 */
Grafo* EliminaVerticeGrafo(Grafo* grafo, int id, bool* res) {
	*res = false;

	grafo->inicioGrafo = EliminarVertice(grafo->inicioGrafo, id, res);
	grafo->inicioGrafo = EliminaAdjacenciaTodosVertices(grafo->inicioGrafo, id, res);

	if (*res == true) {
		grafo->numeroVertices--;
	}

	return grafo;
}


/**
 * @brief Procura um vertice pelo ID no grafo.
 *
 * Esta funcao procura um vertice com o ID especificado no grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @param id O ID do vertice a ser procurado.
 * @return Um ponteiro para o vertice encontrado, ou NULL se nao encontrado.
 */
Vertice* ProcurarVerticeGrafo(Grafo* grafo, int id) {
	if (grafo == NULL) return NULL;

	return (ProcurarVertice(grafo->inicioGrafo, id));

}


/**
 * @brief Insere uma nova adjacencia no grafo.
 *
 * Esta funcao insere uma nova adjacencia entre dois vertices no grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @param idOrigem ID do vertice de origem da adjacencia.
 * @param idDestino ID do vertice de destino da adjacencia.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O grafo atualizado.
 */
Grafo* InserirAdjacenciaGrafo(Grafo* grafo, int idOrigem, int idDestino, bool* res) {
	*res = false;
	if (grafo == NULL) return NULL;


	Vertice* VerticeOrigem = ProcurarVerticeGrafo(grafo, idOrigem);
	Vertice* VerticeDestino = ProcurarVerticeGrafo(grafo, idDestino);
	int valorAdjacente = VerticeDestino->valor;
	int soma = VerticeOrigem->valor + VerticeDestino->valor;
	VerticeOrigem->proxAdjacent = InserirAdjacencia(VerticeOrigem->proxAdjacent, idDestino, valorAdjacente, soma);
	
	*res = true;
	return grafo;

}


/**
 * @brief Remove uma adjacencia do grafo.
 *
 * Esta funcao remove uma adjacencia entre dois vertices do grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @param idOrigem ID do vertice de origem da adjacencia.
 * @param idDestino ID do vertice de destino da adjacencia.
 * @param res Ponteiro para uma variavel que indicara se a operacao foi bem-sucedida.
 * @return O grafo atualizado.
 */
Grafo* EliminarAdjacenciaGrafo(Grafo* grafo, int idOrigem, int idDestino, bool* res) {
	*res = false;
	if (grafo == NULL) return NULL;

	Vertice* VerticeOrigem = ProcurarVerticeGrafo(grafo, idOrigem);
	Vertice* VerticeDestino = ProcurarVerticeGrafo(grafo, idDestino);

	VerticeOrigem->proxAdjacent = EliminaAdjacente(VerticeOrigem->proxAdjacent, idDestino, res);

	return grafo;
}

#pragma endregion

#pragma region DFS SOMA MAXIMA


/**
 * @brief Atualiza o resultado da busca do caminho com soma maxima.
 *
 * Esta funcao atualiza o resultado com a soma atual e o caminho atual, se a soma atual for maior que a soma atual do resultado.
 *
 * @param resultado Ponteiro para o resultado atual.
 * @param somaAtual A soma atual a ser comparada.
 * @param caminhoAtual O caminho atual a ser armazenado.
 * @return 1 em caso de sucesso e -1 em caso de falha.
 */
int AtualizaResultado(Resultado* resultado, int somaAtual, Vertice* caminhoAtual) {
	
	if (resultado == NULL) return -1;
	
	if (somaAtual > resultado->soma) {
		resultado->soma = somaAtual;
		resultado->caminho = caminhoAtual;
	}

	return 1;
}


/**
 * @brief Busca o caminho com soma maxima a partir de um vértice.
 *
 * Esta função realiza uma busca em profundidade a partir de um vértice para encontrar o caminho com soma máxima.
 *
 * @param vertice O vertice atual.
 * @param somaAtual A soma atual.
 * @param resultado Ponteiro para o resultado da busca.
 * @return 1 em caso de sucesso e -1 em caso de falha.
 */
int BuscaCaminhoMaximo(Vertice* vertice, int somaAtual, Resultado* resultado) {
	
	if (vertice == NULL) {
		return -1;
	}

	// Marcar o vértice como visitado
	vertice->visited = true;
	somaAtual += vertice->valor;

	// Atualizar o resultado se a soma atual for maior
	AtualizaResultado(resultado, somaAtual, vertice);

	// Recorrer os vértices adjacentes
	Adjacente* adjacente = vertice->proxAdjacent;
	while (adjacente != NULL) {
		Vertice* verticeAdjacente = ProcurarVerticeGrafo(resultado->grafo, adjacente->id);
		if (verticeAdjacente != NULL && !verticeAdjacente->visited) {
			BuscaCaminhoMaximo(verticeAdjacente, somaAtual, resultado);
		}
		adjacente = adjacente->prox;
	}

	// Desmarcar o vértice como visitado para permitir outras buscas
	vertice->visited = false;
	
	return 1;
}


/**
 * @brief Encontra o caminho com a soma máxima em um grafo.
 *
 * Esta função encontra o caminho com a soma máxima em um grafo.
 *
 * @param grafo Ponteiro para o grafo.
 * @return Ponteiro para o resultado da busca.
 */
Resultado* CaminhoSomaMaxima(Grafo* grafo) {
	Resultado* resultado = (Resultado*)malloc(sizeof(Resultado));
	if (resultado == NULL) {
		//printf("Erro ao alocar memória para o resultado.\n");
		return;
	}
	resultado->soma = 0;
	resultado->caminho = NULL;
	resultado->grafo = grafo;

	Vertice* vertice = grafo->inicioGrafo;
	while (vertice != NULL) {
		BuscaCaminhoMaximo(vertice, 0, resultado);
		vertice = vertice->proxVertice;
	}

	return resultado;
}

void ImprimirSomaMaximaMatriz(Grafo* grafo) {

	Resultado* resultado = CaminhoSomaMaxima(grafo);

	if (resultado == NULL) return NULL;

	Vertice* caminho = resultado->caminho;

	printf("Soma Maxima: %d\n", resultado->soma);
	printf("Caminho: ");

	while (caminho != NULL) {
		printf("%d (%d)", caminho->id, caminho->valor);
		caminho = caminho->proxVertice;
	}
	printf("\n");

	free(resultado);
}

#pragma endregion

#pragma region DFS SOMA CAMINHO

bool BuscaProfundidade(Vertice* vertice, int destino, bool* visitado, int* soma, Grafo* grafo) {
	// Marcar o vértice atual como visitado
	visitado[vertice->id] = true;

	// Adicionar o valor do vértice atual à soma
	*soma += vertice->valor;

	// Se o vértice atual for o destino, retornar true
	if (vertice->id == destino) {
		return true;
	}

	// Percorrer os vértices adjacentes
	Adjacente* adjacente = vertice->proxAdjacent;
	while (adjacente != NULL) {
		// Obter o vértice adjacente
		Vertice* verticeAdjacente = ProcurarVerticeGrafo(grafo, adjacente->id);

		// Se o vértice adjacente não foi visitado, realizar uma busca em profundidade a partir dele
		if (!visitado[adjacente->id] && BuscaProfundidade(verticeAdjacente, destino, visitado, soma, grafo)) {
			return true;
		}

		// Avançar para o próximo vértice adjacente
		adjacente = adjacente->prox;
	}

	// Se nenhum caminho para o destino foi encontrado a partir deste vértice, retornar false
	return false;
}


int CalculaSomaCaminho(Grafo* grafo, int origem, int destino) {
	// Verificar se os vértices de origem e destino existem no grafo
	Vertice* verticeOrigem = ProcurarVerticeGrafo(grafo, origem);
	Vertice* verticeDestino = ProcurarVerticeGrafo(grafo, destino);
	if (verticeOrigem == NULL || verticeDestino == NULL) {
		//printf("Um ou ambos os vértices não existem no grafo.\n");
		return -1;
	}

	// Inicializar um array para marcar os vértices visitados durante a busca em profundidade
	int numVertices = grafo->totVertices;
	bool* visitado = (bool*)malloc(numVertices * sizeof(bool));
	for (int i = 0; i < numVertices; ++i) {
		visitado[i] = false;
	}

	// Inicializar a soma como zero
	int soma = 0;

	// Realizar a busca em profundidade para encontrar o caminho entre os vértices de origem e destino
	if (!BuscaProfundidade(verticeOrigem, destino, visitado, &soma, grafo)) {
		//printf("Não há caminho entre os vértices %d e %d.\n", origem, destino);
		free(visitado);
		return -1;
	}

	// Liberar a memória alocada para o array de visitados
	free(visitado);

	// Retornar a soma dos vértices no caminho
	return soma;
}

void imprimirSomaCaminho(Grafo* grafo, int origem, int destino) {

	int r = CalculaSomaCaminho(grafo, origem, destino);

	printf("A soma do vertice %d ao vertice %d = %d\n\n", origem, destino, r);
}

#pragma endregion
