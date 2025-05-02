#include "Header.h"

//#pragma region CARREGAR FICHEIRO
//
//bool carregarGrafoDeArquivo(const char* nomeArquivo, Grafo* grafo) {
//	FILE* arquivo = fopen(nomeArquivo, "r");
//	if (arquivo == NULL) {
//		printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
//		return false;
//	}
//
//	int linhas = 0;
//	char linha[100]; // Tamanho arbitrário, ajuste conforme necessário
//
//	// Ler o arquivo e atribuir os valores aos vértices do grafo
//	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
//		Vertice* novoVertice = NULL;
//		Vertice* verticeAnterior = NULL;
//
//		char* token = strtok(linha, ";");
//		while (token != NULL) {
//			int id = atoi(token);
//
//
//			// Criar um novo vértice
//			Vertice* vertice = CriaVertice(id);
//			if (vertice == NULL) {
//				printf("Erro ao criar vértice\n");
//				fclose(arquivo);
//				return false;
//			}
//
//			// Inserir o novo vértice no grafo
//			if (verticeAnterior == NULL) {
//				// Primeiro vértice na linha
//				novoVertice = vertice;
//			}
//			else {
//				// Conectar o vértice anterior ao novo vértice
//				verticeAnterior->proxVertice = vertice;
//			}
//
//			// Atualizar o vértice anterior
//			verticeAnterior = vertice;
//
//			// Próximo token
//			token = strtok(NULL, ";");
//		}
//
//		// Atualizar a lista de vértices do grafo
//		if (grafo->inicioGrafo == NULL) {
//			// Primeira linha do arquivo
//			grafo->inicioGrafo = novoVertice;
//		}
//		else {
//			// Conectar o último vértice da linha ao novo vértice
//			Vertice* ultimoVertice = grafo->inicioGrafo;
//			while (ultimoVertice->proxAdjacent != NULL) {
//				ultimoVertice = ultimoVertice->proxAdjacent;
//			}
//			ultimoVertice->proxAdjacent = novoVertice;
//		}
//
//		// Mover para a próxima linha
//		linhas++;
//	}
//
//	fclose(arquivo);
//	return true;
//}
//
//
//#pragma endregion