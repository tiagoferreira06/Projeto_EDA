# Projeto de Estruturas de Dados Avançadas  
## Instituto Politécnico do Cávado e do Ave (IPCA)

### 📍 Informações Gerais
**Curso:** Engenharia de Sistemas Informáticos
**Ano/Semestre:** 1º Ano, 2º Semestre  
**Unidade Curricular:** Estruturas de Dados Avançadas  
**Linguagem:** C  
**Autor:** Tiago Nunes Ferreira

---

## 🧾 Objetivo do Projeto

Este projeto tem como finalidade consolidar os conhecimentos adquiridos em Estruturas de Dados Avançadas, através do desenvolvimento de uma aplicação modular em C, organizada em duas fases complementares:

- **Fase 1:** Implementação de uma matriz dinâmica utilizando listas ligadas.
- **Fase 2:** Conversão da matriz para uma estrutura de grafo, permitindo a aplicação de algoritmos de busca e análise de caminhos.

---

## 🧠 Funcionalidades Implementadas

### 🔹 Fase 1 - Listas Ligadas
- Leitura e carregamento de matriz a partir de ficheiro de texto.
- Representação da matriz com recurso a listas ligadas duplamente encadeadas.
- Operações sobre a matriz:
  - Inserção e remoção de linhas e colunas.
  - Edição de elementos individuais.
  - Apresentação formatada da matriz.
- Cálculo da **soma máxima de inteiros**, selecionando um elemento por linha e por coluna (sem repetições).

### 🔹 Fase 2 - Grafos
- Conversão da matriz em grafo dirigido, com um vértice por elemento.
- Criação dinâmica de arestas com base em regras definidas pelo utilizador:
  - Conexões por linha, coluna, diagonal ou combinações.
- Aplicação de algoritmos de busca (DFS, BFS) para:
  - Percorrer o grafo.
  - Determinar todos os caminhos válidos.
  - Identificar o(s) caminho(s) com a maior soma de valores.
- Armazenamento e apresentação do(s) melhor(es) caminho(s).

---

## 🔍 Casos de Teste

O sistema foi testado com múltiplas matrizes de diferentes dimensões, variando:
- A estrutura dos dados inseridos.
- As regras de ligação entre os vértices.
- A existência de múltiplos caminhos com soma máxima.

---

## 📚 Documentação Técnica

Toda a base do projeto está documentada com **Doxygen**. Para gerar a documentação:

```bash
doxygen Doxyfile
