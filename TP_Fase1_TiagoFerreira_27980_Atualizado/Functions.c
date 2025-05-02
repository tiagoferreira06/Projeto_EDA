/**
 * @file Functions.c
 * @brief Contém funções auxiliares para manipulação de matrizes.
 *
 * Este arquivo contém as implementações das funções auxiliares para manipulação de matrizes,
 * incluindo carregar dados de um arquivo para a matriz, imprimir a matriz, criar uma nova linha,
 * criar uma nova coluna, remover uma linha, remover uma coluna e calcular a soma máxima de números
 * na matriz onde nem a linha nem a coluna podem ser repetidas.
 *
 * @date 15/05/2024
 * @author Tiago Ferreira
 */

    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    #include "Header.h"

#pragma region CriaListaMatriz

    /**
     * @brief Cria uma nova matriz com o numero especificado de linhas e colunas.
     *
     * Aloca memoria para uma nova matriz e inicializa todos os elementos com zero.
     *
     * @param linhas Numero de linhas da matriz.
     * @param colunas Numero de colunas da matriz.
     */

    Matriz* CriaLista(int linhas, int colunas) {
        No* iniciomatriz = NULL;
        No* esquerda = NULL;
        No* primeiro = NULL;
        No* cima = NULL;

        int i = 0;
        int y = 0;

        for ( i = 0; i < linhas; i++) {
            esquerda = NULL;
            primeiro = NULL;

            for ( y = 0; y < colunas; y++) {
                No* novo = (No*)calloc(1, sizeof(No));
                novo->n = 0;

                if (!iniciomatriz) {
                    iniciomatriz = novo;
                }
                if (y == 0) {
                    primeiro = novo;
                }
                if (esquerda != NULL) {
                    esquerda->pdireita = novo;
                }
                esquerda = novo;
                if (cima != NULL) {
                    cima->pbaixo = novo;
                }
                cima = novo;
            }
            cima = primeiro;
        }
        Matriz* matriz = (Matriz*)calloc(1, sizeof(Matriz));
        matriz->ini = iniciomatriz;
        matriz->coluna = y;
        matriz->linha = i;

        return matriz;
    }

#pragma endregion

#pragma region FicheiroParaListaMatriz

    /*
    * Nao consigo passar para a segunda linha
    * 
    int FicheiroParaLista(Matriz* matriz, const char* nomeArquivo) {
   
        FILE* arquivo = fopen(nomeArquivo, "r");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo.\n");
            return -1;
        }

        No* atual = matriz->ini;
        char separador;

        for (int linha = 0; linha < matriz->linha; linha++) {
            for (int coluna = 0; coluna < matriz->coluna; coluna++) {
                if (fscanf(arquivo, "%d%c", &atual->n, &separador) != 2 || separador != ';') {
                    printf("Erro ao ler valor do arquivo.\n");
                    fclose(arquivo);
                    return -1;
                }
         
                atual = atual->pdireita;
            }
            atual = atual->pbaixo;
        }

        fclose(arquivo);
    }
    */


    /**
     * @brief Carrega dados de um arquivo para a matriz.
     *
     * Abre o arquivo especificado e le os valores para preencher a matriz.
     *
     * @param matriz Ponteiro para a estrutura Matriz.
     * @param fileName Nome do arquivo a ser lido.
     * @return matriz em caso de sucesso, -1 em caso de erro.
     */

    int FicheiroParaLista(Matriz* matriz,const char* fileName) {
        FILE* fp = fopen(fileName, "r");
        if (!fp) {
            //printf("Erro ao abrir o arquivo.\n");
            return -1;
        }
        char linha[100];
        int linhaAt = 0;
        while (fgets(linha, sizeof(linha), fp) != NULL) {
            int colunaAt = 0;
            char* token = strtok(linha, ";");
            while (token != NULL) {
                int n = atoi(token);
                No* pos = ProcurarNumeroMatriz(matriz, linhaAt, colunaAt);
                pos->n = n;
                colunaAt++;
                token = strtok(NULL, ";");
            }
            linhaAt++;
        }
        fclose(fp);
        return matriz;
    }

#pragma endregion

#pragma region ProcurarNumeroMatriz

    /**
    * @brief Procura um no especifico em uma matriz dada sua linha e coluna.
    *
    * Esta função percorre uma matriz a partir do no inicial e encontra o no
    * na posicao especificada por `linha` e `coluna`.
    *
    * @param matriz Ponteiro para a matriz onde o no sera procurado.
    * @param linha A linha do no desejado.
    * @param coluna A coluna do no desejado.
    * @return Retorna um ponteiro para o no localizado na posiçao especificada.
    */

    No* ProcurarNumeroMatriz(Matriz* matriz, int linha, int coluna) {
        No* n = matriz->ini;

        for (int i = 0; i < linha; i++) {
            n = n->pbaixo;
        }
        for (int i = 0; i < coluna; i++) {
            n = n->pdireita;
        }

        return n;
    }

#pragma endregion

#pragma region imprimirMatriz

    /*
     * @brief Imprime a matriz na saida padrao.
     *
     * Imprime os valores da matriz na saída padrao.
     *
     */

    void imprimirLista(Matriz* matriz) {
        No* linhaAtual = matriz->ini;
        for (int i = 0; i < matriz->linha; i++) {
            No* colunaAtual = linhaAtual;
            for (int j = 0; j < matriz->coluna; j++) {
                printf("%d ", colunaAtual->n);
                colunaAtual = colunaAtual->pdireita;
            }
            printf("\n");
            linhaAtual = linhaAtual->pbaixo;
        }
    }

#pragma endregion

#pragma region AdicionarLinha
    /*
     * @brief Adiciona uma nova linha a matriz.
     *
     * Aloca memoria para uma nova linha e a adiciona a matriz.
     *
     * @param matriz Ponteiro para a estrutura Matriz.
     * @param pos Indice da linha a ser adicionada.
     * @param num Array contendo os valores da nova linha.
     * @return 1 em caso de sucesso, -1 em caso de falha.
     */

    int AdicionarLinha(Matriz* matriz, int pos, int num[]) {
        // Verifica se a posicao é valida
        if (pos < 0 || pos > matriz->linha) {
            //printf("Linha invalida.\n");
            return -1;
        }

        // Aloca a nova linha que vai ser adicionada a matriz
        No** novaLinha = (No**)malloc(matriz->coluna * sizeof(No));

        for (int i = 0; i < matriz->coluna; i++) {
            novaLinha[i] = (No*)malloc(sizeof(No));
            novaLinha[i]->n = num[i];
        }
        for (int i = 0; i < matriz->coluna - 1; i++) {
            novaLinha[i]->pdireita = novaLinha[i+1];
        }
        //int x = matriz->coluna;
        //novaLinha[x - 1]->pdireita = NULL;
    
        if (pos == 0) {
            
            for (int i = 0; i < matriz->coluna; i++) {
                No* proximo = ProcurarNumeroMatriz(matriz, pos, i);
                novaLinha[i]->pbaixo = proximo;
                if (i == 0) {
                    matriz->ini = novaLinha[i];
                }
            }
        }
        else
        {
            //Encontra a linha anterior a que vai adicionar
            No* antes = matriz->ini;
            for (int i = 0; i < pos - 1;i++) {
                antes = antes->pbaixo;
            }
            for (int i = 0; i < matriz->coluna;i++) {
                novaLinha[i]->pbaixo = antes->pbaixo;
                antes->pbaixo = novaLinha[i];
                antes = novaLinha[i]->pdireita;
            }
        }
        // Adiciona 1 linha ao numero total de linhas na matriz
        matriz->linha++;

        return 1;
    }

#pragma endregion

#pragma region AdicionarColuna

    /**
    * @brief Adiciona uma nova coluna a matriz.
    *
    * Aloca memória para uma nova coluna e a adiciona a matriz.
    *
    * @param matriz Ponteiro para a estrutura Matriz.
    * @param pos Indice da linha a ser adicionada.
    * @param num Array contendo os valores da nova coluna.
    * @return 1 em caso de sucesso e -1 em caso de falha.
    */

    int AdicionarColuna(Matriz* matriz, int pos, int num[]) {
        // Verifica se a posição é válida
        if (pos < 0 || pos > matriz->coluna) {
            //printf("Posição inválida.\n");
            return -1;
        }

        No* linhaAnterior = NULL;

        for (int i = 0; i < matriz->linha;i++) {
            No* novaColuna = (No*)calloc(1, sizeof(No));

            if (num != NULL) {
                novaColuna->n = num[i];
            }
            else
            {
                novaColuna->n = 0;
            }

            if (pos == 0) {
                No* proximo = ProcurarNumeroMatriz(matriz, i, pos);
                novaColuna->pdireita = proximo;
                if (linhaAnterior != NULL) {
                    linhaAnterior->pbaixo = novaColuna;
                }
                linhaAnterior = novaColuna;
                if (i == 0) {
                    matriz->ini = novaColuna;
                }
                
            }
            else
            {
                No* anterior = ProcurarNumeroMatriz(matriz, i, pos - 1);
                novaColuna->pdireita = anterior->pdireita;
                anterior->pdireita = novaColuna;
                if (linhaAnterior != NULL) {
                    linhaAnterior->pbaixo = novaColuna;
                }
                linhaAnterior = novaColuna;
            }
        }
        // Incrementa o número total de colunas na matriz
        matriz->coluna++;

        return 1;
    }

#pragma endregion

#pragma region eliminarLinha

    /*
    * @brief Remove uma linha da matriz.
    *
    * Libera a memoria alocada para a linha especificada e ajusta os ponteiros das linhas subsequentes.
    *
    * @param matriz Ponteiro para a estrutura Matriz.
    * @param pos Indice da linha a ser removida.
    * @return 1 em caso de sucesso, -1 em caso de falha.
    */

    int eliminarLinha(Matriz* matriz, int pos) {
        // Verifica se a posição e valida
        if (pos < 0 || pos >= matriz->linha) {
            //printf("Linha invalida.\n");
            return -1;
        }

        No* linhaAtual = matriz->ini;  // Ponteiro para a linha atual
        No* linhaAnterior = NULL;      // Ponteiro para a linha anterior

        // Encontra a linha a ser eliminada
        for (int i = 0; i < pos; i++) {
            linhaAnterior = linhaAtual;
            linhaAtual = linhaAtual->pbaixo;
        }

        // Atualiza os ponteiros na linha anterior
        if (linhaAnterior != NULL) {
            linhaAnterior->pbaixo = linhaAtual->pbaixo;
        }
        else {
            matriz->ini = linhaAtual->pbaixo;  // Se a linha a ser eliminada é a primeira, atualiza o início da matriz
        }

        // Libera a memória dos elementos da linha eliminada
        No* elementoAtual = linhaAtual;
        while (elementoAtual != NULL) {
            No* elementoProximo = elementoAtual->pdireita;  // Salva o próximo elemento antes de liberar a memória
            free(elementoAtual);  // Libera a memória do elemento atual
            elementoAtual = elementoProximo;  // Atualiza para o próximo elemento
        }

        // Decrementa o número total de linhas na matriz
        matriz->linha--;
        return 1;
    }

#pragma endregion

#pragma region eliminarColuna

    /**
    * @brief Remove uma coluna da matriz.
    *
    * Move os elementos das colunas subsequentes uma posicao para tras e redimensiona a matriz.
    *
    * @param matriz Ponteiro para a estrutura Matriz.
    * @param pos Indice da coluna a ser removida.
    * @return 1 em caso de sucesso, -1 em caso de falha.
    */

    int eliminarColuna(Matriz* matriz, int pos) {
        No* proximo = NULL;
        No* eliminar = matriz->ini;

        if (pos == 0) {
            for (int i = 0; i < matriz->coluna;i++) {
                if (proximo == NULL) {
                    proximo = eliminar->pbaixo;
                    free(eliminar);
                }
                else
                {
                    eliminar = proximo;
                    proximo = proximo->pbaixo;
                    free(eliminar);
                }
            }
            matriz->ini = ProcurarNumeroMatriz(matriz, 0, pos + 1);
        }
        else if (pos == 4) {
                for (int i = 0; i < matriz->coluna;i++) {
                    No* eliminar = ProcurarNumeroMatriz(matriz, i, pos);
                    No* antes = ProcurarNumeroMatriz(matriz, i, pos - 1);
                    free(eliminar);
                    antes->pdireita = NULL;
                }
            }
        else 
        {
            for (int i = 0; i < matriz->coluna;i++) {
                No* colAnterior = ProcurarNumeroMatriz(matriz, i, pos - 1);
                No* eliminar = ProcurarNumeroMatriz(matriz, i, pos);
                No* proximo = eliminar->pdireita;
                free(eliminar);
                colAnterior->pdireita = proximo;
            }
        }
        matriz->coluna--;
        return 1;
    }

#pragma endregion

#pragma region SomaMaxima

    int SomaMaximaAux(Matriz* matriz, int linha, int* colunasUsadas) {
        if (linha >= matriz->linha) {
            return 0;
        }

        int somaMaxima = 0;

        for (int i = 0; i < matriz->coluna; i++) {
            if (!colunasUsadas[i]) {
                colunasUsadas[i] = 1;
                No* escolhido = ProcurarNumeroMatriz(matriz, linha, i);
                int novaSoma = escolhido->n + SomaMaximaAux(matriz, linha + 1, colunasUsadas);
                if (novaSoma > somaMaxima) {
                    somaMaxima = novaSoma;
                }
                colunasUsadas[i] = 0;
            }
        }

        return somaMaxima;
    }

    // Função principal para calcular a soma máxima
    int SomaMaxima(Matriz* matriz) {
        int* colunasUsadas = (int*)calloc(matriz->coluna, sizeof(int));
        int somaMaxima = SomaMaximaAux(matriz, 0, colunasUsadas);
        free(colunasUsadas);
        return somaMaxima;
    }


#pragma endregion
